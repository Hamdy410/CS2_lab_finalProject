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

Item Record::getItem() {
    return item;
}

QString Record::getUsername() {
    return username;
}

QDateTime Record::getTime() {
    return time;
}

QString Record::getOperation() {
    return operation;
}
