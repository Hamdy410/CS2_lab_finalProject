#include "role.h"
#include <QString>

Role stringToRole(const QString &roleStr) {
    if (roleStr.toLower() == "admin")
        return Role::ADMIN;
    else if (roleStr.toLower() == "manager")
        return Role::MANAGER;
    else
        return Role::STAFF;
}

QString roleToString(const Role &role) {
    switch (role) {
    case Role::ADMIN: return "Admin";
    case Role::MANAGER: return "Manager";
    case Role::STAFF: return "Staff";
    default: return "Unknown";
    }
}
