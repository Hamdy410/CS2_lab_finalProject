#include "inventory.h"
#include "item.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

QStringList Inventory::parseCSVRow(const QString &line) {
    QStringList result;
    QString current;
    bool inQuotes = false;

    for (int i = 0; i < line.length(); i++) {
        QChar c = line[i];
        if (c == '"') {
            // Check for the escaped quote.
            if (inQuotes && i + 1 < line.length() && line[i+1] == '"') {
                current += '"';
                i++;
            } else {
                inQuotes = !inQuotes;
            }
        } else if (c == ',' && !inQuotes) {
            result.append(current.trimmed());
            current.clear();
        } else {
            current += c;
        }
    }

    result.append(current.trimmed());
    return result;
}

QString Inventory::quoteField(const QString &field) {
    if (field.contains(',') || field.contains('"')) {
        QString escaped = field;
        escaped.replace("\"", "\"\"");
        return "\"" + escaped + "\"";
    }

    return field;
}

Inventory::Inventory(const QString& inventoryFilePath) : m_inventoryFilePath(inventoryFilePath) {
    loadFromCSV();
}

Inventory::~Inventory() {
    saveToCSV();
}

bool Inventory::addItem(const Item &theItem) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == theItem) {
            Item updatedItem = items[i];
            updatedItem += theItem;

            // Since QSet doesn't allow direct modification
            items.removeOne(items[i]);
            items.push_back(updatedItem);
            return true;
        }
    }

    items.push_back(theItem);
    return true;
}

bool Inventory::removeItem(const Item &theItem) {
    for (int i = 0; i < items.size(); i++) {
        if (items[i] == theItem) {
            Item updatedItem = items[i];
            updatedItem.setQuantity(updatedItem.quantity() - theItem.quantity());
            // Allow negative quantities for loans

            items.removeOne(items[i]);
            items.push_back(updatedItem);
            return true;
        }
    }

    return false;
}

QVector<Item> Inventory::searchItem(const QString& itemName, const QString& itemSupplier) {
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
        if (item.quantity() < 15) {
            lowStockItems.append(item);
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
        item.getDetails(out);
    }

    QVector<Item> lowStock = getLowStockItems();
    out << "\nLOW STOCK ITEMS:\n";
    out << "----------------------------\n";
    if (lowStock.isEmpty()) {
        out << "No low stock items found.\n";
    } else {
        for (const auto& item: lowStock) {
            item.getDetails(out);
        }
    }

    file.close();
    return true;
}

bool Inventory::loadFromCSV() {
    QFile file(m_inventoryFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QFile defaultFile(DEFAULT_ITEMS);
        if (!defaultFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return false;

        QTextStream in(&defaultFile);
        if (!in.atEnd())
            in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = parseCSVRow(line);

            if (fields.size() >= 5) {
                Item item(
                    fields[0],
                    fields[1],
                    fields[2].toInt(),
                    fields[3].toDouble(),
                    fields[4]
                    );
                addItem(item);
            }
        }

        defaultFile.close();
        return true;
    }

    QTextStream in(&file);
    if (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = parseCSVRow(line);

        if (fields.size() >= 5) {
            Item item(
                fields[0],
                fields[1],
                fields[2].toInt(),
                fields[3].toDouble(),
                fields[4]
                );
            addItem(item);
        }
    }

    file.close();
    return true;
}

bool Inventory::saveToCSV() {
    QFile file(m_inventoryFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "name, category, quantity, price, supplier" << Qt::endl;

    for (const auto& item : items) {
        out << quoteField(item.name()) << ","
            << quoteField(item.category()) << ","
            << item.quantity() << ","
            << item.price() << ","
            << quoteField(item.supplier()) << Qt::endl;
    }

    file.close();
    return true;
}

const QVector<Item>& Inventory::getItems() const {
    return items;
}
