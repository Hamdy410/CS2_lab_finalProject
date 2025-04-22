#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QDialog>
#include <QModelIndex>
#include "inventorysystem.h"

namespace Ui {
class Ui_AdminForm;
}

class Ui_AdminForm : public QDialog
{
    Q_OBJECT

public:
    explicit Ui_AdminForm(InventorySystem* system, QWidget *parent = nullptr);
    ~Ui_AdminForm();

private slots:
    void on_addUserButton_clicked();
    void on_roleFilterComboBox_currentIndexChanged(int index);
    void onEditButtonClicked();
    void onDeleteButtonClicked();
    void refreshUserTable();

    // Add these missing method declarations
    void onTableItemClicked(const QModelIndex &current, const QModelIndex &previous);
    void onDeleteUser(const QString &username);

private:
    Ui::Ui_AdminForm *ui;
    InventorySystem* inventorySystem;

    void setupTable();
    void populateTable(Role roleFilter = static_cast<Role>(-1));
    bool validateAdminAccess();
    void createActionButtons(int row, const QString& username);
};

#endif // UI_ADMINFORM_H
