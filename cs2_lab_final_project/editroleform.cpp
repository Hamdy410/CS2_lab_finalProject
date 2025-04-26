#include "editroleform.h"
#include "ui_editroleform.h"

editRoleform::editRoleform(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editRoleform)
{
    ui->setupUi(this);
}

editRoleform::~editRoleform()
{
    delete ui;
}

void editRoleform::on_comboBox_editRole_currentIndexChanged(int index)
{
    QString updatedRole = ui->comboBox_editRole->currentText();
}

