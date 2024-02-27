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
}


MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}


void MainWindow::createAppWindows(){
    createActions();
    createTools();
    createSimulationBody();
}


void MainWindow::deleteAppWindows(){
    deleteActions();
    deleteTools();
    deleteSimulationBody();
}

void MainWindow::createSimulationBody(){

    simBody = new SimulationBody(this);
    setCentralWidget(simBody);
}

void MainWindow::deleteSimulationBody(){
    //delete simBody;
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

    runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));

    restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(restartSimulationAction, SIGNAL(triggered()), this, SLOT(restartSimulationActionFunctional()));
}


void MainWindow::deleteActions(){
    disconnect(helpToolAction, 0, 0, 0);
    disconnect(newMapToolAction, 0, 0, 0);
    disconnect(listMapToolAction, 0, 0, 0);
    disconnect(settingsToolAction, 0, 0, 0);
    disconnect(runSimulationAction, 0, 0, 0);
    disconnect(restartSimulationAction, 0, 0, 0);
    delete helpToolAction;
    delete newMapToolAction;
    delete listMapToolAction;
    delete settingsToolAction;
    delete runSimulationAction;
    delete restartSimulationAction;
}


void MainWindow::createTools(){

    settingsToolBar = addToolBar(tr("settings"));
    settingsToolBar->addAction(settingsToolAction);

    engineSimRunToolBar = addToolBar(tr("engineSimRun"));
    engineSimRunToolBar->addAction(runSimulationAction);
    engineSimRunToolBar->addAction(restartSimulationAction);

    simulationIdToolBar = addToolBar(tr("simulationId"));
    labelSimIdToolBar = new QLabel("Simulation: ");
    simulationIdToolBar->addWidget(labelSimIdToolBar);
    lineMapNameSimIdToolBar = new QLineEdit();
    lineMapNameSimIdToolBar->setReadOnly(true);
    lineMapNameSimIdToolBar->setFixedWidth(500);
    simulationIdToolBar->addWidget(lineMapNameSimIdToolBar);

    mapToolBar = addToolBar(tr("maps"));
    mapToolBar->addAction(newMapToolAction);
    mapToolBar->addAction(listMapToolAction);
    helpToolBar = addToolBar(tr("help"));
    helpToolBar->addAction(helpToolAction);

}


void MainWindow::deleteTools(){
    delete labelSimIdToolBar;
    delete lineMapNameSimIdToolBar;
    delete helpToolBar;
    delete mapToolBar;
    delete settingsToolBar;
    delete engineSimRunToolBar;
    delete simulationIdToolBar;
}


void MainWindow::helpTextToolActionFunctional(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::newMapToolActionFunctional(){
    // !!! creatting widget for writting new map, parsing and sending do simulations widget creatting
    absolutePathToTextMapFile = QInputDialog::getText(this, tr("new map"), tr("Enter path to map file")); // QLineEdit::Normal
    lineMapNameSimIdToolBar->setText(absolutePathToTextMapFile);
}

void MainWindow::listMapToolActionFunctional(){
    // !!! creatting widget list all existting maps and choosing one actual or delete
}

void MainWindow::settingsToolActionFunctional(){
    // !!! creatting widget for setting
}


void MainWindow::runSimulationActionFunctional(){
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(pauseSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");
}
void MainWindow::pauseSimulationActionFunctional(){
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    runSimulationAction->setText(tr("Run"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");
}
void MainWindow::restartSimulationActionFunctional(){
    runSimulationActionFunctional();
}





































