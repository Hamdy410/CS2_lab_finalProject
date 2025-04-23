#ifndef USER_H
#define USER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include "role.h"

class User
{
private:
    QString username;
    QString password;
    Role role;

public:
    User(const QString& username="", const QString& password="",
            Role role=Role::STAFF);

    bool login(const QString& enteredPassword) const;
    bool changePassword(const QString& oldPassword, const QString& newPassword);
    bool canManageUsers() const;
    bool canEditInventory() const;
    bool operator==(const User& theObject) const;
    bool load(const QString& userData);

    QString getUsername() const;
    Role getRole() const;
    QString getPassword() const;

    QString serialize() const;
};


#endif // USER_H
