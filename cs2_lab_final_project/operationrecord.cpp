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
#include <QMap>
#include <QMapIterator>
#include "inventorysystem.h"
#include "helpers.h"

OperationRecord::OperationRecord(InventorySystem* inventorySystemParam, QString csvFilePath) {
    inventorySystem = inventorySystemParam;
    loadOperationRecords(csvFilePath);
}

bool OperationRecord::loadOperationRecords(QString csvFilePath) {
    QFile file(csvFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QFile defaultFile(":/db/default_operations.csv");
        if (!defaultFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            recordsFilePath = csvFilePath;
            return true;
        }

        QTextStream in(&defaultFile);
        if (!in.atEnd()) in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = parseCSVRow(line);

            if (values.size() >= 8) {
                Item newItem(
                    values[0],
                    values[1],
                    values[2].toInt(),
                    values[3].toDouble(),
                    values[4]
                    );
                addRecord(
                    newItem,
                    values[5],
                    QDateTime::fromString(values[6]),
                    values[7]
                    );
            }
        }
        defaultFile.close();
    } else {
        QTextStream in(&file);
        if (!in.atEnd()) in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = parseCSVRow(line);

            if (values.size() >= 8) {
                Item newItem(
                    values[0],
                    values[1],
                    values[2].toInt(),
                    values[3].toDouble(),
                    values[4]
                    );
                addRecord(
                    newItem,
                    values[5],
                    QDateTime::fromString(values[6]),
                    values[7]
                    );
            }
        }

        file.close();
    }

    recordsFilePath = csvFilePath;
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
    QFile file(recordsFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "name,category,quantity,price,supplier,username,time,operation" << Qt::endl;

    for (int i = 0; i < records.size(); i++) {
        QString name = records[i].getItem().name();
        QString category = records[i].getItem().category();
        int quantity = records[i].getItem().quantity();
        double price = records[i].getItem().price();
        QString supplier = records[i].getItem().supplier();
        QString username = records[i].getUsername();
        QDateTime time = records[i].getTime();
        QString operation = records[i].getOperation();

        QString row = QString("%1,%2,%3,%4,%5,%6,%7,%8")
                          .arg(name)
                          .arg(category)
                          .arg(quantity)
                          .arg(price)
                          .arg(supplier)
                          .arg(username)
                          .arg(time.toString())
                          .arg(operation);
        out << row << Qt::endl;
    }
    file.close();
    return true;
}

QString OperationRecord::getBestSeller() const {
    QMap<QString, int> salesByItem;
    for (const Record& record : records) {
        if (record.getOperation() == "Removed Item") {
            QString itemName = record.getItem().name();
            int quantity = record.getItem().quantity();

            if (salesByItem.contains(itemName)) {
                salesByItem[itemName] += quantity;
            } else {
                salesByItem[itemName] = quantity;
            }
        }
    }

    int maxSold = 0;
    QString bestSeller = "No Sales Yet!";

    QMapIterator<QString, int> i(salesByItem);
    while (i.hasNext()) {
        i.next();
        if (i.value() > maxSold) {
            maxSold = i.value();
            bestSeller = i.key();
        }
    }

    return bestSeller + " (" + QString::number(maxSold) + " units)";
}

QString OperationRecord::getLowestSeller() const {
    QMap<QString, int> salesByItem;

    for (const Record& record: records) {
        if (record.getOperation() == "Removed Item") {
            QString itemName = record.getItem().name();
            int quantity = record.getItem().quantity();

            if (salesByItem.contains(itemName)) {
                salesByItem[itemName] += quantity;
            } else {
                salesByItem[itemName] = quantity;
            }
        }
    }

    if (salesByItem.isEmpty()) {
        return "No Sales Yet!";
    }

    int minSold = INT_MAX;
    QString lowestSeller = "";

    QMapIterator<QString, int> i(salesByItem);
    while (i.hasNext()) {
        i.next();
        if (i.value() < minSold) {
            minSold = i.value();
            lowestSeller = i.key();
        }
    }

    return lowestSeller + " (" + QString::number(minSold) + " units)";
}

QString OperationRecord::getLowStock() const {
    if (!inventorySystem) {
        return "\tSystem Error: Cannot access inventory";
    }

    QVector<Item> lowStockItems = inventorySystem->getLowStockItems();

    if (lowStockItems.isEmpty()) {
        return "\tNo low stock items!";
    }

    QString result;
    for (const Item& item : lowStockItems) {
        result += "\t" + item.name() + " has only " + QString::number(item.quantity()) + " left!\n";
    }

    return result;
}
