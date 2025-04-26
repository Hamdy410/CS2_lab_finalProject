#include "adduserform.h"
#include "ui_adduserform.h"

AddUserForm::AddUserForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUserForm)
{
    ui->setupUi(this);
}

AddUserForm::~AddUserForm()
{
    delete ui;
}
