#ifndef INVENTORY_H
#define INVENTORY_H

#include <QSet>
#include <QVector>
#include <QString>
#include "item.h"

#define FILE_ITEMS "items.csv"

// Forward declare hash function for QSet to use with Item
uint qHash(const Item& item);

class Inventory
{
private:
    QSet<Item> items; // Using QSet as the unsorted_set equivalent

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

    const QSet<Item>& getItems() const;
};

#endif // INVENTORY_H
