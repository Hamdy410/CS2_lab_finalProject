#include "inventory.h"
#include "item.h"
#include "helpers.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>
#include <QString>

Inventory::Inventory(const QString& inventoryFilePath) : m_inventoryFilePath(inventoryFilePath) {
    loadFromCSV();
}

Inventory::~Inventory() {
    saveToCSV();
}

bool Inventory::addItem(const Item &theItem) {
    for (auto& item : items) {
        if (item == theItem) {
            item += theItem;
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
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString reportPath = dataDir + QDir::separator() + "inventory_report.txt";

    QFile file(reportPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    // Report header
    out << "Inventory Report - Generated on " << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")
        << "\n\n";
    out << "Total items in inventory: " << items.size() << "\n\n";

    // Define column headers and widths
    QStringList headers = {"Item", "Category", "Quantity", "Price", "Supplier"};
    QVector<int> columnWidths = {20, 15, 10, 10, 30};

    // LOW STOCK ALERTS
    QVector<Item> lowStock = getLowStockItems();
    out << "LOW STOCK ALERTS:\n";
    out << "----------------------------------\n";

    if (lowStock.isEmpty()) {
        out << "No low stock items found.\n\n";
    } else {
        printTable(out, headers, columnWidths, lowStock);
        out << "\n";
    }

    // FULL INVENTORY
    out << "INVENTORY LISTING:\n";
    out << "--------------------------------\n";
    printTable(out, headers, columnWidths, items);

    file.close();
    return true;
}



bool Inventory::loadFromCSV() {
    items.clear();

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
    if (!in.atEnd()) in.readLine();

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

    file.close();
    return true;
}

bool Inventory::saveToCSV() {
    QFile file(m_inventoryFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "name,category,quantity,price,supplier" << Qt::endl;

    for (const auto& item : items) {
        out << quoteField(item.name()) << ","
            << quoteField(item.category()) << ","
            << item.quantity() << ","
            << item.price() << ","
            << quoteField(item.supplier()) << Qt::endl;
    }

    qDebug() << "Saving to:" << m_inventoryFilePath;

    file.close();
    return true;
}

const QVector<Item>& Inventory::getItems() const {
    return items;
}

void Inventory::printTable(QTextStream& out, const QStringList& headers, const QVector<int>& columnWidths, const QVector<Item>& items) {
    // Print top border
    out << "+";
    for (int width : columnWidths) {
        out << QString("-").repeated(width + 2) << "+";
    }
    out << "\n";

    // Print header row
    out << "|";
    for (int i = 0; i < headers.size(); i++) {
        out << " " << headers[i].leftJustified(columnWidths[i], ' ') << " |";
    }
    out << "\n";

    // Print separator
    out << "+";
    for (int width : columnWidths) {
        out << QString("-").repeated(width + 2) << "+";
    }
    out << "\n";

    // Print data rows
    for (const auto& item : items) {
        out << "|";
        out << " " << item.name().left(columnWidths[0]).leftJustified(columnWidths[0], ' ') << " |";
        out << " " << item.category().left(columnWidths[1]).leftJustified(columnWidths[1], ' ') << " |";
        out << " " << QString::number(item.quantity()).leftJustified(columnWidths[2], ' ') << " |";
        out << " " << QString::number(item.price(), 'f', 2).leftJustified(columnWidths[3], ' ') << " |";
        out << " " << item.supplier().left(columnWidths[4]).leftJustified(columnWidths[4], ' ') << " |";
        out << "\n";
    }

    // Print bottom border
    out << "+";
    for (int width : columnWidths) {
        out << QString("-").repeated(width + 2) << "+";
    }
    out << "\n";
}

