/********************************************************************************
** Form generated from reading UI file 'inventoryform.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVENTORYFORM_H
#define UI_INVENTORYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_InventoryForm
{
public:
    QTableWidget *tableWidgetInventoryItems;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditSearch;
    QPushButton *pushButtonSearch;
    QComboBox *comboBoxCriteria;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditAddName;
    QLineEdit *lineEditAddSupplier;
    QLineEdit *lineEditAddQuantity;
    QLineEdit *lineEditAddPrice;
    QLineEdit *lineEditAddCategory;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButtonAdd;
    QLabel *label_10;
    QTextEdit *textEditLowStock;
    QPushButton *pushButton_Go_back;

    void setupUi(QDialog *InventoryForm)
    {
        if (InventoryForm->objectName().isEmpty())
            InventoryForm->setObjectName("InventoryForm");
        InventoryForm->resize(1158, 646);
        InventoryForm->setStyleSheet(QString::fromUtf8(""));
        tableWidgetInventoryItems = new QTableWidget(InventoryForm);
        if (tableWidgetInventoryItems->columnCount() < 5)
            tableWidgetInventoryItems->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetInventoryItems->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidgetInventoryItems->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetInventoryItems->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetInventoryItems->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetInventoryItems->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetInventoryItems->setObjectName("tableWidgetInventoryItems");
        tableWidgetInventoryItems->setGeometry(QRect(150, 60, 631, 261));
        label = new QLabel(InventoryForm);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 0, 111, 41));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label_2 = new QLabel(InventoryForm);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 350, 63, 20));
        lineEditSearch = new QLineEdit(InventoryForm);
        lineEditSearch->setObjectName("lineEditSearch");
        lineEditSearch->setGeometry(QRect(210, 350, 471, 28));
        pushButtonSearch = new QPushButton(InventoryForm);
        pushButtonSearch->setObjectName("pushButtonSearch");
        pushButtonSearch->setGeometry(QRect(210, 430, 83, 29));
        comboBoxCriteria = new QComboBox(InventoryForm);
        comboBoxCriteria->addItem(QString());
        comboBoxCriteria->addItem(QString());
        comboBoxCriteria->addItem(QString());
        comboBoxCriteria->setObjectName("comboBoxCriteria");
        comboBoxCriteria->setGeometry(QRect(210, 390, 82, 28));
        label_3 = new QLabel(InventoryForm);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 390, 63, 20));
        label_4 = new QLabel(InventoryForm);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(440, 470, 51, 41));
        label_4->setFont(font1);
        lineEditAddName = new QLineEdit(InventoryForm);
        lineEditAddName->setObjectName("lineEditAddName");
        lineEditAddName->setGeometry(QRect(70, 520, 113, 28));
        lineEditAddSupplier = new QLineEdit(InventoryForm);
        lineEditAddSupplier->setObjectName("lineEditAddSupplier");
        lineEditAddSupplier->setGeometry(QRect(820, 520, 113, 28));
        lineEditAddQuantity = new QLineEdit(InventoryForm);
        lineEditAddQuantity->setObjectName("lineEditAddQuantity");
        lineEditAddQuantity->setGeometry(QRect(270, 520, 113, 28));
        lineEditAddPrice = new QLineEdit(InventoryForm);
        lineEditAddPrice->setObjectName("lineEditAddPrice");
        lineEditAddPrice->setGeometry(QRect(630, 520, 113, 28));
        lineEditAddCategory = new QLineEdit(InventoryForm);
        lineEditAddCategory->setObjectName("lineEditAddCategory");
        lineEditAddCategory->setGeometry(QRect(460, 520, 113, 28));
        label_5 = new QLabel(InventoryForm);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 520, 63, 20));
        label_6 = new QLabel(InventoryForm);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 520, 63, 20));
        label_7 = new QLabel(InventoryForm);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 520, 63, 20));
        label_8 = new QLabel(InventoryForm);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(590, 520, 63, 20));
        label_9 = new QLabel(InventoryForm);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(760, 520, 63, 20));
        pushButtonAdd = new QPushButton(InventoryForm);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(430, 570, 83, 29));
        label_10 = new QLabel(InventoryForm);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(940, 10, 131, 31));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color:red;"));
        textEditLowStock = new QTextEdit(InventoryForm);
        textEditLowStock->setObjectName("textEditLowStock");
        textEditLowStock->setGeometry(QRect(940, 70, 131, 111));
        pushButton_Go_back = new QPushButton(InventoryForm);
        pushButton_Go_back->setObjectName("pushButton_Go_back");
        pushButton_Go_back->setGeometry(QRect(10, 20, 91, 51));

        retranslateUi(InventoryForm);

        QMetaObject::connectSlotsByName(InventoryForm);
    } // setupUi

    void retranslateUi(QDialog *InventoryForm)
    {
        InventoryForm->setWindowTitle(QCoreApplication::translate("InventoryForm", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetInventoryItems->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("InventoryForm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetInventoryItems->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("InventoryForm", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetInventoryItems->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("InventoryForm", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetInventoryItems->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("InventoryForm", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetInventoryItems->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("InventoryForm", "Supplier", nullptr));
        label->setText(QCoreApplication::translate("InventoryForm", "Inventory", nullptr));
        label_2->setText(QCoreApplication::translate("InventoryForm", "Search:", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("InventoryForm", "Go", nullptr));
        comboBoxCriteria->setItemText(0, QCoreApplication::translate("InventoryForm", "Name", nullptr));
        comboBoxCriteria->setItemText(1, QCoreApplication::translate("InventoryForm", "Category", nullptr));
        comboBoxCriteria->setItemText(2, QCoreApplication::translate("InventoryForm", "Supplier", nullptr));

        label_3->setText(QCoreApplication::translate("InventoryForm", "Criteria:", nullptr));
        label_4->setText(QCoreApplication::translate("InventoryForm", "Add", nullptr));
        label_5->setText(QCoreApplication::translate("InventoryForm", "Name:", nullptr));
        label_6->setText(QCoreApplication::translate("InventoryForm", "Quantity:", nullptr));
        label_7->setText(QCoreApplication::translate("InventoryForm", "Category:", nullptr));
        label_8->setText(QCoreApplication::translate("InventoryForm", "Price:", nullptr));
        label_9->setText(QCoreApplication::translate("InventoryForm", "Supplier:", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("InventoryForm", "Add", nullptr));
        label_10->setText(QCoreApplication::translate("InventoryForm", "Low Stock:", nullptr));
        textEditLowStock->setHtml(QCoreApplication::translate("InventoryForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Item #1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Item #2</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Item #3</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:"
                        "0px;\">Item #4</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Item #5</p></body></html>", nullptr));
        pushButton_Go_back->setText(QCoreApplication::translate("InventoryForm", "Go back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InventoryForm: public Ui_InventoryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVENTORYFORM_H
