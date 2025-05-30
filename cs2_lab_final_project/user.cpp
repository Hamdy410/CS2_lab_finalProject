#include "user.h"
#include "user.h"
#include "role.h"

User::User(const QString& username, const QString& password,
           Role role)
{
    this->username = username;
    this->password = password;
    this->role = role;
}
bool User::login(const QString& enteredPassword) const
{
    return enteredPassword == password;
}
bool User::changePassword(const QString& oldPassword, const QString& newPassword)
{
    if(login(oldPassword))
    {
        password = newPassword;
        return true;
    }
    else
        return false;
}
bool User::canManageUsers() const
{
    qDebug() << "Current role:" << roleToString(role);
    qDebug() << "Result in manage users: " << (role == Role::ADMIN);
    return role == Role::ADMIN;
}
bool User::canEditInventory() const
{
    qDebug() << "Current role: " << roleToString(role);
    return (role == Role::ADMIN || role == Role::MANAGER);
}
bool User::operator==(const User& theObject) const
{
    return this->getUsername() == theObject.getUsername();
}
bool User::load(const QString& userData)
{
    QStringList parts = userData.split(',');
    if (parts.size() != 3) {
        return false;
    }

    username = parts[0];
    password = parts[1];
    role = stringToRole(parts[2]);

    return true;
}
QString User::getUsername() const
{
    return username;
}
Role User::getRole() const
{
    return role;
}
QString User::getPassword() const
{
    return password;
}
QString User::serialize() const
{
    return QString("%1,%2,%3").arg(username).arg(password).arg(roleToString(role));
}

