/********************************************************************************
** Form generated from reading UI file 'signupform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPFORM_H
#define UI_SIGNUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignUpForm
{
public:
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditReenterPassword;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButtonSignUp;

    void setupUi(QDialog *SignUpForm)
    {
        if (SignUpForm->objectName().isEmpty())
            SignUpForm->setObjectName("SignUpForm");
        SignUpForm->resize(400, 300);
        lineEditUsername = new QLineEdit(SignUpForm);
        lineEditUsername->setObjectName("lineEditUsername");
        lineEditUsername->setGeometry(QRect(220, 70, 101, 20));
        lineEditPassword = new QLineEdit(SignUpForm);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(220, 110, 101, 20));
        lineEditReenterPassword = new QLineEdit(SignUpForm);
        lineEditReenterPassword->setObjectName("lineEditReenterPassword");
        lineEditReenterPassword->setGeometry(QRect(220, 150, 101, 20));
        label = new QLabel(SignUpForm);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 70, 71, 20));
        label_2 = new QLabel(SignUpForm);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 110, 71, 20));
        label_3 = new QLabel(SignUpForm);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 150, 131, 20));
        label_4 = new QLabel(SignUpForm);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 20, 131, 20));
        pushButtonSignUp = new QPushButton(SignUpForm);
        pushButtonSignUp->setObjectName("pushButtonSignUp");
        pushButtonSignUp->setGeometry(QRect(150, 200, 83, 29));

        retranslateUi(SignUpForm);

        QMetaObject::connectSlotsByName(SignUpForm);
    } // setupUi

    void retranslateUi(QDialog *SignUpForm)
    {
        SignUpForm->setWindowTitle(QCoreApplication::translate("SignUpForm", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SignUpForm", "Username:", nullptr));
        label_2->setText(QCoreApplication::translate("SignUpForm", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("SignUpForm", "Re-enter Password:", nullptr));
        label_4->setText(QCoreApplication::translate("SignUpForm", "Create an Account!", nullptr));
        pushButtonSignUp->setText(QCoreApplication::translate("SignUpForm", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpForm: public Ui_SignUpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPFORM_H
