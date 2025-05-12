/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QPushButton *pushButton_Report;
    QLabel *label_BestSeller;
    QLabel *label_lowesrSeller;
    QLabel *label_LowStock;
    QPushButton *goBackPushButton;
    QLabel *label;
    QTextEdit *lowStock_textEdit;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName("Dashboard");
        Dashboard->resize(537, 455);
        pushButton_Report = new QPushButton(Dashboard);
        pushButton_Report->setObjectName("pushButton_Report");
        pushButton_Report->setGeometry(QRect(90, 320, 101, 29));
        label_BestSeller = new QLabel(Dashboard);
        label_BestSeller->setObjectName("label_BestSeller");
        label_BestSeller->setGeometry(QRect(100, 110, 181, 31));
        label_lowesrSeller = new QLabel(Dashboard);
        label_lowesrSeller->setObjectName("label_lowesrSeller");
        label_lowesrSeller->setGeometry(QRect(100, 140, 221, 31));
        label_LowStock = new QLabel(Dashboard);
        label_LowStock->setObjectName("label_LowStock");
        label_LowStock->setGeometry(QRect(100, 180, 251, 31));
        goBackPushButton = new QPushButton(Dashboard);
        goBackPushButton->setObjectName("goBackPushButton");
        goBackPushButton->setGeometry(QRect(20, 20, 81, 65));
        goBackPushButton->setMinimumSize(QSize(65, 65));
        label = new QLabel(Dashboard);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 121, 61));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lowStock_textEdit = new QTextEdit(Dashboard);
        lowStock_textEdit->setObjectName("lowStock_textEdit");
        lowStock_textEdit->setGeometry(QRect(240, 210, 161, 91));

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
        goBackPushButton->setText(QCoreApplication::translate("Dashboard", "Go Back", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "Welcome!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
