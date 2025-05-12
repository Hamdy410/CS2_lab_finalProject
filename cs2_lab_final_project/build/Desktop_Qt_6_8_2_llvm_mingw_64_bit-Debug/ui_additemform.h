/********************************************************************************
** Form generated from reading UI file 'additemform.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMFORM_H
#define UI_ADDITEMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItemForm
{
public:
    QLabel *label_4;
    QLabel *label_11;
    QPushButton *pushButtonSelectPhoto;
    QPushButton *pushButtonAdd;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEditAddName;
    QLabel *label_6;
    QLineEdit *lineEditAddQuantity;
    QLabel *label_7;
    QLineEdit *lineEditAddCategory;
    QLabel *label_8;
    QLineEdit *lineEditAddPrice;
    QLabel *label_9;
    QLineEdit *lineEditAddSupplier;

    void setupUi(QDialog *AddItemForm)
    {
        if (AddItemForm->objectName().isEmpty())
            AddItemForm->setObjectName("AddItemForm");
        AddItemForm->resize(1158, 646);
        label_4 = new QLabel(AddItemForm);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(530, 190, 51, 41));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);
        label_11 = new QLabel(AddItemForm);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(200, 440, 251, 41));
        pushButtonSelectPhoto = new QPushButton(AddItemForm);
        pushButtonSelectPhoto->setObjectName("pushButtonSelectPhoto");
        pushButtonSelectPhoto->setGeometry(QRect(470, 450, 161, 29));
        pushButtonAdd = new QPushButton(AddItemForm);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(770, 450, 83, 29));
        layoutWidget = new QWidget(AddItemForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 350, 1071, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        lineEditAddName = new QLineEdit(layoutWidget);
        lineEditAddName->setObjectName("lineEditAddName");

        horizontalLayout->addWidget(lineEditAddName);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        lineEditAddQuantity = new QLineEdit(layoutWidget);
        lineEditAddQuantity->setObjectName("lineEditAddQuantity");

        horizontalLayout->addWidget(lineEditAddQuantity);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout->addWidget(label_7);

        lineEditAddCategory = new QLineEdit(layoutWidget);
        lineEditAddCategory->setObjectName("lineEditAddCategory");

        horizontalLayout->addWidget(lineEditAddCategory);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout->addWidget(label_8);

        lineEditAddPrice = new QLineEdit(layoutWidget);
        lineEditAddPrice->setObjectName("lineEditAddPrice");

        horizontalLayout->addWidget(lineEditAddPrice);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);

        lineEditAddSupplier = new QLineEdit(layoutWidget);
        lineEditAddSupplier->setObjectName("lineEditAddSupplier");

        horizontalLayout->addWidget(lineEditAddSupplier);


        retranslateUi(AddItemForm);

        QMetaObject::connectSlotsByName(AddItemForm);
    } // setupUi

    void retranslateUi(QDialog *AddItemForm)
    {
        AddItemForm->setWindowTitle(QCoreApplication::translate("AddItemForm", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("AddItemForm", "Add", nullptr));
        label_11->setText(QCoreApplication::translate("AddItemForm", "Select a photo before clicking add:", nullptr));
        pushButtonSelectPhoto->setText(QCoreApplication::translate("AddItemForm", "Select photo", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("AddItemForm", "Add", nullptr));
        label_5->setText(QCoreApplication::translate("AddItemForm", "Name:", nullptr));
        label_6->setText(QCoreApplication::translate("AddItemForm", "Quantity:", nullptr));
        label_7->setText(QCoreApplication::translate("AddItemForm", "Category:", nullptr));
        label_8->setText(QCoreApplication::translate("AddItemForm", "Price:", nullptr));
        label_9->setText(QCoreApplication::translate("AddItemForm", "Supplier:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemForm: public Ui_AddItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMFORM_H
