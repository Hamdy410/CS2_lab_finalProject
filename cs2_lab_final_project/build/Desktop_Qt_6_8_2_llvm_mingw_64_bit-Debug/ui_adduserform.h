/********************************************************************************
** Form generated from reading UI file 'adduserform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERFORM_H
#define UI_ADDUSERFORM_H

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

class Ui_AddUserForm
{
public:
    QPushButton *pushButton_OK;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Username;
    QLabel *label_Password;
    QLabel *label_Role;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Username;
    QLineEdit *lineEdit_Password;
    QComboBox *comboBox_Role;

    void setupUi(QDialog *AddUserForm)
    {
        if (AddUserForm->objectName().isEmpty())
            AddUserForm->setObjectName("AddUserForm");
        AddUserForm->resize(431, 314);
        pushButton_OK = new QPushButton(AddUserForm);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(290, 230, 91, 41));
        widget = new QWidget(AddUserForm);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 80, 111, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Username = new QLabel(widget);
        label_Username->setObjectName("label_Username");

        verticalLayout->addWidget(label_Username);

        label_Password = new QLabel(widget);
        label_Password->setObjectName("label_Password");

        verticalLayout->addWidget(label_Password);

        label_Role = new QLabel(widget);
        label_Role->setObjectName("label_Role");

        verticalLayout->addWidget(label_Role);

        widget1 = new QWidget(AddUserForm);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(170, 70, 191, 161));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_Username = new QLineEdit(widget1);
        lineEdit_Username->setObjectName("lineEdit_Username");

        verticalLayout_2->addWidget(lineEdit_Username);

        lineEdit_Password = new QLineEdit(widget1);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineEdit_Password);

        comboBox_Role = new QComboBox(widget1);
        comboBox_Role->setObjectName("comboBox_Role");

        verticalLayout_2->addWidget(comboBox_Role);


        retranslateUi(AddUserForm);

        QMetaObject::connectSlotsByName(AddUserForm);
    } // setupUi

    void retranslateUi(QDialog *AddUserForm)
    {
        AddUserForm->setWindowTitle(QCoreApplication::translate("AddUserForm", "Dialog", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("AddUserForm", "OK", nullptr));
        label_Username->setText(QCoreApplication::translate("AddUserForm", "Username:", nullptr));
        label_Password->setText(QCoreApplication::translate("AddUserForm", "Password:", nullptr));
        label_Role->setText(QCoreApplication::translate("AddUserForm", "Role", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserForm: public Ui_AddUserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERFORM_H
