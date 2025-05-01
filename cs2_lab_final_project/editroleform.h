#ifndef EDITROLEFORM_H
#define EDITROLEFORM_H

#include <QDialog>
#include <QAction>

#include "role.h"

namespace Ui {
class editRoleform;
}

class editRoleform : public QDialog
{
    Q_OBJECT

public:
    explicit editRoleform(QWidget *parent = nullptr);
    ~editRoleform();
    // Set the current user's information
    void setUserInfo(const QString& username,
                     const QString& password, Role currentRole);

    QString getUsername() const;
    QString getPassword() const;
    Role getRole() const;

private slots:
    void on_pushButton_OK_clicked();

private:
    Ui::editRoleform *ui;

    QAction* togglePasswordAction = nullptr;
    bool isPasswordVisible = false;
    bool validatePassword(const QString& password);
};

#endif // EDITROLEFORM_H
