#ifndef RECORD_H
#define RECORD_H

#include <QDateTime>
#include "item.h"
#include "user.h"

struct Record {
    Item item;
    User user;
    QDateTime time;
    QString operation;

    Record(const Item& item, const User& user, const QDateTime& time,
           const QString& operation="Unknown");

    QString serialize() const;
    bool deserialize(const QString& data);
};

#endif // RECORD_H
