/********************************************************************************
** Form generated from reading UI file 'ui_edituserdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_EDITUSERDIALOG_H
#define UI_UI_EDITUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Ui_EditUserDialog
{
public:

    void setupUi(QDialog *Ui_EditUserDialog)
    {
        if (Ui_EditUserDialog->objectName().isEmpty())
            Ui_EditUserDialog->setObjectName("Ui_EditUserDialog");
        Ui_EditUserDialog->resize(400, 300);

        retranslateUi(Ui_EditUserDialog);

        QMetaObject::connectSlotsByName(Ui_EditUserDialog);
    } // setupUi

    void retranslateUi(QDialog *Ui_EditUserDialog)
    {
        Ui_EditUserDialog->setWindowTitle(QCoreApplication::translate("Ui_EditUserDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ui_EditUserDialog: public Ui_Ui_EditUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_EDITUSERDIALOG_H
