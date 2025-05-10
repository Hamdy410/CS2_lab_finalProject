/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QLabel *label_Login;
    QLabel *label_Username;
    QLabel *label_Password;
    QLineEdit *lineEdit_Username;
    QLineEdit *lineEdit_Password;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_Theme;

    void setupUi(QDialog *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName("LoginForm");
        LoginForm->resize(427, 338);
        label_Login = new QLabel(LoginForm);
        label_Login->setObjectName("label_Login");
        label_Login->setGeometry(QRect(150, 50, 101, 41));
        label_Username = new QLabel(LoginForm);
        label_Username->setObjectName("label_Username");
        label_Username->setGeometry(QRect(60, 90, 81, 41));
        label_Password = new QLabel(LoginForm);
        label_Password->setObjectName("label_Password");
        label_Password->setGeometry(QRect(60, 150, 81, 41));
        lineEdit_Username = new QLineEdit(LoginForm);
        lineEdit_Username->setObjectName("lineEdit_Username");
        lineEdit_Username->setGeometry(QRect(120, 100, 201, 28));
        lineEdit_Password = new QLineEdit(LoginForm);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setGeometry(QRect(120, 160, 201, 28));
        lineEdit_Password->setEchoMode(QLineEdit::EchoMode::Password);
        pushButton_Login = new QPushButton(LoginForm);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(270, 200, 91, 31));
        pushButton_Theme = new QPushButton(LoginForm);
        pushButton_Theme->setObjectName("pushButton_Theme");
        pushButton_Theme->setGeometry(QRect(290, 30, 41, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/sun_15195263.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_Theme->setIcon(icon);
        pushButton_Theme->setIconSize(QSize(30, 30));

        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QDialog *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Dialog", nullptr));
        label_Login->setText(QCoreApplication::translate("LoginForm", "Login:", nullptr));
        label_Username->setText(QCoreApplication::translate("LoginForm", "Username:", nullptr));
        label_Password->setText(QCoreApplication::translate("LoginForm", "Password:", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("LoginForm", "Login", nullptr));
        pushButton_Theme->setText(QCoreApplication::translate("LoginForm", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
