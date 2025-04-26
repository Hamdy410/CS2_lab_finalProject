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

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonSearch_clicked();
    //void populateTable(const QVector<Item>& items);
    void refreshItems();
    void on_lineEditSearch_textChanged(const QString &);
    void on_comboBoxSearchCriteria_currentIndexChanged(int);

private:
    Ui::InventoryForm *ui;
    InventorySystem* inventorySystem;
};

#endif // INVENTORYFORM_H
