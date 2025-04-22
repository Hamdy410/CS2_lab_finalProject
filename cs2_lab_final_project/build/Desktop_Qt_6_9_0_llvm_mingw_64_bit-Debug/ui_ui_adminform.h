/********************************************************************************
** Form generated from reading UI file 'ui_adminform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_ADMINFORM_H
#define UI_UI_ADMINFORM_H

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

class Ui_Ui_AdminForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *filterSection;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *roleFilterComboBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *addUserButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *tableSection;
    QTableWidget *userTableWidget;

    void setupUi(QDialog *Ui_AdminForm)
    {
        if (Ui_AdminForm->objectName().isEmpty())
            Ui_AdminForm->setObjectName("Ui_AdminForm");
        Ui_AdminForm->resize(1097, 573);
        verticalLayoutWidget = new QWidget(Ui_AdminForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(39, 39, 1011, 491));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        filterSection = new QHBoxLayout();
        filterSection->setObjectName("filterSection");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        filterSection->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        filterSection->addItem(horizontalSpacer_2);

        roleFilterComboBox = new QComboBox(verticalLayoutWidget);
        roleFilterComboBox->setObjectName("roleFilterComboBox");

        filterSection->addWidget(roleFilterComboBox);

        horizontalSpacer = new QSpacerItem(24, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        filterSection->addItem(horizontalSpacer);

        addUserButton = new QPushButton(verticalLayoutWidget);
        addUserButton->setObjectName("addUserButton");

        filterSection->addWidget(addUserButton);

        horizontalSpacer_3 = new QSpacerItem(65, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        filterSection->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(filterSection);

        tableSection = new QHBoxLayout();
        tableSection->setObjectName("tableSection");
        tableSection->setContentsMargins(-1, 0, -1, -1);
        userTableWidget = new QTableWidget(verticalLayoutWidget);
        userTableWidget->setObjectName("userTableWidget");

        tableSection->addWidget(userTableWidget);


        verticalLayout_2->addLayout(tableSection);


        retranslateUi(Ui_AdminForm);

        QMetaObject::connectSlotsByName(Ui_AdminForm);
    } // setupUi

    void retranslateUi(QDialog *Ui_AdminForm)
    {
        Ui_AdminForm->setWindowTitle(QCoreApplication::translate("Ui_AdminForm", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ui_AdminForm", "Filter by role::", nullptr));
        addUserButton->setText(QCoreApplication::translate("Ui_AdminForm", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_AdminForm: public Ui_Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_ADMINFORM_H
