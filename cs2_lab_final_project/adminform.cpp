#include "adminform.h"
#include "ui_adminform.h"
#include "user.h"
#include "inventorysystem.h"
#include "role.h"

#include <QTableWidgetItem>
#include <QWidget>
#include <QHBoxLayout>
#include <QApplication>
#include <QCloseEvent>

AdminForm::AdminForm(QWidget *parent, InventorySystem* inventorySystem)
    : QDialog(parent)
    , ui(new Ui::AdminForm)
    , inventorySystem(inventorySystem)
{
    ui->setupUi(this);
    setWindowTitle("Admin Form - Manage Users");

    ui->userDisplayTable->setColumnCount(3);
    ui->userDisplayTable->setHorizontalHeaderLabels({"Username", "Role", "Actions"});

    ui->userDisplayTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->filtersComboBox->addItem("All Roles");
    ui->filtersComboBox->addItem("Admin");
    ui->filtersComboBox->addItem("Manager");
    ui->filtersComboBox->addItem("Staff");

    populateTable();
}

AdminForm::~AdminForm()
{
    delete ui;
}


void AdminForm::on_filtersComboBox_currentIndexChanged(int index)
{
    qDebug() << "Index changed to: " << index;
}


void AdminForm::on_goBackPushButton_clicked()
{
    qDebug() << "Go Back Button called";
}


void AdminForm::on_addnewUserPushButton_clicked()
{
    qDebug() << "Add New User Button Called";
}

void AdminForm::populateTable() {
    ui->userDisplayTable->clearContents();
    ui->userDisplayTable->setRowCount(0);

    QVector<User> users = inventorySystem->getUsers();
    for (int row = 0; row < users.size(); row++) {
        // Insert a new row
        ui->userDisplayTable->insertRow(row);

        // Insert the data into each column
        ui->userDisplayTable->setItem(row, 0, new QTableWidgetItem(users[row].getUsername()));
        ui->userDisplayTable->setItem(row, 1, new QTableWidgetItem(roleToString(users[row].getRole())));

        // Create the buttons for Edit and Delete
        QPushButton* editButton = new QPushButton("Edit");
        QPushButton* deleteButton = new QPushButton("Delete");

        editButton->setFixedSize(60, 25);
        deleteButton->setFixedSize(60, 25);

        // Connect the buttons to the actions
        connect(editButton, &QPushButton::clicked, this, [this, row] () {
            onEditUser(row);
        });
        connect(deleteButton, &QPushButton::clicked, this, [this, row] () {
            onDeleteUser(row);
        });

        QWidget *buttonWidget = new QWidget;
        QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);
        buttonLayout->addWidget(editButton);
        buttonLayout->addWidget(deleteButton);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        buttonLayout->setSpacing(5);
        ui->userDisplayTable->setCellWidget(row, 2, buttonWidget);
    }
}

void AdminForm::onEditUser(int row) {
    QString username = ui->userDisplayTable->item(row, 0)->text();
    QString role = ui->userDisplayTable->item(row, 1)->text();

    qDebug() << "User Edit Button called";
}

void AdminForm::onDeleteUser(int row) {
    QString username = ui->userDisplayTable->item(row, 0)->text();
    qDebug() << "Deleted username: " << username;
    qDebug() << "Delete Button called";
    qDebug() << "refresh Now";
}

void AdminForm::refreshTable() {
    populateTable();
}

void AdminForm::closeEvent(QCloseEvent *event) {
    this->parentWidget()->show();
    this->close();

    event->accept();
}
