#ifndef OPERATIONRECORD_H
#define OPERATIONRECORD_H
#include "item.h"
#include "user.h"
#include <QDateTime>

class OperationRecord
{
public:
    OperationRecord(Item itemParam, User userParam, QDateTime timeParam);
    bool loadOperationRecords();
    Item item;
    User user;
    QDateTime time;
};

#endif // OPERATIONRECORD_H
