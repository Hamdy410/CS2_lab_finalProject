#include "mainwindow.h"
#include "inventorysystem.h"
#include "loginform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    InventorySystem* inventorySystem = new InventorySystem();
    LoginForm w(inventorySystem);
    w.show();
    return a.exec();
}
