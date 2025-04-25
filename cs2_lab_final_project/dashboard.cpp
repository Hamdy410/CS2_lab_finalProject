#include "dashboard.h"
#include "ui_dashboard.h"

#include <QCloseEvent>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_goBackPushButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void Dashboard::closeEvent(QCloseEvent *event) {
    this->parentWidget()->show();
    this->close();
}

