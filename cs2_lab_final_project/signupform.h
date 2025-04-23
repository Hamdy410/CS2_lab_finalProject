#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H
#include "inventorysystem.h"
#include <QDialog>

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpForm(InventorySystem* inventorySystemParam, QWidget *parent = nullptr);
    ~SignUpForm();

private slots:
    void on_pushButtonSignUp_clicked();

private:
    Ui::SignUpForm *ui;
    InventorySystem* inventorySystem;
};

#endif // SIGNUPFORM_H
