#include "inventoryform.h"
#include "ui_inventoryform.h"
#include <QString>
#include "item.h"

#include <QTableWidgetItem>
#include <QInputDialog>
#include <QMessageBox>

#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QByteArray>
#include <QDebug>
#include <QLabel>
#include "QVBoxLayout"

InventoryForm::InventoryForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InventoryForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;

    ui->textEditLowStock->setReadOnly(true);

    ui->tableWidgetInventoryItems->setColumnCount(7);

    ui->tableWidgetInventoryItems->setHorizontalHeaderLabels(
        {"Name", "Quantity", "Category", "Price", "Supplier", "Photo", "Action"});

    // Real-time connections
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &InventoryForm::refreshItems);
    connect(ui->comboBoxCriteria, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            &InventoryForm::refreshItems);

    ui->tableWidgetInventoryItems->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);
    ui->tableWidgetInventoryItems->setEditTriggers(QAbstractItemView::NoEditTriggers);

    refreshItems();
    displayLowStock();
}

InventoryForm::~InventoryForm()
{
    delete ui;
}

void InventoryForm::on_pushButtonAdd_clicked()
{
    AddItemForm addItemDialog(inventorySystem, this);
    int result = addItemDialog.exec();

    if (result == QDialog::Accepted)
    {
        qDebug() << "Dialog accepted, refreshing items...";
        qDebug() << "Item count before refresh:" << inventorySystem->getInventory().getItems().size();

        // Force inventory system to save and reload data
        inventorySystem->save();

        // Clear and rebuild the table
        ui->tableWidgetInventoryItems->clearContents();
        ui->tableWidgetInventoryItems->setRowCount(0);
        refreshItems();
        displayLowStock();

        qDebug() << "Item count after refresh:" << inventorySystem->getInventory().getItems().size();
    }
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
    ui->tableWidgetInventoryItems->setRowCount(0);
    QString searchValue = ui->lineEditSearch->text().trimmed().toLower();
    QString searchCriteria = ui->comboBoxCriteria->currentText();
    QVector<Item> allItems = inventorySystem->getInventory().getItems();

    for (const Item& item : allItems) {
        QString fieldValue;

        if (searchCriteria == "Name")
            fieldValue = item.name().toLower();
        else if (searchCriteria == "Category")
            fieldValue = item.category().toLower();
        else if (searchCriteria == "Supplier")
            fieldValue = item.supplier().toLower();

        if (searchValue.isEmpty() || fieldValue.contains(searchValue)) {
            int row = ui->tableWidgetInventoryItems->rowCount();
            ui->tableWidgetInventoryItems->insertRow(row);
            ui->tableWidgetInventoryItems->setItem(row, 0, new QTableWidgetItem(item.name()));
            ui->tableWidgetInventoryItems->setItem(row, 1, new QTableWidgetItem(QString::number(item.quantity())));
            ui->tableWidgetInventoryItems->setItem(row, 2, new QTableWidgetItem(item.category()));
            ui->tableWidgetInventoryItems->setItem(row, 3, new QTableWidgetItem(QString::number(item.price())));
            ui->tableWidgetInventoryItems->setItem(row, 4, new QTableWidgetItem(item.supplier()));

            // Add Sell button
            QPushButton* sellButton = new QPushButton("Sell");
            sellButton->setProperty("itemName", item.name());
            sellButton->setProperty("itemSupplier", item.supplier());
            sellButton->setProperty("itemCategory", item.category());
            connect(sellButton, &QPushButton::clicked, this, &InventoryForm::onSellButtonClicked);
            ui->tableWidgetInventoryItems->setCellWidget(row, 6, sellButton);

            // Add photo button
            QPushButton* photoButton = new QPushButton("View Photo");
            photoButton->setProperty("itemName", item.name());
            connect(photoButton, &QPushButton::clicked, [this, item]() {
                displayItemPhoto(item.name());
            });
            ui->tableWidgetInventoryItems->setCellWidget(row, 5, photoButton);
            QApplication::processEvents();
        }
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

void InventoryForm::onSellButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    QString itemName = button->property("itemName").toString();
    QString itemSupplier = button->property("itemSupplier").toString();
    QString itemCategory = button->property("itemCategory").toString();

    QVector<Item> items = inventorySystem->getInventory().getItems();
    Item targetItem;
    bool found = false;

    for (const Item& item : items) {
        if (item.name() == itemName &&
            item.supplier() == itemSupplier &&
            item.category() == itemCategory) {
            targetItem = item;
            found = true;
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Error", "Item not found.");
        return;
    }

    bool ok;
    int sellQuantity = QInputDialog::getInt(this,
                                    "Sell Item",
                                    "Enter quantity to sell:",
                                    1,
                                    1,
                                    targetItem.quantity(),
                                    1,
                                    &ok);
    if (!ok)
        return;

    Item itemToRemove(itemName, itemCategory, sellQuantity, targetItem.price(), itemSupplier);
    if (inventorySystem->removeItem(itemToRemove)) {
        refreshItems();
        displayLowStock();
        QMessageBox::information(this, "Sucess", QString("Sold %1 units of %2").arg(sellQuantity).arg(itemName));
    } else {
        QMessageBox::warning(this, "Error", "Failed to update inventory.");
    }
}

void InventoryForm::displayItemPhoto(const QString& itemName)
{
    QPixmap photo = ItemPhotoManager::getInstance().getItemPhoto(itemName);

    if (!photo.isNull())
    {
        QDialog* photoDialog = new QDialog(this);
        photoDialog->setAttribute(Qt::WA_DeleteOnClose);
        photoDialog->setWindowTitle("Item Photo: " + itemName);

        QVBoxLayout* layout = new QVBoxLayout(photoDialog);

        QLabel* photoLabel = new QLabel(photoDialog);
        photoLabel->setPixmap(photo.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        layout->addWidget(photoLabel);
        photoDialog->setLayout(layout);
        photoDialog->show();
    }
    else
    {
        QMessageBox::information(this, "No Photo", "No photo available for this item");
    }
}
