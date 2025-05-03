// mainwindow.cpp
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(300, 300);
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *accountMenu = new QMenu("Account", this);
    QMenu *userMenu = new QMenu("User", this);

    QAction *savingAccountAction = new QAction("Saving Account", this);
    QAction *checkBalanceAction = new QAction("Check Balance", this);
    QAction *addAccountAction = new QAction("Add Account", this);
    QAction *debitCardAction = new QAction("Debit Card", this);
    QAction *payContactsAction = new QAction("Pay Your Contacts", this);
    QAction *settingsAction = new QAction("Settings", this);
    QAction *profileViewAction = new QAction("Profile View", this);
    QAction *logoutAction = new QAction("Logout", this);

    accountMenu->addAction(savingAccountAction);
    accountMenu->addAction(checkBalanceAction);
    accountMenu->addAction(addAccountAction);
    accountMenu->addAction(debitCardAction);
    accountMenu->addAction(payContactsAction);
    userMenu->addAction(settingsAction);
    userMenu->addAction(profileViewAction);
    userMenu->addAction(logoutAction);



    menuBar->addMenu(accountMenu);
    menuBar->setCornerWidget(userMenu, Qt::TopRightCorner); // Set userMenu to the top right corner
    setMenuBar(menuBar);

    connect(savingAccountAction, SIGNAL(triggered()), this, SLOT(onSavingAccountClicked()));
    connect(checkBalanceAction, SIGNAL(triggered()), this, SLOT(onCheckBalanceClicked()));
    connect(addAccountAction, SIGNAL(triggered()), this, SLOT(onAddAccountClicked()));
    connect(debitCardAction, SIGNAL(triggered()), this, SLOT(onDebitCardClicked()));
    connect(payContactsAction, SIGNAL(triggered()), this, SLOT(onPayContactsClicked()));
    connect(settingsAction, SIGNAL(triggered()), this, SLOT(onSettingsClicked()));
    connect(profileViewAction, SIGNAL(triggered()), this, SLOT(onProfileViewClicked()));
    connect(logoutAction, SIGNAL(triggered()), this, SLOT(onLogoutClicked()));
}

void MainWindow::onSavingAccountClicked()
{
    QMessageBox::information(this, "Saving Account", "Saving Account Page");
}

void MainWindow::onCheckBalanceClicked()
{
    QMessageBox::information(this, "Check Balance", "Check Balance Page");
}

void MainWindow::onAddAccountClicked()
{
    QMessageBox::information(this, "Add Account", "Add Account Page");
}

void MainWindow::onDebitCardClicked()
{
    QMessageBox::information(this, "Debit Card", "Debit Card Page");
}

void MainWindow::onPayContactsClicked()
{
    QMessageBox::information(this, "Pay Your Contacts", "Pay Your Contacts Page");
}

void MainWindow::onSettingsClicked()
{
    QMessageBox::information(this, "Settings", "Settings Page");
}

void MainWindow::onProfileViewClicked()
{
    QMessageBox::information(this, "Profile View", "Profile View Page");
}

void MainWindow::onLogoutClicked()
{
    QMessageBox::information(this, "Logout", "Logged out successfully");
    close();
}
