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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Username;
    QLabel *label_Password;
    QLabel *label_Role;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Username;
    QLineEdit *lineEdit_Password;
    QComboBox *comboBox_Role;
    QLabel *label_password_warning;

    void setupUi(QDialog *AddUserForm)
    {
        if (AddUserForm->objectName().isEmpty())
            AddUserForm->setObjectName("AddUserForm");
        AddUserForm->resize(431, 314);
        pushButton_OK = new QPushButton(AddUserForm);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(290, 230, 91, 41));
        layoutWidget = new QWidget(AddUserForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 70, 111, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Username = new QLabel(layoutWidget);
        label_Username->setObjectName("label_Username");

        verticalLayout->addWidget(label_Username);

        label_Password = new QLabel(layoutWidget);
        label_Password->setObjectName("label_Password");

        verticalLayout->addWidget(label_Password);

        label_Role = new QLabel(layoutWidget);
        label_Role->setObjectName("label_Role");

        verticalLayout->addWidget(label_Role);

        layoutWidget1 = new QWidget(AddUserForm);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(150, 60, 181, 171));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_Username = new QLineEdit(layoutWidget1);
        lineEdit_Username->setObjectName("lineEdit_Username");

        verticalLayout_2->addWidget(lineEdit_Username);

        lineEdit_Password = new QLineEdit(layoutWidget1);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineEdit_Password);

        comboBox_Role = new QComboBox(layoutWidget1);
        comboBox_Role->setObjectName("comboBox_Role");

        verticalLayout_2->addWidget(comboBox_Role);

        label_password_warning = new QLabel(AddUserForm);
        label_password_warning->setObjectName("label_password_warning");
        label_password_warning->setGeometry(QRect(30, 230, 251, 51));
        label_password_warning->setWordWrap(true);

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
        label_password_warning->setText(QCoreApplication::translate("AddUserForm", "Password should include atleast one uppercase and one lowercase character.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserForm: public Ui_AddUserForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERFORM_H
