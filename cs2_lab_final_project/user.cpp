#include "user.h"

User::User(const QString& username="", const QString& password="",
           Role role=Role::STAFF)
{
    this->username = username;
    this->password = password;
    this->role = role;
}
bool User::login(const QString& enteredPassword)
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
    return role == Role::ADMIN;
}
bool User::canEditInventory() const
{
    return role == Role::MANAGER;
}
bool User::operator==(const User& theObject) const
{
    return username == theObject.username && password == theObject.password && role == theObject.role;
}
bool User::load(const QString& userData)
{

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
uint User::qHash(const User& user)
{
    return qHash(user.getUsername());
}
