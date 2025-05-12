#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventorysystem.h"
#include "inventoryform.h"
#include <QCloseEvent>
#include <QMessageBox>
#include "additemform.h"
#include "logs.h"

Dashboard::Dashboard(InventorySystem* inventorySystemInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    inventorySystem = inventorySystemInput;
    ui->setupUi(this);

    if (!inventorySystem->currentUserCanEditInventory()) {
        ui->pushButtonAddItem->hide();
        qDebug() << "User cannot add items - hiding add item button.";
    }

    ui->lowStock_textEdit->setReadOnly(true);
    ui->label_LowStock->setText("Low Stock Items: ");
    displayLowStock();

    ui->label_BestSeller->setText("Best Seller: " + inventorySystem->getOperationRecord().getBestSeller());
    ui->label_lowesrSeller->setText("Lowest Seller: " + inventorySystem->getOperationRecord().getLowestSeller());

    ui->label_TotalNumItems->setText("Total No. of Items: " + QString::number(inventorySystem->getInventory().getItems().size()));

    ui->label->setText("Welcome, " + inventorySystem->getCurrentUsername() + "!");

    QString updatesOutput;
    int lastIndex = inventorySystem->getOperationRecord().getRecords().size() - 1;
    int count = 0;

    // Only enter the loop if there are records
    if (lastIndex >= 0) {
        for (int i = lastIndex; i >= 0 && count < 3; i--, count++) {
            const Record& record = inventorySystem->getOperationRecord().getRecords()[i];
            if (record.getOperation() == "Removed Item" || record.getOperation() == "Added Item") {
                updatesOutput += record.getOperation() + ", " +
                                 QString::number(record.getItem().quantity()) +
                                 " of " + record.getItem().name() + "\n";
            } else {
                updatesOutput += record.getOperation() + "\n";
            }
        }
    }

    // If no records were found
    if (updatesOutput.isEmpty()) {
        updatesOutput = "No recent operations";
    }

    ui->textEdit->setText(updatesOutput);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_goBackPushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void Dashboard::closeEvent(QCloseEvent *event) {
    this->parentWidget()->show();
    event->accept();
}


void Dashboard::on_pushButton_Report_clicked() {
    if (inventorySystem->generateReport()) {
        QMessageBox::information(this, "Success", "Report generated successfully!");

        // Open the report file with the default text editor
        if (!inventorySystem->openReportFile()) {
            QMessageBox::warning(this, "Warning",
                                 "Report was generated but could not be opened automatically.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to generate report.");
    }
}


void Dashboard::displayLowStock() {
    QVector<Item> lowStock = inventorySystem->getLowStockItems();
    ui->lowStock_textEdit->clear();

    if (lowStock.isEmpty()) {
        ui->lowStock_textEdit->append("No low stock items");
        return;
    }

    for (const Item& item : lowStock) {
        ui->lowStock_textEdit->append(item.name() + " - only " + QString::number(item.quantity()) + " left");
    }
}

void Dashboard::on_pushButtonAddItem_clicked()
{
    if ( !inventorySystem->currentUserCanEditInventory())
    {
        QMessageBox::warning(this, "Error", "You are not authenticated to add items");
    }
    else
    {
        AddItemForm* add = new AddItemForm(inventorySystem, this);
        add->show();
    }
}


void Dashboard::on_pushButton_Logs_clicked()
{
    Logs* logs = new Logs(inventorySystem, this);
    logs->show();
}

