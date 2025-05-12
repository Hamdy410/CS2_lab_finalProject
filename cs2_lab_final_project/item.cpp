#include "item.h"
#include <QString>

Item::Item(const QString& name, const QString& category, int quantity, double price, const QString& supplier) {
    m_name = name;
    m_category = category;
    m_quantity = quantity;
    m_price = price;
    m_supplier = supplier;
}

bool Item::updateQuantity(int quantity, QString operation) {
    if (operation == "+")
        m_quantity += quantity;
    else
        m_quantity -= quantity;
    return true;
}

bool Item::operator==(const Item& theObject) const {
    return theObject.name() == m_name
           && theObject.category() == m_category
           && theObject.price() == m_price
           && theObject.supplier() == m_supplier;
}

Item& Item::operator+=(const Item& theObject) {
    m_quantity += theObject.quantity();
    return *this;
}

Item& Item::operator-=(const Item& theObject) {
    m_quantity -= theObject.quantity();
    return *this;
}

bool Item::load() { return true; }

QString Item::name() const {
    return m_name;
}

QString Item::category() const {
    return m_category;
}

int Item::quantity() const {
    return m_quantity;
}

double Item::price() const {
    return m_price;
}

QString Item::supplier() const {
    return m_supplier;
}

void Item::setName(const QString& name) {
    m_name = name;
}

void Item::setCategory(const QString& category) {
    m_category = category;
}

void Item::setQuantity(int quantity) {
    m_quantity = quantity;
}

void Item::setPrice(double price) {
    m_price = price;
}

void Item::setSupplier(const QString& supplier) {
    m_supplier = supplier;
}
