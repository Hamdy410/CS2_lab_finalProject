#include "inventorysystem.h"
#include <QFile>
#include <QTextStream>

InventorySystem::InventorySystem(QObject *parent, const QString &usersFile,
                                 const QString &inventoryFile,
                                 const QString &operationsFile)
    : QObject(parent),
    currentUser(nullptr),
    operations(operationsFile),
    usersFilePath(usersFile),
    inventoryFilePath(inventoryFile) {
    load();
}

InventorySystem::~InventorySystem() {
    currentUser = nullptr;
    save();
}

bool InventorySystem::load() {
    // load Users
    QFile usersFile(usersFilePath);
    if (usersFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        users.clear();
        QTextStream in(&usersFile);

        if (!in.atEnd())
            in.readLine();

        while (!in.atEnd()) {
            QString line = in.readLine();
            User user;
            if (user.load(line)) {
                users.insert(user);
            }
        }
        usersFile.close();
    } else {
        // Create a dedault admin if user file doesn't exist
        users.insert(User("admin", "admin", Role::ADMIN));
        save();
    }

    // Load Inventory
    if (!inventory.loadFromCSV()) {
        // Failed but continue anyways
    }

    return true;
}

bool InventorySystem::save() {
    // Save Users
    QFile usersFile(usersFilePath);
    if(!usersFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream outUsers(&usersFile);
    outUsers << "username,password,role" << Qt::endl;

    for (const auto& user : users) {
        outUsers << user.serialize() << Qt::endl;
    }

    usersFile.close();
    inventory.saveToCSV();

    return true;
}

bool InventorySystem::authenticateUser(const QString &username, const QString &password) {
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            if (user.login(password)) {
                for (auto it = users.begin(); it != users.end(); it++) {
                    if (it->getUsername() == username) {
                        currentUser = const_cast<User*>(&(*it));
                        emit userChanged();
                        return true;
                    }
                }
            }
            break;
        }
    }
    return false;
}

bool InventorySystem::logout() {
    currentUser = nullptr;
    emit userChanged();
    return true;
}

bool InventorySystem::addUser(const User &user) {
    if (!isAuthenticated() || !currentUserCanManageUsers()) {
        return false;
    }

    for (const auto& existingUser : users) {
        if (existingUser == user) {
            return false;
        }
    }

    users.insert(user);
    save();

    Item dummyItem;
    operations.addRecord(dummyItem, currentUser->getUsername(), QDateTime(), "Added User: " + user.getUsername());
    return true;
}

bool InventorySystem::removeUser(const QString &username) {
    if (!isAuthenticated() || !currentUserCanManageUsers()) {
        return false;
    }

    // For current user not to delete themselves
    if (currentUser->getUsername() == username) {
        return false;
    }

    for (auto it = users.begin(); it != users.end(); it++) {
        if (it->getUsername() == username) {
            Item dummyItem;
            operations.addRecord(dummyItem, currentUser->getUsername(),
                                 QDateTime::currentDateTime(),
                                 "Removed User: " + username);
            users.erase(it);
            save();
            return true;
        }
    }

    return false;
}

QVector<User> InventorySystem::getUsers() const {
    if (!isAuthenticated() || !currentUserCanManageUsers()) {
        return QVector<User>();
    }

    return QVector<User>(users.begin(), users.end());
}

bool InventorySystem::userExists(const QString &username) const {
    for (const auto& user : users) {
        if (user.getUsername() == username)
            return true;
    }

    return false;
}

bool InventorySystem::updateUsername(const QString &oldusername, const QString &newUsername) {
    if (!isAuthenticated() || !currentUserCanManageUsers())
        return false;

    if (userExists(oldusername))
        return false;

    User targetUser;
    bool found = false;

    for (const auto& user : users) {
        if (user.getUsername() == oldusername) {
            targetUser = user;
            found = true;
            break;
        }
    }

    if (!found)
        return false;

    User updatedUser(newUsername, targetUser.getPassword(), targetUser.getRole());

    users.remove(targetUser);
    users.insert(updatedUser);

    if (currentUser && currentUser->getUsername() == oldusername) {
        for (auto it = users.begin(); it != users.end(); it++) {
            if (it->getUsername() == newUsername) {
                currentUser = const_cast<User*>(&(*it));
                break;
            }
        }
    }

    Item dummyItem;
    operations.addRecord(dummyItem, currentUser->getUsername(), QDateTime::currentDateTime(),
        "Changed username from " + oldusername + "to " + newUsername);

    save();
    emit userChanged();
    return true;
}

bool InventorySystem::resetUserPassword(const QString &username, const QString &newPassword) {
    if (!isAuthenticated() || !currentUserCanManageUsers())
        return false;

    User targetUser;
    bool found = false;

    for (const auto& user : users) {
        if (user.getUsername() == username) {
            targetUser = user;
            found = true;
            break;
        }
    }

    if (!found)
        return false;

    User updatedUser(username, newPassword, targetUser.getRole());

    users.remove(targetUser);
    users.insert(updatedUser);

    Item dummyItem;
    operations.addRecord(dummyItem, currentUser->getUsername(), QDateTime::currentDateTime(),
        "Reset password for user: " + username);

    save();
    emit userChanged();
    return true;
}

bool InventorySystem::updateUserRole(const QString &username, Role newRole) {
    if (!isAuthenticated() || !currentUserCanManageUsers())
        return false;

    if (currentUser->getUsername() == username)
        return false;

    for (auto it = users.begin(); it != users.end(); it++) {
        if (it->getUsername() == username) {
            User updatedUser(username, it->getPassword(), newRole);

            Item dummyItem;
            operations.addRecord(dummyItem, currentUser->getUsername(),
                                 QDateTime::currentDateTime(),
                                 "Updated role for users: " + username);
            users.erase(it);
            users.insert(updatedUser);
            save();
            emit userChanged();
            return true;
        }
    }

    return false;
}

bool InventorySystem::addItem(const Item &item) {
    if (!isAuthenticated() || !currentUserCanEditInventory())
        return false;

    bool result = inventory.addItem(item);
    if (result) {
        operations.addRecord(item, currentUser->getUsername(),
                            QDateTime::currentDateTime(),
                            "Added Item");
        save();
        emit inventoryChanged();
    }

    return result;
}

bool InventorySystem::removeItem(const Item& item) {
    if (!isAuthenticated() || !currentUserCanEditInventory())
        return false;

    bool result = inventory.removeItem(item);
    if (result) {
        operations.addRecord(item, currentUser->getUsername(),
                            QDateTime::currentDateTime(),
                            "Removed Item");
        save();
        emit inventoryChanged();
    }

    return result;
}

QVector<Item> InventorySystem::searchItems(const QString &name, const QString &supplier) {
    if (!isAuthenticated()) {
        return QVector<Item>();
    }

    return inventory.searchItem(name, supplier);
}

QVector<Item> InventorySystem::getLowStockItems() {
    if (!isAuthenticated()) {
        return QVector<Item>();
    }

    return inventory.getLowStockItems();
}

bool InventorySystem::generateReport() {
    if (!isAuthenticated())
        return false;

    bool result = inventory.generateReport();
    if (result) {
        Item dummyItem;
        operations.addRecord(dummyItem, currentUser->getUsername(),
                            QDateTime::currentDateTime(),
                            "Generated Report");
    }

    return result;
}

bool InventorySystem::isAuthenticated() const {
    return (currentUser != nullptr);
}

bool InventorySystem::currentUserCanManageUsers() const {
    return (isAuthenticated() && currentUser->canManageUsers());
}

bool InventorySystem::currentUserCanEditInventory() const {
    return (isAuthenticated() && currentUser->canEditInventory());
}

QString InventorySystem::getCurrentUsername() const {
    return isAuthenticated() ? currentUser->getUsername() : "";
}
