#ifndef ROLE_H
#define ROLE_H
#include <QString>

#include <QString>
enum class Role {
    STAFF,
    MANAGER,
    ADMIN
};

Role stringToRole(const QString& roleStr);

QString roleToString(const Role& role);

#endif // ROLE_H
