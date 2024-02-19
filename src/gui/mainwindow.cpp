#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setApplicationDisplayName("ICP2024");
    crutchMenuWindowFlag = false;
    crutchSimulationWindowFlag = false;
    createMenuWindow();
}

void MainWindow::createMenuWindowButtons(){
    startMenuButton = new QPushButton("start", this);
    //settingsMenuButton = new QPushButton("settings", this);
    connect(startMenuButton, SIGNAL(clicked(bool)), this, SLOT(createSimulationWindow()));
}

void MainWindow::deleteMenuWindowButtons(){
    disconnect(startMenuButton, 0, 0, 0);
    delete startMenuButton;
    //delete settingsMenuButton;
}

void MainWindow::createMenuWindow(){
    crutchMenuWindowFlag = true;
    deleteSimulationWindow();

    setWindowTitle("Menu");
    //setStyleSheet("background-color: #0e1047;");
    setFixedSize(1000, 1000);

    createMenuWindowButtons();
}

void MainWindow::deleteMenuWindow(){
    if(crutchMenuWindowFlag){
        crutchMenuWindowFlag = false;
        deleteMenuWindowButtons();
    }
}

void MainWindow::createSimulationWindowButtons(){
    startSimulationButton = new QPushButton("start", this);
    startSimulationButton->setGeometry(130, 670, 100, 50);  // 10, 600, 100, 50
    startSimulationButton->setStyleSheet("background-color: green;");
    startSimulationButton->show();

    stopSimulationButton = new QPushButton("stop", this);
    stopSimulationButton->setGeometry(130, 770, 100, 50);
    stopSimulationButton->setStyleSheet("background-color: red;");
    stopSimulationButton->show();

    continueSimulationButton = new QPushButton("continue", this);
    continueSimulationButton->setGeometry(780, 670, 100, 50);
    continueSimulationButton->setStyleSheet("background-color: orange;");
    continueSimulationButton->show();

    settingsSimulationButton = new QPushButton("settings", this);
    settingsSimulationButton->setGeometry(780, 770, 100, 50);
    settingsSimulationButton->setStyleSheet("background-color: blue;");
    settingsSimulationButton->show();

    forwardMoveSimulationButton = new QPushButton("forward", this);
    forwardMoveSimulationButton->setGeometry(460, 640, 80, 80);
    forwardMoveSimulationButton->setStyleSheet("background-color: purple;");
    forwardMoveSimulationButton->show();

    moveRotateLeftSimulationButton = new QPushButton("left", this);
    moveRotateLeftSimulationButton->setGeometry(360, 740, 80, 80);
    moveRotateLeftSimulationButton->setStyleSheet("background-color: purple;");
    moveRotateLeftSimulationButton->show();

    moveRotateRightSimulationButton = new QPushButton("right", this);
    moveRotateRightSimulationButton->setGeometry(560, 740, 80, 80);
    moveRotateRightSimulationButton->setStyleSheet("background-color: purple;");
    moveRotateRightSimulationButton->show();

    movestopSimulationButton = new QPushButton("stop move", this);
    movestopSimulationButton->setGeometry(460, 740, 80, 80);
    movestopSimulationButton->setStyleSheet("background-color: purple;");
    movestopSimulationButton->show();

    connect(startSimulationButton, SIGNAL(clicked()), this, SLOT(createLabel()));
    connect(stopSimulationButton, SIGNAL(clicked()), this, SLOT(deleteLabel()));
}

void MainWindow::createSimulationWindow(){
    crutchSimulationWindowFlag = true;
    deleteMenuWindow();
    setWindowTitle("Simulation");
    //setStyleSheet("background-color: #0e1047;");
    setFixedSize(1000, 1000);
    createSimulationWindowButtons();
}

void MainWindow::deleteSimulationWindow(){
    if(crutchSimulationWindowFlag){
        crutchSimulationWindowFlag = false;
        deleteSimulationWindowButtons();
    }
}

void MainWindow::createLabel(){
    l = new QLabel(this);
    l->setText("Hello, world!");
    l->show();
}

void MainWindow::deleteLabel(){
    delete l;
}
void MainWindow::deleteSimulationWindowButtons(){
    disconnect(startSimulationButton, 0, 0, 0);
    disconnect(stopSimulationButton, 0, 0, 0);
    delete startSimulationButton;
    delete stopSimulationButton;
    delete continueSimulationButton;
    delete settingsSimulationButton;
    delete forwardMoveSimulationButton;
    delete moveRotateLeftSimulationButton;
    delete moveRotateRightSimulationButton;
    delete movestopSimulationButton;
}

MainWindow::~MainWindow()
{
    deleteMenuWindow();
    deleteSimulationWindow();
    delete ui;
}
