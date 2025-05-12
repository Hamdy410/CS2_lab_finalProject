#include "inventorysystem.h"

#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>

InventorySystem::InventorySystem(QObject *parent, const QString &usersFile,
                                 const QString &inventoryFile,
                                 const QString &operationsFile)
    : QObject(parent),
    currentUser(nullptr),
    operations(this, operationsFile),
    usersFilePath(usersFile),
    inventory(inventoryFile){
    load();
    for (const auto &user : users) {
        qDebug() << "Detected user: " << user.getUsername();
    }
}

InventorySystem::~InventorySystem() {
    qDebug() << "save called in destructor";
    currentUser = nullptr;
    operations.save();
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
                users.push_back(user);
            }
        }
        usersFile.close();
    } else {
        // Create a default admin if user file doesn't exist
        QFile default_file(":db/default_users.csv");
        if (default_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Default users is working now.";
            users.clear();
            QTextStream in_def(&default_file);

            if (!in_def.atEnd()) {
                in_def.readLine();
            }

            while (!in_def.atEnd()) {
                QString line = in_def.readLine();
                User user;
                if (user.load(line)) {
                    qDebug() << "User Added.";
                    users.push_back(user);
                }
            }
            default_file.close();
        }
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
    {
        qDebug() << "Failed to open file or for writing:" << usersFile.fileName();
        qDebug() << "Error:" << usersFile.errorString();
        return false;
    }

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
        qDebug() << "Detected User: " << user.getUsername();
    }

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
#include <iostream>

bool InventorySystem::addUser(const User &user) {
    if (!isAuthenticated() || !currentUserCanManageUsers()) {
        return false;
    }

    for (const auto& existingUser : users) {
        if (existingUser == user) {
            return false;
        }
    }

    users.push_back(user);

    Item dummyItem;
    operations.addRecord(dummyItem, currentUser->getUsername(), QDateTime(),
                         "Added User: " + user.getUsername());
    return true;
}

bool InventorySystem::removeUser(const QString &username) {
    for (const auto& user: users) {
        qDebug() << "User before delete" << user.getUsername();
    }

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
            return true;
        }
    }

    for (const auto& user: users) {
        qDebug() << "User after delete: " << user.getUsername();
    }

    return false;
}

QVector<User> InventorySystem::getUsers() const {
    if (!isAuthenticated() || !currentUserCanManageUsers()) {
        return QVector<User>();
    }

    return users;
}

bool InventorySystem::userExists(const QString &username) const {
    for (const auto& user : users) {
        if (user.getUsername() == username)
            return true;
    }

    return false;
}

bool InventorySystem::updateUser(const QString &oldUsername, const QString &newUsername, const QString &newPassword, Role newRole) {
    if (!isAuthenticated() || !currentUserCanManageUsers())
        return false;

    for (auto& user : users) {
        if (user.getUsername() == oldUsername) {
            user = User(newUsername, newPassword, newRole);
            if (currentUser->getUsername() == oldUsername) {
                currentUser = &user;
            }
            emit userChanged();
            return true;
        }
    }
}

bool InventorySystem::addItem(const Item &item) {
    if (!isAuthenticated() || !currentUserCanEditInventory())
        return false;

    bool result = inventory.addItem(item);
    if (result) {
        operations.addRecord(item, currentUser->getUsername(),
                            QDateTime::currentDateTime(),
                            "Added Item");
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
        emit inventoryChanged();
    }

    return result;
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

bool InventorySystem::openReportFile() {
    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString reportPath = dataDir + QDir::separator() + "inventory_report.txt";

    QFileInfo fileInfo(reportPath);
    if (!fileInfo.exists()) {
        return false;
    }

    // Open the file with the system's default application
    return QDesktopServices::openUrl(QUrl::fromLocalFile(reportPath));
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

const Inventory& InventorySystem::getInventory() const
{
    return inventory;
}

