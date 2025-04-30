#include "adduserform.h"
#include "ui_adduserform.h"
#include <QAction>
#include "QMessageBox"

AddUserForm::AddUserForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUserForm)
{
    ui->setupUi(this);
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
    QString username = getUsername();
    QString password = getPassword();
    Role role = getRole();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Username and password cannot be empty");
        return;
    }
    if (password.length() < 9)
    {
        QMessageBox::warning(this, "Error", "Password must be at least 9 characters long");
        return;
    }
    if (!validatePassword(password, role))
    {
        QMessageBox::warning(this, "Error", "Password must start with user's role");
        return;
    }

    accept();
}

bool AddUserForm::validatePassword(const QString& password, Role role)
{
    QString prefix;
    switch (role)
    {
    case Role::ADMIN:
        prefix = "admin";
        break;
    case Role::MANAGER:
        prefix = "manager";
        break;
    case Role::STAFF:
        prefix = "staff";
        break;
    }
    return password.startsWith(prefix, Qt::CaseInsensitive);
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
