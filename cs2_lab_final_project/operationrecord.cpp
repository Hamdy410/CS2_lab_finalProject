#include "operationrecord.h"
#include "operationrecord.h"
#include <QTextStream>
#include <Qfile>
#include <QString>
#include "record.h"
#include <vector>
#include "item.h"
#include "user.h"
#include <QDateTime>

OperationRecord::OperationRecord() {
    loadOperationRecords();
}

bool OperationRecord::loadOperationRecords() {
    QFile file(":/db/db/operation_records.csv");
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(',');

        QString name = values[0];
        QString category = values[1];
        int quantity = QString::number(values[2]);
        double price = QString::number(values[3]);
        QString supplier = values[4];
        QString username = values[5];
        QDateTime time = QDateTime::fromString(values[6]);

        Item newItem(name, category, quantity, price, supplier);
        addRecord(newItem, username, time, operation)
    }
    return true;
}

void OperationRecord::addRecord(const Item& item, const QString& username, const QDateTime& time=QDateTime::currentDateTime(), const QString& operation="Unknown") {
    Record newRecord(item, username, time, operation);
    records.push_back(newRecord);
}
