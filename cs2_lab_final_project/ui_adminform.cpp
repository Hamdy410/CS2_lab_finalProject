#include "ui_adminform.h"
#include "ui_ui_adminform.h"

#include <QStyle>
#include <QHBoxLayout>
#include <QTableWidgetItem>

Ui_AdminForm::Ui_AdminForm(InventorySystem* system, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ui_AdminForm),
    inventorySystem(system)
{
    ui->setupUi(this);

    if (!validateAdminAccess()) {
        return;
    }

    setWindowTitle("User Management");

    // Setting up ComboBox for filters
    ui->roleFilterComboBox->addItem("All Users", -1);
    ui->roleFilterComboBox->addItem("Admin Users", static_cast<int>(Role::ADMIN));
    ui->roleFilterComboBox->addItem("Manager users", static_cast<int>(Role::MANAGER));
    ui->roleFilterComboBox->addItem("Staff Users", static_cast<int>(Role::STAFF));

    // Initialize the table
    setupTable();

    // connect signals from inventorySystem
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
                              "You must log in to access this area.");
        close();
        return false;
    }

    if (!inventorySystem->currentUserCanManageUsers()) {
        QMessageBox::critical(this, "Acced Denied",
                              "You don't have administrator privileges to access this area.");
        close();
        return false;
    }

    return true;
}

void Ui_AdminForm::setupTable() {
    ui->userTableWidget->setColumnCount(4);

    QStringList headers;
    headers << "Username" << "Role" << "Edit" << "Delete";
    ui->userTableWidget->setHorizontalHeaderLabels(headers);

    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->userTableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->userTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixes);
    ui->userTableWidget->setColumnWidth(2, 80);
    ui->userTableWidget->setColumnWidth(3, 80);

    ui->userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->userTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->userTableWidget->setAlternatingRowColors(true);
}

void Ui_AdminForm::populateTable(Role roleFilter) {
    ui->userTableWidget->setRowCount(0);

    QVector<User> allUsers = inventorySystem->getUsers();

    for (const User& user : allUsers) {
        if (roleFilter != static_cast<Role>(-1) && user.getRole() != roleFilter)
            continue;

        int row = ui->userTableWidget->rowCount();
        ui->userTableWidget->insertRow(row);

        QTableWidgetItem* usernameItem = new QTableWidgetItem(user.getUsername());
        ui->userTableWidget->setItem(row, 0, usernameItem);

        QTableWidgetItem* roleItem = new QTableWidgetItem(roleToString(user.getRole()));
        ui->userTableWidget->setItem(row, 1, roleItem);

        createActionButtons(row, user.getUsername());
    }
}

void Ui_AdminForm::createActionButtons(int row, const QString &username) {
    QWidget* editButtonWidget = new QWidget();
    QPushButton* editButton = new QPushButton();
    editButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogContentsView));
    editButton->setToolTip("Edit User");
    editButton->setProperty("username", username);

    QHBoxLayout* editLayout = new QHBoxLayout(editButtonWidget);
    editLayout->addWidget(editButton);
    editLayout->setAlignment(Qt::AlignCenter);
    editLayout->setContentsMargins(0, 0, 0, 0);

    QWidget* deleteButtonWidget = new QWidget();
    QPushButton* deleteButton = new QPushButton();
    deleteButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    deleteButton->setToolTip("Delete User");
    deleteButton->setProperty("username", username);

    QHBoxLayout * deleteLayout = new QHBoxLayout(deleteButtonWidget);
    deleteLayout->addWidget(deleteButton);
    deleteLayout->setAlignment(Qt::AlignCenter);
    deleteLayout->setContentsMargins(0, 0, 0, 0);

    ui->userTableWidget->setCellWidget(row, 2, editButtonWidget);
    ui->userTableWidget->setCellWidget(row, 3, deleteButtonWidget);

    connect(editButton, &QPushButton::clicked, this,
            &Ui_AdminForm::onEditButtonClicked);
    connect(deleteButton, &QPushButton::clicked, this,
            &Ui_AdminForm::onDeleteButtonClicked);

    if (username == inventorySystem->getCurrentUsername()) {
        editButton->setEnabled(false);
        deleteButton->setEnabled(false);

        editButton->setToolTip("Cannot edit your own account");
        editButton->setToolTip("Cannot delete your own account");
    }
}

void Ui_AdminForm::refreshUserTable()
{
    int currentFilterIndex = ui->roleFilterComboBox->currentIndex();
    Role roleFilter = static_cast<Role>(ui->roleFilterComboBox->itemData(roleFilterIndex).toInt());
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
}

void Ui_AdminForm::onEditButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton>(sender());
    if (button) {
        QString username = button->property("username").toString();
        Ui_EditUserDialog dialog(inventorySystem, username, this);
        dialog.exec();
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
        confirmBox.setIcon(QMessageBox::Warning);
        confirmBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        confirmBox.setDefaultButton(QMessageBox::Cancel);

        if (confirmBox.exec() == QMessageBox::Yes) {
            if (inventorySystem->removeUser(username)) {
                QMessageBox::information(this, "Success", "User '" + username + "' has been deleted");
            } else {
                QMessageBox::critical(this, "Error", "Failed to delete user '" + username + "'");
            }
        }
    }
}

