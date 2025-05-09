#ifndef OPERATIONRECORD_H
#define OPERATIONRECORD_H

#include <QVector>
#include <QFile>
#include <QTextStream>
#include "record.h"

class InventorySystem;

class OperationRecord
{
private:
    QVector<Record> records;
    QString recordsFilePath;

public:
    InventorySystem* inventorySystem;
    OperationRecord(InventorySystem* inventorySystemParam, QString csvFilePath);
    void addRecord(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam=QDateTime::currentDateTime(), const QString& operationParam="Unknown");
    bool save();
    const QVector<Record>& getRecords() const;
    bool loadOperationRecords(QString csvFilePath);
    Item item;
    QDateTime time;
    QString getBestSeller();
};

#endif // OPERATIONRECORD_H
