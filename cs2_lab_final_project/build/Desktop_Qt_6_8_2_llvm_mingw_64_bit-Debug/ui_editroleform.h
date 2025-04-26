/********************************************************************************
** Form generated from reading UI file 'editroleform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITROLEFORM_H
#define UI_EDITROLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_editRoleform
{
public:
    QComboBox *comboBox_editRole;

    void setupUi(QDialog *editRoleform)
    {
        if (editRoleform->objectName().isEmpty())
            editRoleform->setObjectName("editRoleform");
        editRoleform->resize(331, 213);
        comboBox_editRole = new QComboBox(editRoleform);
        comboBox_editRole->addItem(QString());
        comboBox_editRole->addItem(QString());
        comboBox_editRole->addItem(QString());
        comboBox_editRole->addItem(QString());
        comboBox_editRole->setObjectName("comboBox_editRole");
        comboBox_editRole->setGeometry(QRect(110, 80, 82, 28));

        retranslateUi(editRoleform);

        QMetaObject::connectSlotsByName(editRoleform);
    } // setupUi

    void retranslateUi(QDialog *editRoleform)
    {
        editRoleform->setWindowTitle(QCoreApplication::translate("editRoleform", "Dialog", nullptr));
        comboBox_editRole->setItemText(0, QString());
        comboBox_editRole->setItemText(1, QCoreApplication::translate("editRoleform", "Admin", nullptr));
        comboBox_editRole->setItemText(2, QCoreApplication::translate("editRoleform", "Manager", nullptr));
        comboBox_editRole->setItemText(3, QCoreApplication::translate("editRoleform", "Staff", nullptr));

    } // retranslateUi

};

namespace Ui {
    class editRoleform: public Ui_editRoleform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITROLEFORM_H
