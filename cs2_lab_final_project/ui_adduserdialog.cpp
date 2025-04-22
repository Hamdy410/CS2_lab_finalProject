#include "ui_adduserdialog.h"

Ui_AddUserDialog::Ui_AddUserDialog(InventorySystem* system, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ui_AddUserDialog),
    inventorySystem(system)
{
    ui->setupUi(this);

    setWindowTitle("Add New User");
    setWindowIcon(style()->standardIcon(QStyle::SP_DialogYesButton));

    // Setup combo box
    ui->roleComboBox->addItem("Staff", static_cast<int>(Role::STAFF));
    ui->roleComboBox->addItem("Manager", static_cast<int>(Role::MANAGER));
    ui->roleComboBox->addAction("Admin", static_cast<int>(Role::ADMING));

    ui->roleComboBox->setCurrentIndex(0);

    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    okButton = ui->ButtonBox->button(QDialogButtonBox::Ok);

    setupMandatoryFields();
    validateInputs();
}

Ui_AddUserDialog::~Ui_AddUserDialog()
{
    delete ui;
}

void Ui_AddUserDialog::setupMandatoryFields()
{
    ui->usernameLineEdit->setProperty("mandatoryField", true);
    ui->passwordLineEdit->setProperty("mandatoryField", true);
    ui->confirmPasswordLineEdit->setProperty("mandatoryField", true);

    ui->usernameLabel->setText(ui->usernameLabel->text() + "*");
    ui->passwordLabel->setText(ui->passwordLabel->text() + "*");
    ui->confirlmPasswordLabel->setText(ui->passwordLabel->text() + "*");

    connect(ui->usernameLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::validateInputs);
    connect(ui->passwordLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::validateInputs);
    connect(ui->confirmPasswordLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::validateInputs);

    connect(ui->usernameLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::updatedMandatoryFieldsStyle);
    connect(ui->passwordLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::updatedMandatoryFieldsStyle);
    connect(ui->confirmPasswordLineEdit, &QLineEdit::textChanged, this,
            &Ui_AddUserDialog::updatedMandatoryFieldsStyle);

    updatedMandatoryFieldsStyle();
}

void Ui_AddUserDialog::updatedMandatoryFieldsStyle()
{
    QString stylesheet = "QLineEdit[mandatoryField=\"true\"] [text=\"\"] {background-color: #FFDDDD; border: 1px solid #FF9999; }";
    setStyleSheet(stylesheet);
}

void Ui_AddUserDialog::validateInputs()
{
    bool allFilled = !ui->usernameLineEdit->text().trimmed().isEmpty() &&
                     !ui->passwordLineEdit->text().isEmpty() &&
                     !ui->confirmPasswordLineEdit->text().isEmpty();
    bool passwordsMatch = (ui->passwordLineEdit->text() == ui->confirmPasswordLineEdit->text());
    okButton->setEnabled(allFilled && passwordsMatch);

    if (!passwordsMatch && !ui->passwordLineEdit->text().isEmpty() &&
        !ui->confirmPasswordLineEdit->text().isEmpty()) {
        ui->confirmPasswordLineEdit->setStyleSheet("background-color: #FFDDDD; border: 1px solid #FF9999;");
    } else {
        ui->confirmPasswordLineEdit->setStyleSheet("");
        updatedMandatoryFieldsStyle();
    }
}

void Ui_AddUserDialog::on_buttonBox_accepted()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();
    Role role = static_cast<Role>(ui->roleComboBox->currentData().toInt());

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Username cannot be empty.");
        return;
    }

    if (password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Password cannot be empty.");
        return;
    }

    if (confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Passwords do not match");
        return;
    }

    if (inventorySystem->userExists(username)) {
        QMessageBox::warning(this, "Input Error", "Username '" + username + "' already exists");
        return;
    }

    User newUser(username, password, role);
    if (inventorySystem->addUser(newUser)) {
        QMessageBox::information(this, "User Added",
                                 "User '" + username + "' has been added successfully.");
        accept();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add user.");
    }
}

void Ui_AddUserDialog::on_buttonBox_rejected()
{
    reject();
}

