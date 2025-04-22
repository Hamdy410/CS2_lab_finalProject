#ifndef UI_EDITUSERDIALOG_H
#define UI_EDITUSERDIALOG_H

#include <QDialog>
#include "inventorysystem.h"

namespace Ui {
class Ui_EditUserDialog;
}

class Ui_EditUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit Ui_EditUserDialog(QWidget *parent = nullptr);
    explicit Ui_EditUserDialog(InventorySystem* system, QString& username, QWidget* parent = nullptr);
    ~Ui_EditUserDialog();

private:
    Ui::Ui_EditUserDialog *ui;
};

#endif // UI_EDITUSERDIALOG_H
