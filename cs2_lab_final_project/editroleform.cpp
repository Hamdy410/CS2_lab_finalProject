#include "editroleform.h"
#include "ui_editroleform.h"

#include <QDebug>
#include <QRegularExpression>
#include <QAction>
#include <QMessageBox>

editRoleform::editRoleform(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editRoleform)
{
    ui->setupUi(this);
    ui->comboBox_editRole->addItem("Staff", static_cast<int>(Role::STAFF));
    ui->comboBox_editRole->addItem("Manager", static_cast<int>(Role::MANAGER));
    ui->comboBox_editRole->addItem("Admin", static_cast<int>(Role::ADMIN));

    // Password field input visibility function
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    togglePasswordAction = new QAction(QIcon(":icons/eye_closed.png"), "", this);
    ui->lineEdit_password->addAction(togglePasswordAction, QLineEdit::TrailingPosition);
    isPasswordVisible = false;

    connect(togglePasswordAction, &QAction::triggered, this, [=] () {
        isPasswordVisible = !isPasswordVisible;
        ui->lineEdit_password->setEchoMode(isPasswordVisible ? QLineEdit::Normal : QLineEdit::Password);
        togglePasswordAction->setIcon(QIcon(isPasswordVisible ? ":/icons/eye_open.png" : ":/icons/eye_closed.png"));
    });
}

editRoleform::~editRoleform()
{
    delete ui;
}

void editRoleform::setUserInfo(const QString& username, const QString& password,
                               Role currentRole)
{
    m_username = username;
    ui->usernameLabel->setText(username);
    ui->lineEdit_username->setText(username);
    ui->lineEdit_password->setText(password);

    int index = ui->comboBox_editRole->findData(static_cast<int>(currentRole));
    if (index != -1)
        ui->comboBox_editRole->setCurrentIndex(index);
}

Role editRoleform::getSelectedRole() const
{
    return static_cast<Role>(ui->comboBox_editRole->currentData().toInt());
}

QString editRoleform::getNewUsername() const
{
    return ui->lineEdit_username->text().trimmed();
}

QString editRoleform::getNewPassword() const
{
    return ui->lineEdit_password->text();
}

void editRoleform::on_comboBox_editRole_currentIndexChanged(int index)
{
    QString updatedRole = ui->comboBox_editRole->currentText();
}

void editRoleform::on_pushButton_OK_clicked()
{
    QString username = getNewUsername();
    QString password = getNewPassword();

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
    if (!validatePassword(password))
    {
        QMessageBox::warning(this, "Error", "Password must include at least one uppercase and one lowercase character");
        return;
    }
    accept();
}

bool editRoleform::validatePassword(const QString& password)
{
    QString pattern = R"((?=.*[a-z])(?=.*[A-Z]).{9,})";
    QRegularExpression regex(pattern);
    return regex.match(password).hasMatch();
}
