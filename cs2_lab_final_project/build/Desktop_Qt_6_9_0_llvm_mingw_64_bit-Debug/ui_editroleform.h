/********************************************************************************
** Form generated from reading UI file 'editroleform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROLEFORM_H
#define UI_EDITROLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editRoleform
{
public:
    QLabel *usernameLabel;
    QPushButton *pushButton_OK;
    QLabel *label_passwordWarning;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_newUsername;
    QLabel *label_newPassword;
    QLabel *label_newRole;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QComboBox *comboBox_editRole;

    void setupUi(QDialog *editRoleform)
    {
        if (editRoleform->objectName().isEmpty())
            editRoleform->setObjectName("editRoleform");
        editRoleform->resize(331, 213);
        usernameLabel = new QLabel(editRoleform);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(20, 20, 91, 21));
        pushButton_OK = new QPushButton(editRoleform);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(230, 150, 83, 29));
        label_passwordWarning = new QLabel(editRoleform);
        label_passwordWarning->setObjectName("label_passwordWarning");
        label_passwordWarning->setGeometry(QRect(30, 140, 181, 51));
        label_passwordWarning->setWordWrap(true);
        layoutWidget = new QWidget(editRoleform);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 50, 84, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_newUsername = new QLabel(layoutWidget);
        label_newUsername->setObjectName("label_newUsername");

        verticalLayout->addWidget(label_newUsername);

        label_newPassword = new QLabel(layoutWidget);
        label_newPassword->setObjectName("label_newPassword");

        verticalLayout->addWidget(label_newPassword);

        label_newRole = new QLabel(layoutWidget);
        label_newRole->setObjectName("label_newRole");

        verticalLayout->addWidget(label_newRole);

        layoutWidget1 = new QWidget(editRoleform);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(170, 50, 111, 88));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(layoutWidget1);
        lineEdit_username->setObjectName("lineEdit_username");

        verticalLayout_2->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(layoutWidget1);
        lineEdit_password->setObjectName("lineEdit_password");

        verticalLayout_2->addWidget(lineEdit_password);

        comboBox_editRole = new QComboBox(layoutWidget1);
        comboBox_editRole->addItem(QString());
        comboBox_editRole->setObjectName("comboBox_editRole");

        verticalLayout_2->addWidget(comboBox_editRole);


        retranslateUi(editRoleform);

        QMetaObject::connectSlotsByName(editRoleform);
    } // setupUi

    void retranslateUi(QDialog *editRoleform)
    {
        editRoleform->setWindowTitle(QCoreApplication::translate("editRoleform", "Dialog", nullptr));
        usernameLabel->setText(QCoreApplication::translate("editRoleform", "username", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("editRoleform", "OK", nullptr));
        label_passwordWarning->setText(QCoreApplication::translate("editRoleform", "Password should include at least one uppercase, one lowercase character and one number.", nullptr));
        label_newUsername->setText(QCoreApplication::translate("editRoleform", "New username:", nullptr));
        label_newPassword->setText(QCoreApplication::translate("editRoleform", "New password:", nullptr));
        label_newRole->setText(QCoreApplication::translate("editRoleform", "New role: ", nullptr));
        comboBox_editRole->setItemText(0, QString());

    } // retranslateUi

};

namespace Ui {
    class editRoleform: public Ui_editRoleform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROLEFORM_H
