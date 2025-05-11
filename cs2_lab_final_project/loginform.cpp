#include "loginform.h"
#include "ui_loginform.h"
#include <QString>
#include <QDebug>
#include "dashboard.h"

#include "systemui.h"

bool LoginForm::isDarkMode = false;

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

    /* Table styling for dark mode */
    QTableView, QTableWidget {
        background-color: #121212;
        color: #E0E0E0;
        gridline-color: #3A3A3A;
        border: 1px solid #3A3A3A;
    }

    QHeaderView::section {
        background-color: #1F1F1F;
        color: #E0E0E0;
        border: 1px solid #3A3A3A;
    }

    QTableView::item, QTableWidget::item {
        border: 1px solid #3A3A3A;
    }

    /* Additional elements that need dark styling */
    QTextEdit, QPlainTextEdit {
        background-color: #1F1F1F;
        color: #E0E0E0;
        border: 1px solid #3A3A3A;
    }

    QComboBox {
        background-color: #1F1F1F;
        color: #E0E0E0;
        border: 1px solid #3A3A3A;
    }

    QComboBox QAbstractItemView {
        background-color: #1F1F1F;
        color: #E0E0E0;
        selection-background-color: #2A2A2A;
    }

    QScrollBar {
        background-color: #1F1F1F;
    }

    QScrollBar::handle {
        background-color: #3A3A3A;
    }
    )";

    lightStyle = R"(
    QWidget { background-color: #FFFFFF; color: #000000; }
    QPushButton { background-color: #F0F0F0; color: #000000; }
    QLineEdit { background-color: #FFFFFF; color: #000000; }

    /* Table styling for light mode */
    QTableView, QTableWidget {
        background-color: #FFFFFF;
        color: #000000;
        gridline-color: #D0D0D0;
        border: 1px solid #D0D0D0;
    }

    QHeaderView::section {
        background-color: #F0F0F0;
        color: #000000;
        border: 1px solid #D0D0D0;
    }

    /* Additional elements for light mode */
    QTextEdit, QPlainTextEdit {
        background-color: #FFFFFF;
        color: #000000;
        border: 1px solid #D0D0D0;
    }

    QComboBox {
        background-color: #FFFFFF;
        color: #000000;
        border: 1px solid #D0D0D0;
    }
    )";


    //the default is the light mode
    ui->pushButton_Theme->setText("");
    ui->pushButton_Theme->setIcon(QIcon(":/icons/moon_4867888.png"));
    qApp->setStyleSheet(lightStyle);
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

void LoginForm::on_pushButton_Theme_clicked()
{
    isDarkMode = !isDarkMode;
    qApp->setStyleSheet(isDarkMode ? darkStyle : lightStyle);
    ui->pushButton_Theme->setIcon(QIcon(isDarkMode ? ":/icons/sun_15195263.png" : ":/icons/moon_4867888.png"));
}

