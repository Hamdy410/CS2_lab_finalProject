#ifndef SYSTEMUI_H
#define SYSTEMUI_H

#include <QDialog>

#include "user.h"
#include "inventorysystem.h"

namespace Ui {
class SystemUI;
}

class SystemUI : public QDialog
{
    Q_OBJECT

public:
    explicit SystemUI(QWidget *parent = nullptr, InventorySystem* inventorySystem=nullptr);
    ~SystemUI();

private slots:
    void on_signoutPushButton_clicked();

    void on_dashboardButton_clicked();

    void on_adminPageButton_clicked();

    void on_inventoryManagerButton_clicked();

private:
    Ui::SystemUI *ui;
    InventorySystem* inventorySystem = nullptr;
};

#endif // SYSTEMUI_H
