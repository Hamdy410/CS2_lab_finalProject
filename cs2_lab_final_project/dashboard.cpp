#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventorysystem.h"
#include "inventoryform.h"
#include <QCloseEvent>
#include <QMessageBox>
#include "additemform.h"

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
    ui->label_TotalNumItems->setText("Total Number of Items: " + QString::number(inventorySystem->getInventory().getItems().size()));
    ui->label->setText("Welcome, " + inventorySystem->getCurrentUsername() + "!");
    ui->label_BestSeller->setText("Best Seller: " + inventorySystem->getOperationRecord().getBestSeller());
    ui->label_lowesrSeller->setText("Lowest Seller: " + inventorySystem->getOperationRecord().getLowestSeller());
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
        // InventoryForm* displayToAdd = new InventoryForm(inventorySystem, this);
        // // displayToAdd->show();
        // // this->hide();
        // AddItemForm addItemDialog(inventorySystem, this);
        // if (addItemDialog.exec() == QDialog::Accepted)
        // {
        //     displayToAdd->refreshItems();
        //     displayLowStock();
        // }
        AddItemForm* add = new AddItemForm(inventorySystem, this);
        add->show();
    }
}

