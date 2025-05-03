// welcomewindow.h
#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class WelcomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = nullptr);
signals:
    void quitActionTriggered();

private slots:
    void onLoginButtonClicked();
    void onQuitButtonClicked();


private:
    QPushButton *loginButton;
    QPushButton *quitButton;
};

#endif // WELCOMEWINDOW_H
