#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "inventorysystem.h"

#include <QDialog>
#include <QAction>

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
    void on_pushButton_Theme_clicked();

private:
    QString darkStyle;
    QString lightStyle;
    Ui::LoginForm *ui;
    QAction* togglePasswordAction;
    bool isPasswordVisible;
    bool isDarkMode;
};

#endif // LOGINFORM_H
