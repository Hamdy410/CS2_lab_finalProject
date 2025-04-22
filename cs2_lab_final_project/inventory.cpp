#include "inventory.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

uint qHash(const Item& item) {
    return qHash(item.name() + ":" + item.supplier());
}

Inventory::Inventory() {
    loadFromCSV();
}

Inventory::~Inventory() {
    saveToCSV();
}

bool Inventory::addItem(const Item &theItem) {
    for (auto it = items.begin(); it != items.end(); it++) {
        if (*it == theItem) {
            Item updatedItem = *it;
            updatedItem += theItem;

            // Since QSet doesn't allow direct modification
            items.remove(*it);
            items.insert(updatedItem);
            return true;
        }
    }

    items.insert(theItem);
    return true;
}

bool Inventory::removeItem(const Item &theItem) {
    for (auto it = items.begin(); it != items.end(); it++) {
        if (*it == theItem) {
            Item updatedItem = *it;
            updatedItem.setQuantity(updatedItem.quantity() - theItem.quantity());
            // Allow negative quantities for loans

            items.remove(*it);
            items.insert(updatedItem);
            return true;
        }
    }

    return false;
}

bool Inventory::searchItem(const QString &itemName, const QString &itemSupplier) {
    QVector<Item> matchingItems;
    for (const auto &item : items) {
        bool nameMatches = itemName.isEmpty() || item.name() == itemName;
        bool supplierMatches = itemSupplier.isEmpty() || item.supplier() == itemSupplier;

        if (nameMatches && supplierMatches) {
            matchingItems.append(item);
        }
    }

    return matchingItems;
}

QVector<Item> Inventory::getLowStockItems() {
    QVector<Item> lowStockItems;
    for (const auto& item : items) {
        if (item.quantity() < 5) {
            lowStockItems.append(items);
        }
    }

    return lowStockItems;
}

bool Inventory::generateReport() {
    QFile file("iventory_report.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "Inventory Report -" << QDateTime::currentDateTime().toString()
        << "\n\n";
    out << "Total items: " << items.size() << "\n\n";

    out << "INVENTORY LISTING:\n";
    out << "----------------------------\n";
    for (const auto& item : items) {
        QTextStream itemStream(&out);
        item.getDetails(itemStream);
    }

    QVector<Item> lowStock = getLowStockItems();
    out << "\nLOW STOCK ITEMS:\n";
    out << "----------------------------\n";
    if (lowStock.isEmpty()) {
        out << "No low stock items found.\n";
    } else {
        for (const auto& item: lowStock) {
            QTextStream itemStream(&out);
            item.getDetails(itemStream);
        }
    }

    file.close();
    return true;
}

bool Inventory::loadFromCSV() {
    QFile file(FILE_ITEMS);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    if (!in.atEnd())
        in.readLine();

    while (!in.atEnd()) {
        QString line = in.readLine();
        QString fields = line.split(",");

        if (fields.size() >= 5) {
            Item item(
                fields[0],              // name
                fields[1],              // category
                fields[2].toInt(),      // quantity
                fields[3].toDouble(),   // price
                fields[4]               // supplier
            );
            addItem(item);
        }
    }

    file.close();
    return true;
}

bool Inventory::saveToCSV() {
    QFile file(FILE_ITEMS);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "name, category, quantity, price, supplier" << Qt::endl;

    for (const auto& item : items) {
        out << item.name() << ","
            << item.category() << ","
            << item.quantity() << ","
            << item.price() << ","
            << item.supplier() << Qt::endl;
    }

    file.close();
    return true;
}

const QSet<Item>& Inventory::getItems() const {
    return items;
}
