#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QCloseEvent>
#include "inventorysystem.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(InventorySystem* inventorySystemInput, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_goBackPushButton_clicked();

    void on_pushButton_Report_clicked();

    void on_pushButtonAddItem_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Dashboard *ui;
    InventorySystem* inventorySystem;

    void displayLowStock();
};

#endif // DASHBOARD_H
