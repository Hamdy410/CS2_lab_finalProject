#include "loginform.h"
#include "ui_loginform.h"
#include <QString>
#include <QDebug>
#include "dashboard.h"

#include "systemui.h"

LoginForm::LoginForm(InventorySystem* inventorySystemParam, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    inventorySystem = inventorySystemParam;

    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
    togglePasswordAction = new QAction(QIcon(":/icons/eye_closed.png"), "", this);
    ui->lineEdit_Password->addAction(togglePasswordAction, QLineEdit::TrailingPosition);
    isPasswordVisible = false;

    connect(togglePasswordAction, &QAction::triggered, this, [=] () {
        isPasswordVisible = !isPasswordVisible;
        ui->lineEdit_Password->setEchoMode(isPasswordVisible ? QLineEdit::Normal : QLineEdit::Password);
        togglePasswordAction->setIcon(QIcon(isPasswordVisible ? ":/icons/eye_open.png" : ":icons/eye_closed.png"));
    });

    darkStyle = R"(
    QWidget { background-color: #121212; color: #E0E0E0; }
    QPushButton { background-color: #1F1F1F; color: #E0E0E0; }
    QLineEdit { background-color: #1F1F1F; color: #E0E0E0; }
)";

    lightStyle = R"(
    QWidget { background-color: #FFFFFF; color: #000000; }
    QPushButton { background-color: #F0F0F0; color: #000000; }
    QLineEdit { background-color: #FFFFFF; color: #000000; }
)";

    isDarkMode = false; //the default is the light mode
    toggleChoosingTheme= new QAction(QIcon(":/icons/sun_15195263.png"), "", this);
    ui->pushButton_Theme->setIcon(QIcon(":/icons/sun_15195263.png"));
    qApp->setStyleSheet(lightStyle);

    // connect(toggleChoosingTheme, &QAction::triggered, this, [=]() mutable {
    //     isDarkMode = !isDarkMode;
    //     qApp->setStyleSheet(isDarkMode ? darkStyle : lightStyle);
    //     toggleChoosingTheme->setIcon(QIcon(isDarkMode ? ":/icons/moon_4867888.png" : ":/icons/sun_15195263.png"));
    // });
}

LoginForm::~LoginForm()
{
    qDebug() << "login form destroyed";
    delete inventorySystem;
    delete ui;
}

void LoginForm::on_pushButton_Login_clicked()
{   
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    // Process Input

    qDebug() << "Username: " << username;
    qDebug() << "Password: " << password;
    if (inventorySystem->authenticateUser(username, password)) {
        qDebug() << "Found the user";
        SystemUI* system = new SystemUI(this, inventorySystem);
        system->show();

        this->ui->lineEdit_Username->setText("");
        this->ui->lineEdit_Password->setText("");

        this->hide();
    } else {
        qDebug() << "Cannot find the user.";
    }
}

// void LoginForm::makeDark()
// {
//     qApp->setStyleSheet(darkStyle);
// }

// void LoginForm::makeLight()
// {
//     qApp->setStyleSheet(lightStyle);
// }

void LoginForm::on_pushButton_Theme_clicked()
{
    isDarkMode = !isDarkMode;
    qApp->setStyleSheet(isDarkMode ? darkStyle : lightStyle);
    toggleChoosingTheme->setIcon(QIcon(isDarkMode ? ":/icons/moon_4867888.png" : ":/icons/sun_15195263.png"));
}

