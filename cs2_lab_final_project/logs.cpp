#include "logs.h"
#include "ui_logs.h"
#include "operationrecord.h"
#include <QString>
#include <QCloseEvent>
#include "inventorysystem.h"

Logs::Logs(InventorySystem* inventorySystem, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Logs)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    QString data;
    const QVector<Record>& records = inventorySystem->getOperationRecord().getRecords();

    // Check if there are any records
    if (records.isEmpty()) {
        data = "No operation records found.";
    } else {
        int lastIndex = records.size() - 1;
        for (int i = lastIndex; i >= 0; i--) {
            const Record& record = records[i];
            QString operation = record.getOperation();

            if (operation == "Removed Item" || operation == "Added Item") {
                data += operation + ", " +
                        QString::number(record.getItem().quantity()) +
                        " of " + record.getItem().name() +
                        " by " + record.getUsername() +
                        " at " + record.getTime().toString("yyyy-MM-dd hh:mm:ss") + "\n";
            } else {
                data += operation + " by " + record.getUsername() +
                        " at " + record.getTime().toString("yyyy-MM-dd hh:mm:ss") + "\n";
            }
        }
    }

    ui->textEdit->setText(data);
    setWindowTitle("Operation Logs");
}

void Logs::closeEvent(QCloseEvent *event) {
    event->accept();
}

Logs::~Logs()
{
    delete ui;
}
