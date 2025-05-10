#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "inventorysystem.h"

#include <QDialog>
#include <QAction>

// const QString darkStyle = R"(
//     QWidget { background-color: #121212; color: #E0E0E0; }
//     QPushButton { background-color: #1F1F1F; color: #E0E0E0; }
//     QLineEdit { background-color: #1F1F1F; color: #E0E0E0; }
// )";

// const QString lightStyle = R"(
//     QWidget { background-color: #FFFFFF; color: #000000; }
//     QPushButton { background-color: #F0F0F0; color: #000000; }
//     QLineEdit { background-color: #FFFFFF; color: #000000; }
// )";

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

// public slots:
//     void makeDark();
//     void makeLight();

    void on_pushButton_Theme_clicked();

private:
    QString darkStyle;
    QString lightStyle;
    Ui::LoginForm *ui;
    QAction* togglePasswordAction;
    bool isPasswordVisible;
    QAction* toggleChoosingTheme;
    bool isDarkMode;
};

#endif // LOGINFORM_H
