#ifndef UI_ADDUSERDIALOG_H
#define UI_ADDUSERDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include "inventorysystem.h"

namespace Ui {
class Ui_AddUserDialog;
}

class Ui_AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Ui_AddUserDialog(QWidget *parent = nullptr);
    explicit Ui_AddUserDialog(InventorySystem* system, QWidget *parent = nullptr);
    ~Ui_AddUserDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void validateInputs();
    void updatedMandatoryFieldsStyle();

private:
    Ui::Ui_AddUserDialog *ui;
    InventorySystem* inventorySystem;
    QPushButton* okButton;

    void setupMandatoryFields();
};

#endif // UI_ADDUSERDIALOG_H
