#include "mainwindow.h"
#include <QApplication>
#include "processes.h"
#include <QDebug>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Processes p;
    p.startProcesses();

    MainWindow w;

    w.show();

    return a.exec();
}
