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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editRoleform
{
public:
    QComboBox *comboBox_editRole;
    QLabel *usernameLabel;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *editRoleform)
    {
        if (editRoleform->objectName().isEmpty())
            editRoleform->setObjectName("editRoleform");
        editRoleform->resize(331, 213);
        comboBox_editRole = new QComboBox(editRoleform);
        comboBox_editRole->addItem(QString());
        comboBox_editRole->setObjectName("comboBox_editRole");
        comboBox_editRole->setGeometry(QRect(110, 80, 82, 28));
        usernameLabel = new QLabel(editRoleform);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setGeometry(QRect(20, 30, 91, 21));
        pushButton_OK = new QPushButton(editRoleform);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(170, 130, 83, 29));

        retranslateUi(editRoleform);

        QMetaObject::connectSlotsByName(editRoleform);
    } // setupUi

    void retranslateUi(QDialog *editRoleform)
    {
        editRoleform->setWindowTitle(QCoreApplication::translate("editRoleform", "Dialog", nullptr));
        comboBox_editRole->setItemText(0, QString());

        usernameLabel->setText(QCoreApplication::translate("editRoleform", "username", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("editRoleform", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editRoleform: public Ui_editRoleform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROLEFORM_H
