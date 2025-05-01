#include "mainwindow.h"
#include "inventorysystem.h"
#include "loginform.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>

/*
 * Important Notice:
 *      Data files (.csv) are created inside the Users folders.
 *      Typically, in windows:
 *          C:\Users\<username>\AppData\Roaming\CS2_Team\Inventory_System_Manager
 *      Right now, you will find two files:
 *          items.csv
 *          users.csv
 *
 *      Operations Logic have been handled, but its file has not been impelemented
 *      as for now.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("CS2_Team");
    QCoreApplication::setApplicationName("Inventory_System_Manager");

    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (!QDir().mkpath(dataDir)) {
        qDebug() << "Failed to create director:" << dataDir;
        return a.exec();
    }
    QString usersPath = dataDir + QDir::separator() + "users.csv";
    QString inventoryPath = dataDir + QDir::separator() + "inventory.csv";
    QString operationsPath = dataDir + QDir::separator() + "operations.csv";

    qDebug() << "Users CSV at: " << usersPath;
    qDebug() << "Inventory CSV at: " << inventoryPath;
    qDebug() << "Qoperations CSV at: " << operationsPath;

    InventorySystem* inventorySystem = new InventorySystem(nullptr, usersPath,
                                                           inventoryPath,
                                                           operationsPath);
    qDebug() << "Saving users to:" << usersPath;
    LoginForm w(inventorySystem);
    w.show();

    return a.exec();
}
