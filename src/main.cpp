#include "gui/MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("ICP2024");
    MainWindow w;
    w.showMaximized();
    w.show();
    return a.exec();
}
