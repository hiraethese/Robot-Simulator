#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("");
    _core = Core::getInstance();

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
    connect(helpToolAction, &QAction::triggered, this, &MainWindow::helpTextToolActionSlot);

    settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(settingsToolAction, &QAction::triggered, this, &MainWindow::settingsToolActionSlot);

    runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(runSimulationAction, &QAction::triggered, this, &MainWindow::runSimulationActionSlot);

    restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(restartSimulationAction, &QAction::triggered, this, &MainWindow::restartSimulationActionSlot);
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
void MainWindow::helpTextToolActionSlot(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::runSimulationActionSlot(){
    if(!_core->IsSimReady()){
        warningMsgSimNotSet();
        return;
    }
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, &QAction::triggered, this, &MainWindow::pauseSimulationActionSlot);
    runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");

    _core->SetRunSim(true);

    simWind->runSimGUI();
}
void MainWindow::pauseSimulationActionSlot(){

    _core->SetRunSim(false);
    simWind->stopSimGUI();
    disconnect(runSimulationAction, 0, 0, 0);
    connect(runSimulationAction, &QAction::triggered, this, &MainWindow::runSimulationActionSlot);
    runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    runSimulationAction->setText(tr("Run"));
    lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");
}

void MainWindow::restartSimulationActionSlot(){
    //runSimulationActionSlot();
    if(_core->IsSimReady()){
        warningMsgSimNotSet();
        return;
    }
}
// **************************************************************************************************************



// ************************************  SETTINGS       *********************************************************
void MainWindow::createSettings(){
    settings = new SettingsWindow();
    connect(settings->setPushButton, &QPushButton::clicked, this, &MainWindow::updateSettingsSlot);
    settings->hide();
}

void MainWindow::deleteSettings(){
    disconnect(settings, 0, 0, 0);
    delete settings;
}
void MainWindow::updateSettingsSlot(){

    // !!! try catch filtering errors
    //contr_set_new_settings(settings->isSetMapValue(), settings->getMapValue().toStdString(), settings->isSetSpeedValue(), settings->getSpeedValue(), settings->isSetAngleValue(), settings->getAngleValue());
    //
    
    if(settings->isSetMapValue()){
        lineMapNameSimIdToolBar->setText(settings->getMapValue());
        simWind->storeSimGUI();
    }
    settings->close();
}
void MainWindow::settingsToolActionSlot(){
    if(_core->IsSimRun()) pauseSimulationActionSlot();
    // *** should be set by core ***
    settings->setMapValue(QString::fromStdString(_core->GetMapValue()));
    settings->setSpeedValue(_core->GetSpeedValue());
    settings->setAngleValue(_core->GetAngleValue());
    // *** *** *** *** *** *** *** ***
    settings->show();
}
// **************************************************************************************************************



// ************************************  SIMULATION     *********************************************************
void MainWindow::createSimulationWindow(){

    simWind = new SimulationWindow(this);
    setCentralWidget(simWind);
}

// **************************************************************************************************************





































