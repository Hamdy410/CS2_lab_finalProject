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
    Operation(const QString& filePath="operations.csv");
    void addRecord(const Item& item, const User& user,
        const QDateTime& time=QDateTime::currentDateTime(),
                   const QString& operation="Unknown");
    bool load();
    bool save();

    const QVector<Record>& getRecords() const;
};

#endif // OPERATIONRECORD_H
