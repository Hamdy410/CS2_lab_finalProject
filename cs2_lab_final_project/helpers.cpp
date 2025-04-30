#include "helpers.h"

QStringList parseCSVRow(const QString &line) {
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

QString quoteField(const QString &field) {
    if (field.contains(',') || field.contains('"')) {
        QString escaped = field;
        escaped.replace("\"", "\"\"");
        return "\"" + escaped + "\"";
    }

    return field;
}
