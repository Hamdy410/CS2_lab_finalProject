#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_goBackPushButton_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H
