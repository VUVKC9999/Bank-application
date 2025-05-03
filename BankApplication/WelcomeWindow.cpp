// welcomewindow.cpp
#include "WelcomeWindow.h"
#include "loginwindow.h"
#include "RegisterWindow.h"
#include <QCoreApplication>

WelcomeWindow::WelcomeWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Welcome");
    resize(300, 300);

    // Set background picture
    setStyleSheet("WelcomeWindow { background-image: url(:/images/background.jpeg); }");

    // Create buttons
    loginButton = new QPushButton("Login", this);
    loginButton->setGeometry(50, 70, 200, 30);
    loginButton->setStyleSheet("QPushButton { background-color: #FF0000; color: #FFFFFF; }");

    QLabel *titleLabel = new QLabel("Welcome to My Bank App", this);
    titleLabel->setGeometry(60, 10, 200, 30);
    titleLabel->setStyleSheet("QLabel { color: #FFFFFF; }");

    QLabel *infoLabel = new QLabel("Please click login to continue", this);
    infoLabel->setGeometry(60, 150, 300, 30);
    infoLabel->setStyleSheet("QLabel { color: #FFFFFF; }");

    quitButton = new QPushButton("Quit", this);
    quitButton->setGeometry(50, 110, 200, 30);
    quitButton->setStyleSheet("QPushButton { background-color: #00FF00; color: #FFFFFF; }");

    connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(onQuitButtonClicked()));

}

void WelcomeWindow::onLoginButtonClicked()
{
    LoginWindow *loginWindow = new LoginWindow();
    loginWindow->show();
    this->hide();
}

void WelcomeWindow::onQuitButtonClicked()
{
    emit quitActionTriggered();
}




