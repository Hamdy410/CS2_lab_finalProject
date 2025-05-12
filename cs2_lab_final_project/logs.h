#ifndef LOGS_H
#define LOGS_H

#include <QDialog>
#include "inventorysystem.h"

namespace Ui {
class Logs;
}

class Logs : public QDialog
{
    Q_OBJECT

public:
    explicit Logs(InventorySystem* inventorySystem, QWidget *parent = nullptr);
    ~Logs();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::Logs *ui;
};

#endif // LOGS_H
