#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("ICP2024");
    _core = Core::getInstance();

    _CreateAppWindows();
}


MainWindow::~MainWindow()
{
    _DeleteAppWindows();
    delete ui;
}



// ************************************  APPLICATION    *********************************************************
void MainWindow::_CreateAppWindows(){
    _CreateSimulationWindow();
    _CreateSettings();
    _CreateActions();
    _CreateTools();
}


void MainWindow::_DeleteAppWindows(){
    _DeleteActions();
    _DeleteTools();
    delete _settingsWind;
    delete _simulationWind;
}

void MainWindow::_CreateTools(){

    _settingsToolBar = addToolBar(tr("settings"));
    _settingsToolBar->addAction(_settingsToolAction);

    _engineSimRunToolBar = addToolBar(tr("engineSimRun"));
    _engineSimRunToolBar->addAction(_runSimulationAction);
    _engineSimRunToolBar->addAction(_restartSimulationAction);

    _simulationIdToolBar = addToolBar(tr("simulationId"));
    _labelSimIdToolBar = new QLabel("Simulation: ");
    _simulationIdToolBar->addWidget(_labelSimIdToolBar);
    _lineMapNameSimIdToolBar = new QLineEdit();
    _lineMapNameSimIdToolBar->setReadOnly(true);
    _lineMapNameSimIdToolBar->setFixedWidth(500);
    _simulationIdToolBar->addWidget(_lineMapNameSimIdToolBar);

    _helpToolBar = addToolBar(tr("help"));
    _helpToolBar->addAction(_helpToolAction);

}


void MainWindow::_DeleteTools(){
    delete _labelSimIdToolBar;
    delete _lineMapNameSimIdToolBar;
    delete _helpToolBar;
    delete _settingsToolBar;
    delete _engineSimRunToolBar;
    delete _simulationIdToolBar;
}

void MainWindow::_CreateActions(){
    _simulationMenuAction = new QAction();
    _settingsMenuAction = new QAction();
    connect(_simulationMenuAction, &QAction::triggered, this, &MainWindow::_SimulationMenuActionSlot);
    connect(_settingsMenuAction, &QAction::triggered, this, &MainWindow::_SettingsMenuActionSlot);

    _helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(_helpToolAction, &QAction::triggered, this, &MainWindow::_HelpTextToolActionSlot);

    _settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(_settingsToolAction, &QAction::triggered, this, &MainWindow::_SettingsToolActionSlot);

    _runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_RunSimulationActionSlot);

    _restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(_restartSimulationAction, &QAction::triggered, this, &MainWindow::_RestartSimulationActionSlot);
}


void MainWindow::_DeleteActions(){
    disconnect(_helpToolAction, 0, 0, 0);
    disconnect(_settingsToolAction, 0, 0, 0);
    disconnect(_runSimulationAction, 0, 0, 0);
    disconnect(_restartSimulationAction, 0, 0, 0);
    delete _helpToolAction;
    delete _settingsToolAction;
    delete _runSimulationAction;
    delete _restartSimulationAction;
}
void MainWindow::_HelpTextToolActionSlot(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::_RunSimulationActionSlot(){
    if(!_core->IsSimReady()){
        _WarningMsgSimNotSet();
        return;
    }
    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_PauseSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/pauseTool.png"));
    _lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");

    _core->SetRunSim(true);

    _simulationWind->RunSimGUI();
}
void MainWindow::_PauseSimulationActionSlot(){

    _core->SetRunSim(false);
    _simulationWind->StopSimGUI();
    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_RunSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    _runSimulationAction->setText(tr("Run"));
    _lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");
}

void MainWindow::_RestartSimulationActionSlot(){
    //runSimulationActionSlot();
    if(_core->IsSimReady()){
        _WarningMsgSimNotSet();
        return;
    }
}

void MainWindow::_CreateSettings(){
    _settingsWind = new SettingsWindow();
    connect(_settingsWind->setPushButton, &QPushButton::clicked, this, &MainWindow::_UpdateSettingsSlot);
    _settingsWind->hide();
}

void MainWindow::_DeleteSettings(){
    disconnect(_settingsWind, 0, 0, 0);
    delete _settingsWind;
}

void MainWindow::_UpdateSettingsSlot(){

    // !!! try catch filtering errors
    //contr_set_new_settings(settings->IsSetMapValue(), settings->GetMapValue().toStdString(), settings->IsSetSpeedValue(), settings->GetSpeedValue(), settings->IsSetAngleValue(), settings->GetAngleValue());
    //
    
    if(_settingsWind->IsSetMapValue()){
        _lineMapNameSimIdToolBar->setText(_settingsWind->GetMapValue());
        _simulationWind->StoreSimGUI();
    }
    _settingsWind->close();
}

void MainWindow::_SettingsToolActionSlot(){
    if(_core->IsSimRun()) _PauseSimulationActionSlot();
    // *** should be set by core ***
    _settingsWind->SetMapValue(QString::fromStdString(_core->GetMapValue()));
    _settingsWind->SetSpeedValue(_core->GetSpeedValue());
    _settingsWind->SetAngleValue(_core->GetAngleValue());
    // *** *** *** *** *** *** *** ***
    _settingsWind->show();
}

void MainWindow::_CreateSimulationWindow(){

    _simulationWind = new SimulationWindow(this);
    setCentralWidget(_simulationWind);
}


void MainWindow::_SimulationMenuActionSlot(){
    std::cout << "SIM MENU !!!" << std::endl;
}
void MainWindow::_SettingsMenuActionSlot(){
    std::cout << "SET MENU !!!" << std::endl;

}



































