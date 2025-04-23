#include "signupform.h"
#include "ui_signupform.h"
#include <QDebug>

SignUpForm::SignUpForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpForm)
{
    ui->setupUi(this);
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
    qDebug() << username << " " << password << " " << password2 << endl;
}

