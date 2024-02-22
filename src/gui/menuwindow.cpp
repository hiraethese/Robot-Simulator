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
    menuBoxForButton = new QHBoxLayout(this);

    startButton = new QPushButton("start");
    startButton->setFixedSize(100, 50);
    settingsButton = new QPushButton("settings");
    settingsButton->setFixedSize(100, 50);
    setPlaceButton = new QPushButton("place");
    setPlaceButton->setFixedSize(100, 50);

    menuBoxForButton->addWidget(startButton);
    menuBoxForButton->addWidget(settingsButton);
    menuBoxForButton->addWidget(setPlaceButton);

    menuBoxForButton->setAlignment(Qt::AlignCenter);
}

void MenuWindow::deleteMenuWindowButtons(){
    delete startButton;
    delete settingsButton;
    delete setPlaceButton;
    delete menuBoxForButton;
}
