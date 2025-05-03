// loginwindow.cpp
#include "loginwindow.h"
#include "MainWindow.h"
#include "WelcomeWindow.h"
#include "RegisterWindow.h"

#include <QFile>
#include <QTextStream>

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Login");
    resize(300, 300);
    setStyleSheet("LoginWindow { background-image: url(:/images/loginback.jpg); }");

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");
    usernameLineEdit->setGeometry(60, 10, 200, 30);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setGeometry(60, 50, 200, 30);

    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(90, 90, 130, 30);
    loginButton->setStyleSheet("QPushButton { background-color: #FF0000; color: #FFFFFF; }");

    registerbutton = new QPushButton("Register", this);
    registerbutton->setGeometry(60, 130, 200, 30);
    registerbutton->setStyleSheet("QPushButton { background-color: #0000FF; color: #FFFFFF; }");

    backButton = new QPushButton("<back", this);
    backButton->setGeometry(195, 165, 55, 35);
    backButton->setStyleSheet("QPushButton { background-color: #FFFFFF; color: #000000; }");


    connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(onBackButtonClicked()));
    connect(registerbutton, SIGNAL(clicked()), this, SLOT(onRegisterButtonClicked()));
}

void LoginWindow::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    // Perform input validation
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "Error", "Username and password are required.");
        return;
    }

    // Check if the entered username and password match the registered details from the file
    QFile file("/home/sana/BankApplication/users.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        bool loginSuccessful = false;

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(':');
            if (fields.size() == 2 && fields[0] == username && fields[1] == password) {
                loginSuccessful = true;
                break;
            }
        }

        file.close();

        if (loginSuccessful) {
            // Login successful
            QMessageBox::information(this, "Success", "Login successful.");

            // Open the main window
            MainWindow *mainWindow = new MainWindow();
            mainWindow->show();
            this->hide();
        } else {
            // Login failed
            QMessageBox::critical(this, "Error", "Invalid username or password.");
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to open user data file. Please try again.");
    }
}
void LoginWindow::onBackButtonClicked()
{
    WelcomeWindow *welcomeWindow = new WelcomeWindow();
    welcomeWindow->show();
    this->hide();
}

void LoginWindow::onRegisterButtonClicked()
{
    RegisterWindow *registerWindow = new RegisterWindow();
    registerWindow->show();
    this->hide();
}
