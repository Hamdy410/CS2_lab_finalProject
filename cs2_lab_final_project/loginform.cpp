#include "loginform.h"
#include "ui_loginform.h"
#include "signupform.h"
#include <QString>
#include <QDebug>
#include "dashboard.h"

LoginForm::LoginForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    // Process Input
    if (inventorySystem->authenticateUser(username, password)) {
        Dashboard *dashboard = new Dashboard();

        dashboard->show();

        this->close();
    }
}


void LoginForm::on_pushButton_Sign_Up_clicked()
{
    SignUpForm *signUpForm = new SignUpForm(inventorySystem);

    signUpForm->show();

    this->close();
}

