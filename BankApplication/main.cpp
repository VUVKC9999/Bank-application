// main.cpp
#include <QApplication>
#include "loginwindow.h"
#include "WelcomeWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    WelcomeWindow welcomeWindow;
     welcomeWindow.show();
     QObject::connect(&welcomeWindow, &WelcomeWindow::quitActionTriggered, &QApplication::quit);
         return a.exec();
}
