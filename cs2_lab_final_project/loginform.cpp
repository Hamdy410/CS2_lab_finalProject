#include "loginform.h"
#include "ui_loginform.h"
#include "signupform.h"
#include <QString>
#include <QDebug>
#include "dashboard.h"

#include "systemui.h"

LoginForm::LoginForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;
}

LoginForm::~LoginForm()
{
    qDebug() << "login form destroyed";
    delete inventorySystem;
    delete ui;
}

void LoginForm::on_pushButton_Login_clicked()
{   
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    // Process Input

    qDebug() << "Username: " << username;
    qDebug() << "Password: " << password;
    if (inventorySystem->authenticateUser(username, password)) {
        qDebug() << "Found the user";
        SystemUI* system = new SystemUI(this, inventorySystem);
        system->show();

        this->hide();
    } else {
        qDebug() << "Cannot find the user.";
    }
}


void LoginForm::on_pushButton_Sign_Up_clicked()
{
    SignUpForm *signUpForm = new SignUpForm(inventorySystem);

    signUpForm->show();

    this->close();
}

