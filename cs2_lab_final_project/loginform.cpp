#include "loginform.h"
#include "ui_loginform.h"
#include "signupform.h"
#include <QString>
#include <QDebug>

LoginForm::LoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    qDebug() << username << endl;
    qDebug() << password << endl;
}


void LoginForm::on_pushButton_Sign_Up_clicked()
{
    SignUpForm *signUpForm = new SignUpForm();

    signUpForm->show();

    this->close();
}

