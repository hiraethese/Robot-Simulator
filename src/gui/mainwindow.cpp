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
    createAppWindows();
    //centralWidget->setStyleSheet("QWidget { background-color: white; }");
}


MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}


void MainWindow::createAppWindows(){
    createActions();
    createTools();
}


void MainWindow::deleteAppWindows(){
    deleteActions();
    deleteTools();
}


void MainWindow::createActions(){
    helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(helpToolAction, SIGNAL(triggered()), this, SLOT(helpTextToolActionFunctional()));

    newMapToolAction = new QAction(QIcon(":/icons/newMapTool.png"), "&New map", this);
    connect(newMapToolAction, SIGNAL(triggered()), this, SLOT(newMapToolActionFunctional()));

    /* MENU FOR NEW MAP
    newMapMenu = new QMenu(this);
    newMapDownload = new QAction("download new map");
    newMapCreate = new QAction("create new map");
    newMapMenu->addAction(newMapDownload);
    newMapMenu->addAction(newMapCreate);
    newMapToolAction->setMenu(newMapMenu);
    */
    listMapToolAction = new QAction(QIcon(":/icons/listOfMapTool.png"), "&List of maps", this);
    connect(listMapToolAction, SIGNAL(triggered()), this, SLOT(listMapToolActionFunctional()));

    settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(settingsToolAction, SIGNAL(triggered()), this, SLOT(settingsToolActionFunctional()));
}


void MainWindow::deleteActions(){
    disconnect(helpToolAction, 0, 0, 0);
    disconnect(newMapToolAction, 0, 0, 0);
    disconnect(listMapToolAction, 0, 0, 0);
    disconnect(settingsToolAction, 0, 0, 0);

    delete helpToolAction;
    delete newMapToolAction;
    delete listMapToolAction;
    delete settingsToolAction;
}


void MainWindow::createTools(){
    helpToolBar = addToolBar("&help");
    helpToolBar->addAction(helpToolAction);


    mapToolBar = addToolBar("&maps");
    mapToolBar->addAction(newMapToolAction);
    mapToolBar->addAction(listMapToolAction);

    settingsToolBar = addToolBar("&settings");
    settingsToolBar->addAction(settingsToolAction);
}


void MainWindow::deleteTools(){
    delete helpToolBar;
    delete mapToolBar;
    delete settingsToolBar;
}


void MainWindow::helpTextToolActionFunctional(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::newMapToolActionFunctional(){
    // !!! creatting widget for writting new map, parsing and sending do simulations widget creatting
    //QMessageBox::about(this, "Help", "<b>This place will be for creatting new maps!</b>");
    absolutePathToTextMapFile = QInputDialog::getText(this, tr("new map"), tr("Enter path to map file")); // QLineEdit::Normal
}

void MainWindow::listMapToolActionFunctional(){
    // !!! creatting widget list all existting maps and choosing one actual or delete
    QMessageBox::about(this, "Help", "<b>This place will be for creatting new maps!</b>");
}

void MainWindow::settingsToolActionFunctional(){
    // !!! creatting widget for setting
    QMessageBox::about(this, "Help", "<b>This place will be for setting!</b>");
}






































