#include "gui/mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("icp2024");
    MainWindow w;
    return a.exec();
}
