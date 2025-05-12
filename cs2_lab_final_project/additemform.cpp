#include "additemform.h"
#include "ui_additemform.h"
#include <QMessageBox>
#include <QFileDialog>

AddItemForm::AddItemForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddItemForm)
    , inventorySystem(inventorySystemParam)
{
    ui->setupUi(this);
}

AddItemForm::~AddItemForm()
{
    delete ui;
}

void AddItemForm::on_pushButtonAdd_clicked()
{
    QString name = ui->lineEditAddName->text();
    QString category = ui->lineEditAddCategory->text();
    double price = ui->lineEditAddPrice->text().toDouble();
    QString strPrice = ui->lineEditAddPrice->text();
    int quantity = ui->lineEditAddQuantity->text().toInt();
    QString strQuantity = ui->lineEditAddQuantity->text();
    QString supplier = ui->lineEditAddSupplier->text();

    if (name.isEmpty() || category.isEmpty() || supplier.isEmpty() ||
        strPrice.isEmpty() || strQuantity.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled");
        return;
    }
    if (price <= 0)
    {
        QMessageBox::warning(this, "Error", "Invalid price value");
        return;
    }
    if (quantity < 0)
    {
        QMessageBox::warning(this, "Error", "Invalid quantity value");
        return;
    }

    Item newItem(name, category, quantity, price, supplier);

    if (inventorySystem->addItem(newItem))
    {
        if (!selectedPhotoPath.isEmpty())
        {
            ItemPhotoManager::getInstance().saveItemPhoto(name, selectedPhotoPath);
            selectedPhotoPath.clear();
        }

        ui->lineEditAddName->clear();
        ui->lineEditAddCategory->clear();
        ui->lineEditAddPrice->clear();
        ui->lineEditAddQuantity->clear();
        ui->lineEditAddSupplier->clear();

        QMessageBox::information(this, "Done", "Item is added");
        emit accepted();
        close();
    }
}
void AddItemForm::on_pushButtonSelectPhoto_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Select Item Photo", "", "Image Files (*.png *.jpg *.jpeg *.bmp)");

    if (!filePath.isEmpty())
    {
        selectedPhotoPath = filePath;
        QMessageBox::information(this, "Success", "Photo selected successfully");
    }
}
