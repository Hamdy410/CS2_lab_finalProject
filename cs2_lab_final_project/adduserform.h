#ifndef ADDUSERFORM_H
#define ADDUSERFORM_H

#include <QDialog>
#include "role.h"

namespace Ui {
class AddUserForm;
}

class AddUserForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserForm(QWidget *parent = nullptr);
    ~AddUserForm();
    QString getUsername() const;
    QString getPassword() const;
    Role getRole() const;

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::AddUserForm *ui;
    QAction* togglePasswordAction;
    bool isPasswordVisible;
    bool validatePassword(const QString& password);
};

#endif // ADDUSERFORM_H
