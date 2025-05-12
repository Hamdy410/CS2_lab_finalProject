/********************************************************************************
** Form generated from reading UI file 'logs.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGS_H
#define UI_LOGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Logs
{
public:
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *Logs)
    {
        if (Logs->objectName().isEmpty())
            Logs->setObjectName("Logs");
        Logs->resize(400, 300);
        textEdit = new QTextEdit(Logs);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(70, 50, 261, 211));
        label = new QLabel(Logs);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 10, 63, 20));

        retranslateUi(Logs);

        QMetaObject::connectSlotsByName(Logs);
    } // setupUi

    void retranslateUi(QDialog *Logs)
    {
        Logs->setWindowTitle(QCoreApplication::translate("Logs", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Logs", "Logs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logs: public Ui_Logs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGS_H
