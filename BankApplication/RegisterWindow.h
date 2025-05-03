// registerwindow.h
#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);

private slots:
    void onRegisterButtonClicked();
    void onBackButtonClicked();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
    QPushButton *registerButton;
    QPushButton *backbutton;
//    QLineEdit *mobilenum;
//    QLineEdit *emailadd;
};

#endif // REGISTERWINDOW_H
