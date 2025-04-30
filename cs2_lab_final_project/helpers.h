#ifndef HELPERS_H
#define HELPERS_H

#include <QString>
#include <QStringList>

QStringList parseCSVRow(const QString& line);
QString quoteField(const QString& field);

#endif // HELPERS_H
