#include "editroleform.h"
#include "ui_editroleform.h"

#include <QAction>
#include <QMessageBox>
#include <QRegularExpression>

editRoleform::editRoleform(QWidget* parent)
    : QDialog(parent),
    ui(new Ui::editRoleform),
    togglePasswordAction(nullptr),
    isPasswordVisible(false)
{
    ui->setupUi(this);

    ui->comboBox_editRole->clear();
    ui->comboBox_editRole->addItem("Staff", static_cast<int>(Role::STAFF));
    ui->comboBox_editRole->addItem("Manager", static_cast<int>(Role::MANAGER));
    ui->comboBox_editRole->addItem("Admin", static_cast<int>(Role::ADMIN));

    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
    togglePasswordAction = new QAction(QIcon(":/icons/eye_closed.png"), "", this);
    ui->lineEdit_password->addAction(togglePasswordAction, QLineEdit::TrailingPosition);

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

void editRoleform::setUserInfo(const QString &username, const QString &password, Role currentRole) {
    ui->lineEdit_username->setText(username);
    ui->lineEdit_password->setText(password);

    int index = ui->comboBox_editRole->findData(static_cast<int>(currentRole));
    if (index != -1)
        ui->comboBox_editRole->setCurrentIndex(index);

    ui->usernameLabel->setText(username);
}

QString editRoleform::getUsername() const {
    return ui->lineEdit_username->text().trimmed();
}

QString editRoleform::getPassword() const {
    return ui->lineEdit_password->text();
}

Role editRoleform::getRole() const {
    return static_cast<Role>(ui->comboBox_editRole->currentData().toInt());
}

void editRoleform::on_pushButton_OK_clicked()
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

bool editRoleform::validatePassword(const QString& password)
{
    QString pattern = R"((?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,})";
    QRegularExpression regex(pattern);
    return regex.match(password).hasMatch();
}
