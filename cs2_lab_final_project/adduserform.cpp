#include "adduserform.h"
#include "ui_adduserform.h"
#include <QAction>
#include "QMessageBox"
#include <QRegularExpression>

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

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Username and password cannot be empty");
        return;
    }
    if (password.length() < 8)
    {
        QMessageBox::warning(this, "Error", "Password must be at least 8 characters long");
        return;
    }
    if (!validatePassword(password))
    {
        QMessageBox::warning(this, "Error", "Password must include at least one uppercase, one lowercase character and one number");
        return;
    }

    accept();
}

bool AddUserForm::validatePassword(const QString& password)
{
    QString pattern = R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,})";
    QRegularExpression regex(pattern);
    return regex.match(password).hasMatch();
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
