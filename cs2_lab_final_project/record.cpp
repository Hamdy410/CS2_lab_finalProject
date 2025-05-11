#include "record.h"
#include <QDateTime>
#include <QString>
#include "item.h"

Record::Record(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam, const QString& operationParam) {
    item = itemParam;
    username = usernameParam;
    time = timeParam;
    operation = operationParam;
}

Item Record::getItem() const {
    return item;
}

QString Record::getUsername() const {
    return username;
}

QDateTime Record::getTime() const {
    return time;
}

QString Record::getOperation() const {
    return operation;
}
