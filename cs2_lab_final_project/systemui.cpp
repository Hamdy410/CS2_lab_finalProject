#include "systemui.h"
#include "ui_systemui.h"
#include "user.h"

#include <QFont>
#include <QString>
#include <QDebug>

SystemUI::SystemUI(QWidget *parent, InventorySystem* inventorySystem)
    : QDialog(parent)
    , ui(new Ui::SystemUI)
    , inventorySystem(inventorySystem)
{
    ui->setupUi(this);
    ui->welcomeLabel->setText("Welcome, " + inventorySystem->getCurrentUsername());

    QFont font;
    font.setFamily("Cursive");
    font.setPointSize(24);
    font.setBold(true);
    font.setWeight(QFont::Black);
    ui->welcomeLabel->setFont(font);

    if (!inventorySystem->getCurrentUser()->canManageUsers())
    {
        ui->adminPageButton->hide();
        qDebug() << "You can not access admin page";
    }

    if (!inventorySystem->getCurrentUser()->canEditInventory())
    {
        ui->inventoryManagerButton->hide();
        qDebug() << "You can not access inventory";
    }
}

SystemUI::~SystemUI()
{
    delete inventorySystem;
    delete ui;
}

void SystemUI::on_signoutPushButton_clicked()
{
    qDebug() << "This is signout";
    this->parentWidget()->show();
    this->close();
}


void SystemUI::on_dashboardButton_clicked()
{
    qDebug() << "This is dashboard";
}


void SystemUI::on_adminPageButton_clicked()
{
    qDebug() << "This is the admin page";
}


void SystemUI::on_inventoryManagerButton_clicked()
{
    qDebug() << "This is inventory manager";
}

