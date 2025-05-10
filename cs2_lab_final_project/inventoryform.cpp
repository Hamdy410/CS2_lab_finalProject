#include "inventoryform.h"
#include "ui_inventoryform.h"
#include <QString>
#include "item.h"
#include <QTableWidgetItem>
#include <QMessageBox>

InventoryForm::InventoryForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InventoryForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;
    ui->tableWidgetInventoryItems->setColumnCount(5);
    ui->tableWidgetInventoryItems->setHorizontalHeaderLabels(
        {"Name", "Quantity", "Category", "Price", "Supplier"});
    refreshItems();
    displayLowStock();
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
    if (quantity <= 0)
    {
        QMessageBox::warning(this, "Error", "Invalid quantity value");
        return;
    }

    Item newItem(name, category, quantity, price, supplier);

    if (inventorySystem->addItem(newItem))
    {
        refreshItems();
        displayLowStock();

        ui->lineEditAddName->clear();
        ui->lineEditAddCategory->clear();
        ui->lineEditAddPrice->clear();
        ui->lineEditAddQuantity->clear();
        ui->lineEditAddSupplier->clear();

        QMessageBox::information(this, "Done", "Item is added");
    }
}

void InventoryForm::on_pushButtonSearch_clicked()
{
    refreshItems();
}

void InventoryForm::on_lineEditSearch_textChanged(const QString &)
{
    refreshItems();
}

void InventoryForm::on_comboBoxSearchCriteria_currentIndexChanged(int)
{
    refreshItems();
}

void InventoryForm::refreshItems() {
    ui->tableWidgetInventoryItems->setRowCount(0); // Clear existing

    QVector<Item> items = inventorySystem->getInventory().getItems();

    for (int i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        int row = ui->tableWidgetInventoryItems->rowCount();
        ui->tableWidgetInventoryItems->insertRow(row);

        ui->tableWidgetInventoryItems->setItem(row, 0, new QTableWidgetItem(item.name()));
        ui->tableWidgetInventoryItems->setItem(row, 1, new QTableWidgetItem(QString::number(item.quantity())));
        ui->tableWidgetInventoryItems->setItem(row, 2, new QTableWidgetItem(item.category()));
        ui->tableWidgetInventoryItems->setItem(row, 3, new QTableWidgetItem(QString::number(item.price())));
        ui->tableWidgetInventoryItems->setItem(row, 4, new QTableWidgetItem(item.supplier()));
    }
}


void InventoryForm::displayLowStock()
{
    // these items' quantity is less than 15, to edit the number got to inventory class
    QVector<Item> lowStock = inventorySystem->getLowStockItems();
    ui->textEditLowStock->clear();
    for(const Item& item : lowStock)
    {
        ui->textEditLowStock->append(item.name());
    }
}

void InventoryForm::on_pushButton_Go_back_clicked()
{
    this->parentWidget()->show();
    this->close();
}
