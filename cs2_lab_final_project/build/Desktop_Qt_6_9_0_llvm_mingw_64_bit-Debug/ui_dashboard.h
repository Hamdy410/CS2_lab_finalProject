/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QPushButton *pushButton_Report;
    QLabel *label_BestSeller;
    QLabel *label_lowesrSeller;
    QLabel *label_LowStock;
    QLabel *label_BestSellerSold;
    QLabel *label_LowestSellerSold;
    QLabel *label_OnlyLeft;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(400, 300);
        pushButton_Report = new QPushButton(Dashboard);
        pushButton_Report->setObjectName("pushButton_Report");
        pushButton_Report->setGeometry(QRect(20, 230, 101, 29));
        label_BestSeller = new QLabel(Dashboard);
        label_BestSeller->setObjectName("label_BestSeller");
        label_BestSeller->setGeometry(QRect(30, 20, 181, 31));
        label_lowesrSeller = new QLabel(Dashboard);
        label_lowesrSeller->setObjectName("label_lowesrSeller");
        label_lowesrSeller->setGeometry(QRect(30, 90, 221, 31));
        label_LowStock = new QLabel(Dashboard);
        label_LowStock->setObjectName("label_LowStock");
        label_LowStock->setGeometry(QRect(30, 160, 251, 31));
        label_BestSellerSold = new QLabel(Dashboard);
        label_BestSellerSold->setObjectName("label_BestSellerSold");
        label_BestSellerSold->setGeometry(QRect(30, 50, 171, 31));
        label_LowestSellerSold = new QLabel(Dashboard);
        label_LowestSellerSold->setObjectName("label_LowestSellerSold");
        label_LowestSellerSold->setGeometry(QRect(30, 120, 171, 31));
        label_OnlyLeft = new QLabel(Dashboard);
        label_OnlyLeft->setObjectName("label_OnlyLeft");
        label_OnlyLeft->setGeometry(QRect(30, 190, 171, 31));

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dialog", nullptr));
        pushButton_Report->setText(QCoreApplication::translate("Dashboard", "Generate report", nullptr));
        label_BestSeller->setText(QCoreApplication::translate("Dashboard", "BestSeller:", nullptr));
        label_lowesrSeller->setText(QCoreApplication::translate("Dashboard", "Lowest Seller: ", nullptr));
        label_LowStock->setText(QCoreApplication::translate("Dashboard", "Low Stock: ", nullptr));
        label_BestSellerSold->setText(QCoreApplication::translate("Dashboard", "Sold: ", nullptr));
        label_LowestSellerSold->setText(QCoreApplication::translate("Dashboard", "Sold: ", nullptr));
        label_OnlyLeft->setText(QCoreApplication::translate("Dashboard", "Only left: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
