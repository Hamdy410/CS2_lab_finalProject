#ifndef RECORD_H
#define RECORD_H

#include <QDateTime>
#include "item.h"
#include "user.h"
#include <QString>

class Record {
private:
    Item item;
    QString username;
    QDateTime time;
    QString operation;
public:
    Record(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam,
           const QString& operationParam="Unknown");

    Item getItem();
    QString getUsername();
    QDateTime getTime();
    QString getOperation();
    QString serialize() const;
    bool deserialize(const QString& data);
};

#endif // RECORD_H
