/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *goBackPushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *filtersComboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addnewUserPushButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QTableWidget *userDisplayTable;

    void setupUi(QDialog *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName("AdminForm");
        AdminForm->resize(770, 650);
        verticalLayoutWidget = new QWidget(AdminForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(29, 39, 701, 561));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        goBackPushButton = new QPushButton(verticalLayoutWidget);
        goBackPushButton->setObjectName("goBackPushButton");
        goBackPushButton->setMinimumSize(QSize(75, 75));

        horizontalLayout_3->addWidget(goBackPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        filtersComboBox = new QComboBox(verticalLayoutWidget);
        filtersComboBox->setObjectName("filtersComboBox");

        horizontalLayout_2->addWidget(filtersComboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        addnewUserPushButton = new QPushButton(verticalLayoutWidget);
        addnewUserPushButton->setObjectName("addnewUserPushButton");
        addnewUserPushButton->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(addnewUserPushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        userDisplayTable = new QTableWidget(verticalLayoutWidget);
        userDisplayTable->setObjectName("userDisplayTable");

        horizontalLayout->addWidget(userDisplayTable);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdminForm);

        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QDialog *AdminForm)
    {
        AdminForm->setWindowTitle(QCoreApplication::translate("AdminForm", "Dialog", nullptr));
        goBackPushButton->setText(QCoreApplication::translate("AdminForm", "Go Back", nullptr));
        label->setText(QCoreApplication::translate("AdminForm", "Filters: ", nullptr));
        addnewUserPushButton->setText(QCoreApplication::translate("AdminForm", "Add new User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
