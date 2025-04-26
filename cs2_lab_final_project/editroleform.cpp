#include "editroleform.h"
#include "ui_editroleform.h"
#include <QDebug>

editRoleform::editRoleform(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editRoleform)
{
    ui->setupUi(this);
    ui->comboBox_editRole->addItem("Staff", static_cast<int>(Role::STAFF));
    ui->comboBox_editRole->addItem("Manager", static_cast<int>(Role::MANAGER));
    ui->comboBox_editRole->addItem("Admin", static_cast<int>(Role::ADMIN));
    connect(ui->pushButton_OK, &QPushButton::clicked, this, &editRoleform::on_pushButton_OK_clicked);

}

editRoleform::~editRoleform()
{
    delete ui;
}

void editRoleform::setUserInfo(const QString& username, Role currentRole)
{
    m_username = username;
    ui->usernameLabel->setText(username);

    // Set current role in combo box
    int index = ui->comboBox_editRole->findData(static_cast<int>(currentRole));
    if (index != -1) {
        ui->comboBox_editRole->setCurrentIndex(index);
    }
}
Role editRoleform::getSelectedRole() const
{
    return static_cast<Role>(ui->comboBox_editRole->currentData().toInt());
}

void editRoleform::on_comboBox_editRole_currentIndexChanged(int index)
{
    QString updatedRole = ui->comboBox_editRole->currentText();
}
void editRoleform::on_pushButton_OK_clicked()
{
    accept();
}

