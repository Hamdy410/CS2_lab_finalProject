#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "inventorysystem.h"

#include <QDialog>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(InventorySystem* inventorySystemParam, QWidget *parent = nullptr);
    ~LoginForm();
    InventorySystem *inventorySystem;
private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_Sign_Up_clicked();

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
