// registerwindow.cpp
#include "RegisterWindow.h"
#include "loginwindow.h"
#include "WelcomeWindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>

RegisterWindow::RegisterWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Register");
    resize(300,300);
    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");
    usernameLineEdit->setGeometry(50, 10, 200, 30);

//    mobilenum = new QLineEdit(this);
//    mobilenum->setPlaceholderText("mobile Number");
//    mobilenum->setGeometry(50, 50, 200, 30);

//    emailadd = new QLineEdit(this);
//    emailadd->setPlaceholderText("Mail Id");
//    emailadd->setGeometry(50, 90, 200, 30);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setGeometry(50, 130, 200, 30);

    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setPlaceholderText("Confirm Password");
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLineEdit->setGeometry(50, 170, 200, 30);

    registerButton = new QPushButton("Register", this);
    registerButton->setGeometry(50, 210, 200, 30);

    backbutton = new QPushButton("Back", this);
    backbutton->setGeometry(50, 250, 200, 30);

    connect(registerButton, SIGNAL(clicked()), this, SLOT(onRegisterButtonClicked()));
    connect(backbutton, SIGNAL(clicked()), this, SLOT(onBackButtonClicked()));
}

void RegisterWindow::onRegisterButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QString confirmPassword = confirmPasswordLineEdit->text();

    // Perform input validation
    if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::critical(this, "Error", "All fields are required.");
        return;
    }

    // Perform password match validation
    if (password != confirmPassword) {
        QMessageBox::critical(this, "Error", "Passwords do not match.");
        return;
    }

    // Perform email validation (if needed)

    // Store the registered username and password in a file
    QFile file("/home/sana/BankApplication/users.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << ":" << password << "\n";
        file.close();

        QMessageBox::information(this, "Success", "Registration successful.");

        // Clear the input fields
        usernameLineEdit->clear();
        passwordLineEdit->clear();
        confirmPasswordLineEdit->clear();

        // Open the login window
        LoginWindow *loginWindow = new LoginWindow();
        loginWindow->show();
        this->hide();
    } else {
        QMessageBox::critical(this, "Error", "Failed to register. Please try again.");
    }
}

void RegisterWindow::onBackButtonClicked()
{
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
    this->hide();
}
