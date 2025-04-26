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
    //populateTable(inventorySystem->searchItems("", ""));
    refreshItems();
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
    inventorySystem->addItem(newItem);
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
// void InventoryForm::populateTable(const QVector<Item>& items)
// {
//     ui->tableWidgetInventoryItems->clearContents();
//     ui->tableWidgetInventoryItems->setRowCount(0); // Clear existing rows
//     //const QVector<Item>& items = inventorySystem->getLowStockItems();
//     for (const Item& item : items)
//     {
//         int row = ui->tableWidgetInventoryItems->rowCount();
//         ui->tableWidgetInventoryItems->insertRow(row);

//         ui->tableWidgetInventoryItems->setItem(row, 0, new QTableWidgetItem(item.name()));
//         ui->tableWidgetInventoryItems->setItem(row, 1, new QTableWidgetItem(QString::number(item.quantity())));
//         ui->tableWidgetInventoryItems->setItem(row, 2, new QTableWidgetItem(item.category()));
//         ui->tableWidgetInventoryItems->setItem(row, 3, new QTableWidgetItem(QString::number(item.price(), 'f', 2)));
//         ui->tableWidgetInventoryItems->setItem(row, 4, new QTableWidgetItem(item.supplier()));
//     }
// }

// void InventoryForm::on_pushButtonSearch_clicked()
// {
//     QString searchText = ui->lineEditSearch->text().trimmed();
//     QString criteria = ui->comboBoxCriteria->currentText();

//     if (searchText.isEmpty()) {
//         // If search field is empty, show all items
//         populateTable(inventorySystem->searchItems("", ""));
//         return;
//     }

//     QVector<Item> results;

//     if (criteria == "Name") {
//         results = inventorySystem->searchItems(searchText, "");
//     }
//     else if (criteria == "Category") {
//         results = inventorySystem->searchItems("", searchText);
//     }
//     else if (criteria == "Supplier") {
//         // If your InventorySystem doesn't support supplier search directly,
//         // you might need to filter the results here
//         QVector<Item> allItems = inventorySystem->searchItems("", "");
//         for (const Item& item : allItems) {
//             if (item.supplier().contains(searchText, Qt::CaseInsensitive)) {
//                 results.append(item);
//             }
//         }
//     }

//     populateTable(results);

//     // Update low stock items display
//     QVector<Item> lowStockItems = inventorySystem->getLowStockItems();
//     QString lowStockText;
//     for (const Item& item : lowStockItems) {
//         lowStockText += item.name() + " (" + QString::number(item.quantity()) + ")\n";
//     }
//     ui->textEditLowStock->setPlainText(lowStockText);
// }
// void InventoryForm::on_pushButtonAdd_clicked()
// {
//     QString name = ui->lineEditAddName->text().trimmed();
//     QString category = ui->lineEditAddCategory->text().trimmed();
//     double price = ui->lineEditAddPrice->text().toDouble();
//     int quantity = ui->lineEditAddQuantity->text().toInt();
//     QString supplier = ui->lineEditAddSupplier->text().trimmed();

//     // Validate inputs
//     if (name.isEmpty() || category.isEmpty() || supplier.isEmpty()) {
//         QMessageBox::warning(this, "Error", "Please fill in all required fields");
//         return;
//     }

//     Item newItem(name, category, quantity, price, supplier);
//     if (inventorySystem->addItem(newItem)) {
//         // Clear input fields
//         ui->lineEditAddName->clear();
//         ui->lineEditAddCategory->clear();
//         ui->lineEditAddPrice->clear();
//         ui->lineEditAddQuantity->clear();
//         ui->lineEditAddSupplier->clear();

//         // Refresh the display
//         refreshItems();
//     }
// }

void InventoryForm::refreshItems()
{
    // Clear existing items
    ui->tableWidgetInventoryItems->setRowCount(0);

    // Get search criteria and value
    QString searchValue = ui->lineEditSearch->text().trimmed();
    QString searchCriteria = ui->comboBoxCriteria->currentText();

    // Get items from inventory system based on search criteria
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
            // Filter by category
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
    }
    else
    {
        items = inventorySystem->getInventory().getItems();
    }

    // Add items to table
    for (int i = 0; i < items.size(); ++i) {
        const Item& item = items[i];
        ui->tableWidgetInventoryItems->insertRow(i);

        ui->tableWidgetInventoryItems->setItem(i, 0, new QTableWidgetItem(item.name()));
        ui->tableWidgetInventoryItems->setItem(i, 1, new QTableWidgetItem(item.category()));
        ui->tableWidgetInventoryItems->setItem(i, 2, new QTableWidgetItem(QString::number(item.quantity())));
        ui->tableWidgetInventoryItems->setItem(i, 3, new QTableWidgetItem(QString::number(item.price())));
        ui->tableWidgetInventoryItems->setItem(i, 4, new QTableWidgetItem(item.supplier()));
    }

    // Resize columns to fit content
    ui->tableWidgetInventoryItems->resizeColumnsToContents();
}
