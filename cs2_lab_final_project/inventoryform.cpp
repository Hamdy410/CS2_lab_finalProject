#include "inventoryform.h"
#include "ui_inventoryform.h"

InventoryForm::InventoryForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InventoryForm)
{
    ui->setupUi(this);
}

InventoryForm::~InventoryForm()
{
    delete ui;
}
