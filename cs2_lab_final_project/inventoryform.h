#ifndef INVENTORYFORM_H
#define INVENTORYFORM_H

#include <QDialog>

namespace Ui {
class InventoryForm;
}

class InventoryForm : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryForm(QWidget *parent = nullptr);
    ~InventoryForm();

private:
    Ui::InventoryForm *ui;
};

#endif // INVENTORYFORM_H
