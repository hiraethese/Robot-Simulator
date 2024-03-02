#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    //QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("");
    createAppWindows();
}


MainWindow::~MainWindow()
{
    deleteAppWindows();
    delete ui;
}



// ************************************  APPLICATION    *********************************************************
void MainWindow::createAppWindows(){
    createSimulationWindow();
    createSettings();
    createActions();
    createTools();
}


void MainWindow::deleteAppWindows(){
    deleteActions();
    deleteTools();
    deleteSimulationWindow();
    delete settings;
    delete simWind;
}
// **************************************************************************************************************



// ************************************  BAR && ACTIONS *********************************************************
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

    helpToolBar = addToolBar(tr("help"));
    helpToolBar->addAction(helpToolAction);

}


void MainWindow::deleteTools(){
    delete labelSimIdToolBar;
    delete lineMapNameSimIdToolBar;
    delete helpToolBar;
    delete settingsToolBar;
    delete engineSimRunToolBar;
    delete simulationIdToolBar;
}

void MainWindow::createActions(){
    helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(helpToolAction, SIGNAL(triggered()), this, SLOT(helpTextToolActionFunctional()));

    settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(settingsToolAction, SIGNAL(triggered()), this, SLOT(settingsToolActionFunctional()));

    runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));

    restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(restartSimulationAction, SIGNAL(triggered()), this, SLOT(restartSimulationActionFunctional()));
}


void MainWindow::deleteActions(){
    disconnect(helpToolAction, 0, 0, 0);
    disconnect(settingsToolAction, 0, 0, 0);
    disconnect(runSimulationAction, 0, 0, 0);
    disconnect(restartSimulationAction, 0, 0, 0);
    delete helpToolAction;
    delete settingsToolAction;
    delete runSimulationAction;
    delete restartSimulationAction;
}
void MainWindow::helpTextToolActionFunctional(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::runSimulationActionFunctional(){
    if(!devflagMapIsSet){
        warningMsgSimNotSet();
        return;
    }
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(pauseSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");

    simWind->runSimObject();
}
void MainWindow::pauseSimulationActionFunctional(){
    if(!devflagMapIsSet){
        warningMsgSimNotSet();
        return;
    }
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, SIGNAL(triggered()), this, SLOT(runSimulationActionFunctional()));
    runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    runSimulationAction->setText(tr("Run"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");

    simWind->pauseSimObject();
}

void MainWindow::restartSimulationActionFunctional(){
    //runSimulationActionFunctional();
    if(!devflagMapIsSet){
        warningMsgSimNotSet();
        return;
    }
}
// **************************************************************************************************************



// ************************************  SETTINGS       *********************************************************
void MainWindow::createSettings(){
    settings = new SettingsWindow();
    connect(settings->setPushButton, SIGNAL(clicked()), this, SLOT(updateSettings()));
    settings->hide();
}

void MainWindow::deleteSettings(){
    disconnect(settings, 0, 0, 0);
    delete settings;
}
void MainWindow::updateSettings(){
    if(settings->isSetMapValue()){
        devflagMapIsSet = true;
        simulationMap = settings->getMapValue();
        lineMapNameSimIdToolBar->setText(simulationMap);
        simWind->storeSimulationMap();
    }
    if(settings->isSetSpeedValue()) devSimulationSpeed = settings->getSpeedValue();
    if(settings->isSetCornerValue()) devSimulationCorner = settings->getCornerValue();
    settings->close();
}
void MainWindow::settingsToolActionFunctional(){
    // *** should be set by core ***
    settings->setMapValue(simulationMap);
    settings->setSpeedValue(devSimulationSpeed);
    settings->setCornerValue(devSimulationCorner);
    // *** *** *** *** *** *** *** ***
    settings->show();
}
// **************************************************************************************************************



// ************************************  SIMULATION     *********************************************************
void MainWindow::createSimulationWindow(){

    simWind = new SimulationWindow(this);
    setCentralWidget(simWind);
}

void MainWindow::deleteSimulationWindow(){
    //delete simWind;
}
// **************************************************************************************************************





































