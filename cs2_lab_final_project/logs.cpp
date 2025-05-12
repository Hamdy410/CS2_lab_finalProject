#include "logs.h"
#include "ui_logs.h"
#include "operationrecord.h"
#include <QString>
#include "inventorysystem.h"

Logs::Logs(InventorySystem* inventorySystem, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Logs)
{
    int lastIndex = inventorySystem->getOperationRecord().getRecords().size() - 1;
    QString data;
    for (int i = lastIndex; i >= 0; i--) {
        if (inventorySystem->getOperationRecord().getRecords()[i].getOperation() == "Removed Item" || inventorySystem->getOperationRecord().getRecords()[i].getOperation() == "Added Item") {
            data += "Nigger";//inventorySystem->getOperationRecord().getRecords()[i].getOperation() + ", " + QString::number(inventorySystem->getOperationRecord().getRecords()[i].getItem().quantity()) + " of " + inventorySystem->getOperationRecord().getRecords()[i].getItem().name() + "\n";
        } else {
            data += "Nigger";// inventorySystem->getOperationRecord().getRecords()[i].getOperation() + "\n";
        }
    }
    ui->textEdit->setText(data);
    ui->setupUi(this);
}

Logs::~Logs()
{
    delete ui;
}
