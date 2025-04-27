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
    QVector<Item> existingItems = inventorySystem->searchItems(name, "");

    for (const Item& item : existingItems)
    {
        if (item.name() == name && item.category() == category && item.supplier() == supplier) {
            QMessageBox::warning(this, "Error", "Item already exists with same name, category and supplier");
            return;
        }
    }
    if (inventorySystem->addItem(newItem))
    {
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

void InventoryForm::refreshItems()
{
    // Clear existing items
    ui->tableWidgetInventoryItems->setRowCount(0);
    QString searchValue = ui->lineEditSearch->text().trimmed();
    QString searchCriteria = ui->comboBoxCriteria->currentText();

    // to get items from inventory system based on search criteria
    QVector<Item> items;
    if (!searchValue.isEmpty())
    {
        if (searchCriteria == "Supplier")
        {
            items = inventorySystem->searchItems("", searchValue);
        }
        else if (searchCriteria == "Category")
        {
            items = inventorySystem->getInventory().getItems();
            QVector<Item> filteredItems;
            for (const Item& item : items)
            {
                if (item.category().contains(searchValue, Qt::CaseInsensitive))
                {
                    filteredItems.append(item);
                }
            }
            items = filteredItems;
        }
        else if (searchCriteria == "Name")
        {
            items = inventorySystem->getInventory().getItems();
            QVector<Item> filteredItems;
            for (const Item& item : items)
            {
                if (item.name().contains(searchValue, Qt::CaseInsensitive))
                {
                    filteredItems.append(item);
                }
            }
            items = filteredItems;
        }
    }
    else
    {
        items = inventorySystem->getInventory().getItems();
    }
    // to add items to table
    for (int i = 0; i < items.size(); ++i)
    {
        const Item& item = items[i];
        ui->tableWidgetInventoryItems->insertRow(i);
        ui->tableWidgetInventoryItems->setItem(i, 0, new QTableWidgetItem(item.name()));
        ui->tableWidgetInventoryItems->setItem(i, 1, new QTableWidgetItem(QString::number(item.quantity())));
        ui->tableWidgetInventoryItems->setItem(i, 2, new QTableWidgetItem(item.category()));
        ui->tableWidgetInventoryItems->setItem(i, 3, new QTableWidgetItem(QString::number(item.price())));
        ui->tableWidgetInventoryItems->setItem(i, 4, new QTableWidgetItem(item.supplier()));
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
