/********************************************************************************
** Form generated from reading UI file 'ui_adduserdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_ADDUSERDIALOG_H
#define UI_UI_ADDUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ui_AddUserDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *usernameSection;
    QSpacerItem *horizontalSpacer_3;
    QLabel *usernameLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *usernameLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *passwordSection;
    QSpacerItem *horizontalSpacer_4;
    QLabel *passwordLabel;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *passwordLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *confirmPasswordSection;
    QSpacerItem *horizontalSpacer_7;
    QLabel *confirlmPasswordLabel;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *confirmPasswordLineEdit;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *roleSection;
    QSpacerItem *horizontalSpacer_10;
    QLabel *roleLabel;
    QSpacerItem *horizontalSpacer_11;
    QComboBox *roleComboBox;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_13;
    QDialogButtonBox *ButtonBox;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Ui_AddUserDialog)
    {
        if (Ui_AddUserDialog->objectName().isEmpty())
            Ui_AddUserDialog->setObjectName("Ui_AddUserDialog");
        Ui_AddUserDialog->resize(651, 425);
        verticalLayoutWidget = new QWidget(Ui_AddUserDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(49, 39, 551, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        usernameSection = new QHBoxLayout();
        usernameSection->setObjectName("usernameSection");
        horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        usernameSection->addItem(horizontalSpacer_3);

        usernameLabel = new QLabel(verticalLayoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        usernameSection->addWidget(usernameLabel);

        horizontalSpacer = new QSpacerItem(76, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        usernameSection->addItem(horizontalSpacer);

        usernameLineEdit = new QLineEdit(verticalLayoutWidget);
        usernameLineEdit->setObjectName("usernameLineEdit");

        usernameSection->addWidget(usernameLineEdit);

        horizontalSpacer_2 = new QSpacerItem(233, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        usernameSection->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(usernameSection);

        passwordSection = new QHBoxLayout();
        passwordSection->setObjectName("passwordSection");
        horizontalSpacer_4 = new QSpacerItem(53, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        passwordSection->addItem(horizontalSpacer_4);

        passwordLabel = new QLabel(verticalLayoutWidget);
        passwordLabel->setObjectName("passwordLabel");

        passwordSection->addWidget(passwordLabel);

        horizontalSpacer_5 = new QSpacerItem(90, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        passwordSection->addItem(horizontalSpacer_5);

        passwordLineEdit = new QLineEdit(verticalLayoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");

        passwordSection->addWidget(passwordLineEdit);

        horizontalSpacer_6 = new QSpacerItem(241, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        passwordSection->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(passwordSection);

        confirmPasswordSection = new QHBoxLayout();
        confirmPasswordSection->setObjectName("confirmPasswordSection");
        horizontalSpacer_7 = new QSpacerItem(56, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        confirmPasswordSection->addItem(horizontalSpacer_7);

        confirlmPasswordLabel = new QLabel(verticalLayoutWidget);
        confirlmPasswordLabel->setObjectName("confirlmPasswordLabel");

        confirmPasswordSection->addWidget(confirlmPasswordLabel);

        horizontalSpacer_8 = new QSpacerItem(46, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        confirmPasswordSection->addItem(horizontalSpacer_8);

        confirmPasswordLineEdit = new QLineEdit(verticalLayoutWidget);
        confirmPasswordLineEdit->setObjectName("confirmPasswordLineEdit");

        confirmPasswordSection->addWidget(confirmPasswordLineEdit);

        horizontalSpacer_9 = new QSpacerItem(253, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        confirmPasswordSection->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(confirmPasswordSection);

        roleSection = new QHBoxLayout();
        roleSection->setObjectName("roleSection");
        horizontalSpacer_10 = new QSpacerItem(30, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        roleSection->addItem(horizontalSpacer_10);

        roleLabel = new QLabel(verticalLayoutWidget);
        roleLabel->setObjectName("roleLabel");

        roleSection->addWidget(roleLabel);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        roleSection->addItem(horizontalSpacer_11);

        roleComboBox = new QComboBox(verticalLayoutWidget);
        roleComboBox->setObjectName("roleComboBox");

        roleSection->addWidget(roleComboBox);

        horizontalSpacer_12 = new QSpacerItem(274, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        roleSection->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(roleSection);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_13);

        ButtonBox = new QDialogButtonBox(verticalLayoutWidget);
        ButtonBox->setObjectName("ButtonBox");
        ButtonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        horizontalLayout->addWidget(ButtonBox);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Ui_AddUserDialog);

        QMetaObject::connectSlotsByName(Ui_AddUserDialog);
    } // setupUi

    void retranslateUi(QDialog *Ui_AddUserDialog)
    {
        Ui_AddUserDialog->setWindowTitle(QCoreApplication::translate("Ui_AddUserDialog", "Dialog", nullptr));
        usernameLabel->setText(QCoreApplication::translate("Ui_AddUserDialog", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Ui_AddUserDialog", "Password:", nullptr));
        confirlmPasswordLabel->setText(QCoreApplication::translate("Ui_AddUserDialog", "Confirm Password:", nullptr));
        roleLabel->setText(QCoreApplication::translate("Ui_AddUserDialog", "Role:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_AddUserDialog: public Ui_Ui_AddUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_ADDUSERDIALOG_H
