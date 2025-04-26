#include "adduserform.h"
#include "ui_adduserform.h"
#include <QAction>

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

    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    togglePasswordAction = new QAction(QIcon(":/icons/eye_closed.png"), "", this);
    ui->lineEdit_Password->addAction(togglePasswordAction, QLineEdit::TrailingPosition);
    isPasswordVisible = false;

    connect(togglePasswordAction, &QAction::triggered, this, [=] () {
        isPasswordVisible = !isPasswordVisible;
        ui->lineEdit_Password->setEchoMode(isPasswordVisible ? QLineEdit::Normal : QLineEdit::Password);
        togglePasswordAction->setIcon(QIcon(isPasswordVisible ? ":/icons/eye_open.png" : ":icons/eye_closed.png"));
    });
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
    return ui->lineEdit_Password->text();
}
Role AddUserForm::getRole() const
{
    return static_cast<Role>(ui->comboBox_Role->currentData().toInt());
}
