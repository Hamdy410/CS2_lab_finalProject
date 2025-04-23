#include "operationrecord.h"
#include "operationrecord.h"
#include <QTextStream>
#include <QFile>
#include <QString>
#include "record.h"
#include <vector>
#include "item.h"
#include "user.h"
#include <QDateTime>
#include <QTextStream>
#include "inventorysystem.h"

OperationRecord::OperationRecord(InventorySystem* inventorySystemParam, QString csvFilePath) {
    inventorySystem = inventorySystemParam;
    loadOperationRecords(csvFilePath);
}

bool OperationRecord::loadOperationRecords(QString csvFilePath) {
    QFile file(csvFilePath);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QString name = values[0];
        QString category = values[1];
        int quantity = values[2].toInt();
        double price = values[3].toDouble();
        QString supplier = values[4];
        QString username = values[5];
        QDateTime time = QDateTime::fromString(values[6]);
        QString operation = values[7];

        Item newItem(name, category, quantity, price, supplier);
        addRecord(newItem, username, time, operation);
    }
    file.close();
    return true;
}

void OperationRecord::addRecord(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam, const QString& operationParam) {
    Record newRecord(itemParam, usernameParam, timeParam, operationParam);
    records.push_back(newRecord);
}

const QVector<Record>& OperationRecord::getRecords() const {
    return records;
}

bool OperationRecord::save() {
    QFile file(":/db/db/operation_records.csv");
    QTextStream out(&file);

    for (int i = 0; i < records.size(); i++) {
        QString name = records[i].getItem().name();
        QString category = records[i].getItem().category();
        int quantity = records[i].getItem().quantity();
        double price = records[i].getItem().price();
        QString supplier = records[i].getItem().supplier();
        QString username = records[i].getUsername();
        QDateTime time = records[i].getTime();
        QString operation = records[i].getOperation();

        QString row = QString("%1,%2,%3,%4,%5,%6,%7,%8\n")
                          .arg(name)
                          .arg(category)
                          .arg(quantity)
                          .arg(price)
                          .arg(supplier)
                          .arg(username)
                          .arg(time.toString())
                          .arg(operation);
        out << row;
    }
    file.close();
    return true;
}
