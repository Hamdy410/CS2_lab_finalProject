#include "ui_adminform.h"
#include "ui_ui_adminform.h"
#include "ui_adduserdialog.h"
#include "ui_edituserdialog.h"
#include <QStyle>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStandardItem>
#include <QTableWidgetItem>
#include <QHeaderView>

Ui_AdminForm::Ui_AdminForm(InventorySystem* system, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ui_AdminForm),
    inventorySystem(system)
{
    ui->setupUi(this);

    // Check admin permissions before proceeding
    if (!validateAdminAccess()) {
        return; // Dialog will be closed in validateAdminAccess if validation fails
    }

    setWindowTitle("User Management");

    // Setting up ComboBox for role filters
    ui->roleFilterComboBox->addItem("All Users", -1);
    ui->roleFilterComboBox->addItem("Admin Users", static_cast<int>(Role::ADMIN));
    ui->roleFilterComboBox->addItem("Manager Users", static_cast<int>(Role::MANAGER));
    ui->roleFilterComboBox->addItem("Staff Users", static_cast<int>(Role::STAFF));

    // Initialize the table
    setupTable();

    // Connect signal from inventory system for user changes
    connect(inventorySystem, &InventorySystem::userChanged,
            this, &Ui_AdminForm::refreshUserTable);

    // Set add user button icon
    ui->addUserButton->setIcon(style()->standardIcon(QStyle::SP_DialogYesButton));

    // Initial population of the table
    populateTable();
}

Ui_AdminForm::~Ui_AdminForm()
{
    delete ui;
}

bool Ui_AdminForm::validateAdminAccess()
{
    if (!inventorySystem->isAuthenticated()) {
        QMessageBox::critical(this, "Access Denied",
                              "You must be logged in to access this area.");
        close();
        return false;
    }

    if (!inventorySystem->currentUserCanManageUsers()) {
        QMessageBox::critical(this, "Access Denied",
                              "You don't have administrator privileges to access this area.");
        close();
        return false;
    }

    return true;
}

void Ui_AdminForm::setupTable()
{
    // Set up the table columns
    ui->userTableWidget->setColumnCount(4); // Username, Role, Edit, Delete

    // Set the headers
    QStringList headers;
    headers << "Username" << "Role" << "Edit" << "Delete";
    ui->userTableWidget->setHorizontalHeaderLabels(headers);

    // Set column sizes
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // Username
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Role
    ui->userTableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed); // Edit
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed); // Delete
    ui->userTableWidget->setColumnWidth(2, 80); // Edit button width
    ui->userTableWidget->setColumnWidth(3, 80); // Delete button width

    // Other table settings
    ui->userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->userTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userTableWidget->setAlternatingRowColors(true);
}

void Ui_AdminForm::populateTable(Role roleFilter)
{
    // Clear the table
    ui->userTableWidget->setRowCount(0);

    // Get all users
    QVector<User> allUsers = inventorySystem->getUsers();

    // Filter and add users to the table
    for (const User& user : allUsers) {
        // Apply role filter if specified
        if (roleFilter != static_cast<Role>(-1) && user.getRole() != roleFilter) {
            continue;
        }

        int row = ui->userTableWidget->rowCount();
        ui->userTableWidget->insertRow(row);

        // Username
        QTableWidgetItem* usernameItem = new QTableWidgetItem(user.getUsername());
        ui->userTableWidget->setItem(row, 0, usernameItem);

        // Role
        QTableWidgetItem* roleItem = new QTableWidgetItem(roleToString(user.getRole()));
        ui->userTableWidget->setItem(row, 1, roleItem);

        // Create edit and delete buttons
        createActionButtons(row, user.getUsername());
    }
}

void Ui_AdminForm::createActionButtons(int row, const QString& username)
{
    // Container widget for edit button
    QWidget* editButtonWidget = new QWidget();
    QPushButton* editButton = new QPushButton();
    editButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    editButton->setToolTip("Edit User");
    editButton->setProperty("username", username);

    QHBoxLayout* editLayout = new QHBoxLayout(editButtonWidget);
    editLayout->addWidget(editButton);
    editLayout->setAlignment(Qt::AlignCenter);
    editLayout->setContentsMargins(0, 0, 0, 0);

    // Container widget for delete button
    QWidget* deleteButtonWidget = new QWidget();
    QPushButton* deleteButton = new QPushButton();
    deleteButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    deleteButton->setToolTip("Delete User");
    deleteButton->setProperty("username", username);

    QHBoxLayout* deleteLayout = new QHBoxLayout(deleteButtonWidget);
    deleteLayout->addWidget(deleteButton);
    deleteLayout->setAlignment(Qt::AlignCenter);
    deleteLayout->setContentsMargins(0, 0, 0, 0);

    // Set the buttons in the table
    ui->userTableWidget->setCellWidget(row, 2, editButtonWidget);
    ui->userTableWidget->setCellWidget(row, 3, deleteButtonWidget);

    // Connect button signals to slots
    connect(editButton, &QPushButton::clicked, this, &Ui_AdminForm::onEditButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this, &Ui_AdminForm::onDeleteButtonClicked);

    // Disable buttons if this is the current user
    if (username == inventorySystem->getCurrentUsername()) {
        editButton->setEnabled(false);
        deleteButton->setEnabled(false);

        editButton->setToolTip("Cannot edit your own account");
        deleteButton->setToolTip("Cannot delete your own account");
    }
}

void Ui_AdminForm::refreshUserTable()
{
    int currentFilterIndex = ui->roleFilterComboBox->currentIndex();
    Role roleFilter = static_cast<Role>(ui->roleFilterComboBox->itemData(currentFilterIndex).toInt());
    populateTable(roleFilter);
}

void Ui_AdminForm::on_roleFilterComboBox_currentIndexChanged(int index)
{
    Role roleFilter = static_cast<Role>(ui->roleFilterComboBox->itemData(index).toInt());
    populateTable(roleFilter);
}

void Ui_AdminForm::on_addUserButton_clicked()
{
    Ui_AddUserDialog dialog(inventorySystem, this);
    dialog.exec();
    // Table will refresh via the userChanged signal if a user was added
}

void Ui_AdminForm::onEditButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString username = button->property("username").toString();
        Ui_EditUserDialog dialog(inventorySystem, username, this);
        dialog.exec();
        // Table will refresh via the userChanged signal if user was edited
    }
}

void Ui_AdminForm::onDeleteButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString username = button->property("username").toString();

        QMessageBox confirmBox(this);
        confirmBox.setWindowTitle("Confirm Delete");
        confirmBox.setText("Are you sure you want to delete user '" + username + "'?");
        confirmBox.setInformativeText("This action cannot be undone.");
        confirmBox.setIcon(QMessageBox::Warning);
        confirmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        confirmBox.setDefaultButton(QMessageBox::Cancel);

        if (confirmBox.exec() == QMessageBox::Yes) {
            if (inventorySystem->removeUser(username)) {
                QMessageBox::information(this, "Success",
                                         "User '" + username + "' has been deleted.");
            } else {
                QMessageBox::critical(this, "Error",
                                      "Failed to delete user '" + username + "'.");
            }
        }
    }
}
