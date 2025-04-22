#include "ui_edituserdialog.h"
#include "ui_ui_edituserdialog.h"

Ui_EditUserDialog::Ui_EditUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ui_EditUserDialog)
{
    ui->setupUi(this);
}

Ui_EditUserDialog::~Ui_EditUserDialog()
{
    delete ui;
}
