#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <QVector>
#include "inventory.h"
#include "user.h"
#include "record.h"
#include "operationrecord.h"

class InventorySystem : public QObject
{
    Q_OBJECT

private:
    QVector<User> users;
    Inventory inventory;
    User* currentUser;
    OperationRecord operations;

    QString usersFilePath;
    QString inventoryFilePath;

public:
    InventorySystem(QObject* parent = nullptr,
                    const QString& usersFile="users.csv",
                    const QString& inventoryFile="inventory.csv",
                    const QString& operationsFile="operations.csv");
    ~InventorySystem();

    bool load();
    bool save();
    bool authenticateUser(const QString& user, const QString& password);
    bool logout();

    // User management
    bool addUser(const User& user);
    bool removeUser(const QString& username);
    QVector<User> getUsers() const;
    bool userExists(const QString& username) const;

    bool updateUser(const QString& oldUsername, const QString& newUsername,
                    const QString& newPassword, Role newRole);

    // Inventory Operations
    bool addItem(const Item& item);
    bool removeItem(const Item& item);
    QVector<Item> getLowStockItems();
    bool generateReport();
    const Inventory& getInventory() const;

    // Current user info
    bool isAuthenticated() const;
    bool currentUserCanManageUsers() const;
    bool currentUserCanEditInventory() const;
    QString getCurrentUsername() const;
    User* getCurrentUser() const { return currentUser; }
    OperationRecord returnOperationRecord();

signals:
    void userChanged();
    void inventoryChanged();
};

#endif // INVENTORYSYSTEM_H
