#ifndef OPERATIONRECORD_H
#define OPERATIONRECORD_H

#include <QVector>
#include <QFile>
#include <QTextStream>
#include "record.h"

class OperationRecord
{
private:
    QVector<Record> records;
    QString recordsFilePath;

public:
    OperationRecord();
    void addRecord(const Item& item, const QString& username, const QDateTime& time=QDateTime::currentDateTime(), const QString& operation="Unknown");
    bool save();
    const QVector<Record>& getRecords() const;
    bool loadOperationRecords();
    Item item;
    QDateTime time;
};

#endif // OPERATIONRECORD_H
