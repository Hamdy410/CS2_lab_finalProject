#ifndef ADDUSERFORM_H
#define ADDUSERFORM_H

#include <QDialog>

namespace Ui {
class AddUserForm;
}

class AddUserForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserForm(QWidget *parent = nullptr);
    ~AddUserForm();

private:
    Ui::AddUserForm *ui;
};

#endif // ADDUSERFORM_H
