#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QTextStream>

class Item
{
private:
    QString m_name;
    QString m_category;
    int m_quantity;
    double m_price;
    QString m_supplier;

public:
    Item(const QString& name="", const QString& category="", int quantity = 0,
         double price = 0.0, const QString& supplier="");

    bool updateQuantity(int quantity, QString operation);
    bool getDetails(QTextStream& outs);
    bool operator==(const Item& theObject) const;
    Item& operator+=(const Item& theObject) const;
    Item& operator-=(const Item& theObject) const;
    bool load();

    QString name() const;
    QString category() const;
    int quantity() const;
    double price() const;
    QString supplier() const;

    void setName(const QString& name);
    void setCategory(const QString& category);
    void setQuantity(int quantity);
    void setPrice(double price);
    void setSupplier(const QString& supplier);
};

#endif // ITEM_H
