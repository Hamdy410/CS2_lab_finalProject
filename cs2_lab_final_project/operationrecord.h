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
<<<<<<< HEAD
    Operation(const QString& filePath="operations.csv");
    void addRecord(const Item& item, const User& user,
        const QDateTime& time=QDateTime::currentDateTime(),
                   const QString& operation="Unknown");
    bool load();
    bool save();

    const QVector<Record>& getRecords() const;
=======
    OperationRecord(Item itemParam, User userParam, QDateTime timeParam);
    bool loadOperationRecords();
    Item item;
    User user;
    QDateTime time;
>>>>>>> 45d8d739672ecad24dea7d9414b3ae5fcda1f962
};

#endif // OPERATIONRECORD_H
