#include "record.h"
#include <QDateTime>
#include <QString>
#include "item.h"

Record::Record(const Item& itemParam, const QString& usernameParam, const QDateTime& timeParam, const QString& operationParam="Unknown") {
    item = itemParam;
    username = usernameParam;
    time = timeParam;
    operation = operationParam;
}
