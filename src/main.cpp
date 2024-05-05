/** ICP Project 2023-2024
 * @file main.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Application execution point
 */
#include "gui/MainWindow.h"

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QString>
#include <iostream>

/**
 * @brief Main function (by Qt)
 * 
 * @param argc count of arguments
 * @param argv vector of arguments
 * @return int 0(=succes) or other(=unsuccess) 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("ICP2024");
    QString stylesSting = "QAction, QMenu, QMenuBar, QPushButton, QLabel {color: black;}"
                     "QMenu::item::selected {color: white;}";
    a.setStyleSheet(stylesSting);
    MainWindow w;
    w.showMaximized();
    w.show();
    return a.exec();
}
