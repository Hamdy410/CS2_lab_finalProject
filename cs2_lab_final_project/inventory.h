#ifndef INVENTORY_H
#define INVENTORY_H

#include <QSet>
#include <QVector>
#include <QString>
#include "item.h"

#define DEFAULT_ITEMS ":db/default_items.csv"

class Inventory
{
private:
    QVector<Item> items;
    QString m_inventoryFilePath;

public:
    Inventory(const QString& inventoryFilePath);
    virtual ~Inventory();


    bool addItem(const Item& theItem);
    bool removeItem(const Item& theItem);
    QVector<Item> getLowStockItems();
    bool generateReport();

    bool loadFromCSV();
    bool saveToCSV();

    const QVector<Item>& getItems() const;
};

#endif // INVENTORY_H
