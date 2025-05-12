/********************************************************************************
** Form generated from reading UI file 'systemui.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMUI_H
#define UI_SYSTEMUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemUI
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *welcomeLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Theme;
    QPushButton *signoutPushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *dashboardButton;
    QPushButton *adminPageButton;
    QPushButton *inventoryManagerButton;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *SystemUI)
    {
        if (SystemUI->objectName().isEmpty())
            SystemUI->setObjectName("SystemUI");
        SystemUI->resize(673, 515);
        verticalLayoutWidget = new QWidget(SystemUI);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 671, 511));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 32, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        welcomeLabel = new QLabel(verticalLayoutWidget);
        welcomeLabel->setObjectName("welcomeLabel");

        horizontalLayout_5->addWidget(welcomeLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_Theme = new QPushButton(verticalLayoutWidget);
        pushButton_Theme->setObjectName("pushButton_Theme");
        pushButton_Theme->setMinimumSize(QSize(40, 75));
        pushButton_Theme->setIconSize(QSize(30, 30));

        horizontalLayout_5->addWidget(pushButton_Theme);

        signoutPushButton = new QPushButton(verticalLayoutWidget);
        signoutPushButton->setObjectName("signoutPushButton");
        signoutPushButton->setMinimumSize(QSize(75, 75));

        horizontalLayout_5->addWidget(signoutPushButton);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(5, 23, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        dashboardButton = new QPushButton(verticalLayoutWidget);
        dashboardButton->setObjectName("dashboardButton");
        dashboardButton->setMinimumSize(QSize(190, 190));

        horizontalLayout_2->addWidget(dashboardButton);

        adminPageButton = new QPushButton(verticalLayoutWidget);
        adminPageButton->setObjectName("adminPageButton");
        adminPageButton->setMinimumSize(QSize(190, 190));

        horizontalLayout_2->addWidget(adminPageButton);

        inventoryManagerButton = new QPushButton(verticalLayoutWidget);
        inventoryManagerButton->setObjectName("inventoryManagerButton");
        inventoryManagerButton->setMinimumSize(QSize(190, 190));

        horizontalLayout_2->addWidget(inventoryManagerButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SystemUI);

        QMetaObject::connectSlotsByName(SystemUI);
    } // setupUi

    void retranslateUi(QDialog *SystemUI)
    {
        SystemUI->setWindowTitle(QCoreApplication::translate("SystemUI", "Dialog", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("SystemUI", "Welcome, username", nullptr));
        pushButton_Theme->setText(QCoreApplication::translate("SystemUI", "PushButton", nullptr));
        signoutPushButton->setText(QCoreApplication::translate("SystemUI", "Sign Out", nullptr));
        dashboardButton->setText(QCoreApplication::translate("SystemUI", "Dashboard", nullptr));
        adminPageButton->setText(QCoreApplication::translate("SystemUI", "Admin Page", nullptr));
        inventoryManagerButton->setText(QCoreApplication::translate("SystemUI", "Inventory Manager", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemUI: public Ui_SystemUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMUI_H
