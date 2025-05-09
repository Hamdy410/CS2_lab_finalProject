#include "dashboard.h"
#include "ui_dashboard.h"
#include "inventorysystem.h"
#include <QCloseEvent>

Dashboard::Dashboard(InventorySystem* inventorySystemInput, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    inventorySystem = inventorySystemInput;
    ui->setupUi(this);
    ui->label_BestSellerSold->setText("Dashboard: " + inventorySystem->returnOperationRecord().getBestSeller());

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
    this->close();
}

