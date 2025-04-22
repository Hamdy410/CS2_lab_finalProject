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
    explicit OperationRecord(const QString& filePath);
    OperationRecord(Item itemParam, User userParam, QDateTime timeParam);
    void addRecord(const Item& item, const User& user, const QDateTime& time=QDateTime::currentDateTime(), const QString& operation="Unknown");
    bool save();
    const QVector<Record>& getRecords() const;
    bool loadOperationRecords();
    Item item;
    User user;
    QDateTime time;
};

#endif // OPERATIONRECORD_H
