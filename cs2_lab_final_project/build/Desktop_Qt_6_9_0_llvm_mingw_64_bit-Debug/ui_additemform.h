/********************************************************************************
** Form generated from reading UI file 'additemform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItemForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *lineEditAddQuantity;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEditAddName;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEditAddCategory;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *lineEditAddPrice;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEditAddSupplier;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QPushButton *pushButtonSelectPhoto;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButtonAdd;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_4;

    void setupUi(QDialog *AddItemForm)
    {
        if (AddItemForm->objectName().isEmpty())
            AddItemForm->setObjectName("AddItemForm");
        AddItemForm->resize(558, 501);
        verticalLayoutWidget = new QWidget(AddItemForm);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 30, 351, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_9 = new QSpacerItem(0, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        lineEditAddQuantity = new QLineEdit(verticalLayoutWidget);
        lineEditAddQuantity->setObjectName("lineEditAddQuantity");

        horizontalLayout_3->addWidget(lineEditAddQuantity);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_8 = new QSpacerItem(12, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        lineEditAddName = new QLineEdit(verticalLayoutWidget);
        lineEditAddName->setObjectName("lineEditAddName");

        horizontalLayout->addWidget(lineEditAddName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        lineEditAddCategory = new QLineEdit(verticalLayoutWidget);
        lineEditAddCategory->setObjectName("lineEditAddCategory");

        horizontalLayout_4->addWidget(lineEditAddCategory);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName("label_8");

        horizontalLayout_5->addWidget(label_8);

        horizontalSpacer_7 = new QSpacerItem(22, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        lineEditAddPrice = new QLineEdit(verticalLayoutWidget);
        lineEditAddPrice->setObjectName("lineEditAddPrice");

        horizontalLayout_5->addWidget(lineEditAddPrice);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");

        horizontalLayout_6->addWidget(label_9);

        horizontalSpacer_6 = new QSpacerItem(0, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEditAddSupplier = new QLineEdit(verticalLayoutWidget);
        lineEditAddSupplier->setObjectName("lineEditAddSupplier");

        horizontalLayout_6->addWidget(lineEditAddSupplier);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_7->addWidget(label_11);

        pushButtonSelectPhoto = new QPushButton(verticalLayoutWidget);
        pushButtonSelectPhoto->setObjectName("pushButtonSelectPhoto");

        horizontalLayout_7->addWidget(pushButtonSelectPhoto);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        pushButtonAdd = new QPushButton(verticalLayoutWidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        horizontalLayout_8->addWidget(pushButtonAdd);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_8);

        label_4 = new QLabel(AddItemForm);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 20, 61, 71));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);

        retranslateUi(AddItemForm);

        QMetaObject::connectSlotsByName(AddItemForm);
    } // setupUi

    void retranslateUi(QDialog *AddItemForm)
    {
        AddItemForm->setWindowTitle(QCoreApplication::translate("AddItemForm", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("AddItemForm", "Quantity:", nullptr));
        label_5->setText(QCoreApplication::translate("AddItemForm", "Name:", nullptr));
        label_7->setText(QCoreApplication::translate("AddItemForm", "Category:", nullptr));
        label_8->setText(QCoreApplication::translate("AddItemForm", "Price:", nullptr));
        label_9->setText(QCoreApplication::translate("AddItemForm", "Supplier:", nullptr));
        label_11->setText(QCoreApplication::translate("AddItemForm", "Select a photo before clicking add:", nullptr));
        pushButtonSelectPhoto->setText(QCoreApplication::translate("AddItemForm", "Select photo", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("AddItemForm", "Add", nullptr));
        label_4->setText(QCoreApplication::translate("AddItemForm", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemForm: public Ui_AddItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMFORM_H
