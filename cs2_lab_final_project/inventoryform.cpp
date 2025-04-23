#include "inventoryform.h"
#include "ui_inventoryform.h"
#include <QString>
#include "item.h"

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

void InventoryForm::on_pushButtonAdd_clicked()
{
    QString name = ui->lineEditAddName->text();
    QString category = ui->lineEditAddCategory->text();
    double price = ui->lineEditAddPrice->text().toDouble();
    int quantity = ui->lineEditAddQuantity->text().toInt();
    QString supplier = ui->lineEditAddSupplier->text();

    Item newItem(name, category, quantity, price, supplier);
    // Add newItem to item vector
}

