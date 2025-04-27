#ifndef INVENTORYFORM_H
#define INVENTORYFORM_H
#include "inventorysystem.h"
#include <QDialog>

namespace Ui {
class InventoryForm;
}

class InventoryForm : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryForm(InventorySystem* inventorySystemParam, QWidget *parent = nullptr);
    ~InventoryForm();
    void displayLowStock();
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonSearch_clicked();
    void refreshItems();
    void on_lineEditSearch_textChanged(const QString &);
    void on_comboBoxSearchCriteria_currentIndexChanged(int);

    void on_pushButton_Go_back_clicked();

private:
    Ui::InventoryForm *ui;
    InventorySystem* inventorySystem;
};

#endif // INVENTORYFORM_H
