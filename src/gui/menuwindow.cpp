#include "menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 1000);
    setWindowTitle("Menu");
    initMenuWindowButtons();
}

MenuWindow::~MenuWindow(){
    deleteMenuWindowButtons();
}

void MenuWindow::initMenuWindowButtons(){
    startButton = new QPushButton("start", this);
    startButton->show();
}

void MenuWindow::deleteMenuWindowButtons(){
    delete startButton;
}
