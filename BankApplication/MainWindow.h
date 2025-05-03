// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onSavingAccountClicked();
    void onCheckBalanceClicked();
    void onAddAccountClicked();
    void onDebitCardClicked();
    void onPayContactsClicked();
    void onSettingsClicked();
    void onProfileViewClicked();
    void onLogoutClicked();
};

#endif // MAINWINDOW_H
