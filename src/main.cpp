#include "gui/MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("ICP2024");
    QString stylesSting = "QAction, QMenu, QPushButton, QLabel {color: black;}"
                     "QMenu::item::selected {color: white;}";
    a.setStyleSheet(stylesSting);
    MainWindow w;
    w.showMaximized();
    w.show();
    return a.exec();
}
// /mnt/c/Users/user/icp2024/examples/example.txt
// C:\Users\user\icp2024\examples\example.txt

// For Illia:
// /home/illia/Desktop/Programming/ICP/icp2024/examples/example.txt
