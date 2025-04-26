#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "inventorysystem.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QDialog
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = nullptr, InventorySystem* inventorySystem=nullptr);
    ~AdminForm();

private slots:
    void on_filtersComboBox_currentIndexChanged(int index);
    void on_goBackPushButton_clicked();
    void on_addnewUserPushButton_clicked();

    void onEditUser(int row);
    void onDeleteUser(int row);
    void refreshTable();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::AdminForm *ui;
    InventorySystem* inventorySystem = nullptr;
    void populateTable(const QString& roleFilter = "All Roles");
};

#endif // ADMINFORM_H
