#ifndef EDITROLEFORM_H
#define EDITROLEFORM_H

#include <QDialog>
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
    void setUserInfo(const QString& username, Role currentRole);
    Role getSelectedRole() const;
    QString getNewUsername() const;
    QString getNewPassword() const;

private slots:
    void on_comboBox_editRole_currentIndexChanged(int index);
    void on_pushButton_OK_clicked();

private:
    Ui::editRoleform *ui;
    QString m_username;
    bool validatePassword(const QString& password);
};

#endif // EDITROLEFORM_H
