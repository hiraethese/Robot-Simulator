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
    initAppWindows();
    runApp();
    //centralWidget->setStyleSheet("QWidget { background-color: white; }");
}

MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}

void MainWindow::runApp(){
    menuWind->show();
    //simWind->show();
}

void MainWindow::initAppWindows(){
    menuWind = new MenuWindow();
    simWind = new SimulationWindow();
    connect(menuWind->startButton, SIGNAL(clicked()), this, SLOT(fromMenuToSimulation()));
    connect(simWind->startButton, SIGNAL(clicked()), this, SLOT(fromSimulationToMenu()));
}

void MainWindow::deleteAppWindows(){
    delete menuWind;
    delete simWind;
}

void MainWindow::fromMenuToSimulation(){
    menuWind->hide();
    simWind->show();
}

void MainWindow::fromSimulationToMenu(){
    simWind->hide();
    menuWind->show();
}






































