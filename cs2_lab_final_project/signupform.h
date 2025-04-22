#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QDialog>

namespace Ui {
class SignUpForm;
}

class SignUpForm : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpForm(QWidget *parent = nullptr);
    ~SignUpForm();

private:
    Ui::SignUpForm *ui;
};

#endif // SIGNUPFORM_H
