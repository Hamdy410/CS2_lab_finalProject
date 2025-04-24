#include "signupform.h"
#include "ui_signupform.h"
#include <QDebug>
#include <QMessageBox>
#include "user.h"
#include "role.h"

SignUpForm::SignUpForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;
}

SignUpForm::~SignUpForm()
{
    delete ui;
}

void SignUpForm::on_pushButtonSignUp_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString role = ui->comboBoxRole->currentText();

    User newUser = User(username, password, stringToRole(role));
    if (!inventorySystem->addUser(newUser)) {
        QMessageBox::critical(this, "Sign Up Error", "Cannot create user!");
    }
}

