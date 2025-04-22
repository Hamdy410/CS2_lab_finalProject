#ifndef RECORD_H
#define RECORD_H

#include <QDateTime>
#include "item.h"
#include "user.h"
#include <QString>
#include "record.h"

struct Record {
    Item item;
    QString username;
    QDateTime time;
    QString operation;

    Record(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam,
           const QString& operationParam="Unknown");

    QString serialize() const;
    bool deserialize(const QString& data);
};

#endif // RECORD_H
