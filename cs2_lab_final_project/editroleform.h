#ifndef EDITROLEFORM_H
#define EDITROLEFORM_H

#include <QDialog>

namespace Ui {
class editRoleform;
}

class editRoleform : public QDialog
{
    Q_OBJECT

public:
    explicit editRoleform(QWidget *parent = nullptr);
    ~editRoleform();

private slots:
    void on_comboBox_editRole_currentIndexChanged(int index);

private:
    Ui::editRoleform *ui;
};

#endif // EDITROLEFORM_H
