#include "signupform.h"
#include "ui_signupform.h"
#include <QDebug>
#include <QMessageBox>

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
    QString password2 = ui->lineEditReenterPassword->text();

    if (password != password2) {
        QMessageBox::critical(this, "Sign Up Error", "Passwords do not match. Please re-enter them.");
        return;
    }
}

