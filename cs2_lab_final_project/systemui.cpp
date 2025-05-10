#include "systemui.h"
#include "ui_systemui.h"
#include "user.h"
#include "adminform.h"
#include "dashboard.h"
#include "inventoryform.h"
#include "loginform.h"

#include <QFont>
#include <QString>
#include <QDebug>
#include <QCloseEvent>

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

    darkStyle = R"(
    QWidget { background-color: #121212; color: #E0E0E0; }
    QPushButton { background-color: #1F1F1F; color: #E0E0E0; }
    QLineEdit { background-color: #1F1F1F; color: #E0E0E0; }
    )";

    lightStyle = R"(
    QWidget { background-color: #FFFFFF; color: #000000; }
    QPushButton { background-color: #F0F0F0; color: #000000; }
    QLineEdit { background-color: #FFFFFF; color: #000000; }
    )";
    ui->pushButton_Theme->setText("");
    ui->pushButton_Theme->setIcon(QIcon(LoginForm::isDarkMode ? ":/icons/sun_15195263.png" : ":/icons/moon_4867888.png"));
}

SystemUI::~SystemUI()
{
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
    Dashboard* dashboard = new Dashboard(inventorySystem, this);
    dashboard->show();

    this->hide();
}


void SystemUI::on_adminPageButton_clicked()
{
    qDebug() << "Admin Page is clicked";
    AdminForm* adminForm = new AdminForm(this, inventorySystem);
    adminForm->show();

    this->hide();
}


void SystemUI::on_inventoryManagerButton_clicked()
{
    qDebug() << "This is inventory manager";
    InventoryForm* inventoryManager = new InventoryForm(inventorySystem, this);
    inventoryManager->show();
}

void SystemUI::closeEvent(QCloseEvent *event) {
    this->parentWidget()->show();
    this->close();
    event->accept();
}


void SystemUI::on_pushButton_Theme_clicked()
{
    LoginForm::isDarkMode = !LoginForm::isDarkMode;
    qApp->setStyleSheet(LoginForm::isDarkMode ? darkStyle : lightStyle);
    ui->pushButton_Theme->setIcon(QIcon(LoginForm::isDarkMode ? ":/icons/sun_15195263.png" : ":/icons/moon_4867888.png"));
}

