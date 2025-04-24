#include "mainwindow.h"
#include "inventorysystem.h"
#include "loginform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    InventorySystem* inventorySystem = new InventorySystem(nullptr, ":db/db/users.csv",
                                                           ":db/db/inventory.csv",
                                                           ":db/dboperations.csv");
    LoginForm w(inventorySystem);
    w.show();
    return a.exec();
}
