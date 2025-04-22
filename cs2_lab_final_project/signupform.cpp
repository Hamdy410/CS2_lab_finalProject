#include "signupform.h"
#include "ui_signupform.h"

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
