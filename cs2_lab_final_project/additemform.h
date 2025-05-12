#ifndef ADDITEMFORM_H
#define ADDITEMFORM_H

#include <QDialog>

#include <QDialog>
#include "inventorysystem.h"
#include "itemphotomanager.h"

namespace Ui {
class AddItemForm;
}

class AddItemForm : public QDialog
{
    Q_OBJECT

public:
 explicit AddItemForm(InventorySystem* inventorySystemParam, QWidget *parent = nullptr);    ~AddItemForm();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonSelectPhoto_clicked();

private:
    Ui::AddItemForm *ui;
    InventorySystem* inventorySystem;
    QString selectedPhotoPath;
};

#endif // ADDITEMFORM_H
