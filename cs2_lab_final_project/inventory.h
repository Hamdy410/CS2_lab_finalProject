#ifndef INVENTORY_H
#define INVENTORY_H

#include <QSet>
#include <QVector>
#include <QString>
#include "item.h"

#define FILE_ITEMS "items.csv"
#define DEFAULT_ITEMS ":db/default_items.csv"

class Inventory
{
private:
    QVector<Item> items;

public:
    Inventory();
    virtual ~Inventory();


    bool addItem(const Item& theItem);
    bool removeItem(const Item& theItem);
    QVector<Item> searchItem(const QString& itemName="", const QString& itemSupplier="");
    QVector<Item> getLowStockItems();
    bool generateReport();

    bool loadFromCSV();
    bool saveToCSV();

    const QVector<Item>& getItems() const;
};

#endif // INVENTORY_H
