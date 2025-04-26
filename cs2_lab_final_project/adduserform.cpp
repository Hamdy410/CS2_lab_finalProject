#include "adduserform.h"
#include "ui_adduserform.h"

AddUserForm::AddUserForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUserForm)
{
    ui->setupUi(this);
    connect(ui->pushButton_OK, &QPushButton::clicked, this, &AddUserForm::on_pushButton_OK_clicked);
    ui->comboBox_Role->clear();
    ui->comboBox_Role->addItem("Staff", static_cast<int>(Role::STAFF));
    ui->comboBox_Role->addItem("Manager", static_cast<int>(Role::MANAGER));
    ui->comboBox_Role->addItem("Admin", static_cast<int>(Role::ADMIN));
}

AddUserForm::~AddUserForm()
{
    delete ui;
}

void AddUserForm::on_pushButton_OK_clicked()
{
    if (getUsername().isEmpty() || getPassword().isEmpty())
    {
        qDebug() << "Username or password cannot be empty";
        return;
    }
    accept();
}
QString AddUserForm::getUsername() const
{
    return ui->lineEdit_Username->text().trimmed();
}
QString AddUserForm::getPassword() const
{
    return ui->lineEdit_Password->text().trimmed();
}
Role AddUserForm::getRole() const
{
    return static_cast<Role>(ui->comboBox_Role->currentData().toInt());
}
