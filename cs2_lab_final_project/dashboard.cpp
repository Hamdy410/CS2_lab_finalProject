#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventorysystem.h"
#include <QCloseEvent>
#include <QMessageBox>

Dashboard::Dashboard(InventorySystem* inventorySystemInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    inventorySystem = inventorySystemInput;
    ui->setupUi(this);

    ui->lowStock_textEdit->setReadOnly(true);
    ui->label_LowStock->setText("Low Stock Items: ");
    displayLowStock();

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


void Dashboard::on_pushButton_Report_clicked()
{
    if (inventorySystem->generateReport()) {
        QMessageBox::information(this, "Sucess", "Report generated successfully!");
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
