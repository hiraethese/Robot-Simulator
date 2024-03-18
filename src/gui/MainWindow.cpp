#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setApplicationDisplayName("ICP2024");
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
    _CreateMenu();

    setWindowTitle("Simulation");
    _actualPage = SimulationPage;
    _SetSimulationTool();
    _CreateSimModeSlot();
    _SetPallet();
}

void MainWindow::_SetPallet(){
    //palMainWindow = QPalette();
    //palMainWindow.setColor(QPalette::Window, Qt::lightGray);//lightGray);
    //setPalette(palMainWindow);
}

void MainWindow::_DeleteAppWindows(){
    _DeleteActions();
    _DeleteTools();
    _DeleteMenu();
    delete _newMapWind;
    delete _settingsWind;
    delete _simulationWind;
}

void MainWindow::_CreateTools(){

    _settingsToolBar = addToolBar("settings");
    _settingsToolBar->addAction(_settingsToolAction);

    _simulationToolBar = addToolBar("simulation");
    _simulationToolBar->addAction(_simulationToolAction);
}

void MainWindow::_SetSimulationTool(){
    _engineSimRunToolBar = addToolBar("engineSimRun");
    _engineSimRunToolBar->addAction(_runSimulationAction);
    _engineSimRunToolBar->addAction(_restartSimulationAction);

    _simulationIdToolBar = addToolBar("simulationId");
    _labelSimIdToolBar = new QLabel("Simulation: ");
    _simulationIdToolBar->addWidget(_labelSimIdToolBar);
    _lineMapNameSimIdToolBar = new QLineEdit();
    _lineMapNameSimIdToolBar->setReadOnly(true);
    _lineMapNameSimIdToolBar->setFixedWidth(500);
    _simulationIdToolBar->addWidget(_lineMapNameSimIdToolBar);

    _helpToolBar = addToolBar("help");
    _helpToolBar->addAction(_helpToolAction);

}
void MainWindow::_UnsetSimulationTool(){
    removeToolBar(_engineSimRunToolBar);
    removeToolBar(_simulationIdToolBar);
    removeToolBar(_helpToolBar);
    delete _labelSimIdToolBar;
    delete _lineMapNameSimIdToolBar;
    delete _engineSimRunToolBar;
    delete _simulationIdToolBar;
    delete _helpToolBar;
}

void MainWindow::_SetSettingsTool(){
    _newSimulationIdToolBar = addToolBar("engineNewSimulation");;
    _newLabelSimIdToolBar = new QLabel("New simulation: ");
    _newSimulationIdToolBar->addWidget(_newLabelSimIdToolBar);
    _newLineMapNameSimIdToolBar = new QLineEdit();
    _newLineMapNameSimIdToolBar->setFixedWidth(500);
    _newSimulationIdToolBar->addWidget(_newLineMapNameSimIdToolBar);
    _newSimulationButton = new QPushButton("set");
    _newSimulationIdToolBar->addWidget(_newSimulationButton);
    connect(_newSimulationButton, &QPushButton::clicked, this, &MainWindow::_GetNewSimToParserSlot);
}

void MainWindow::_UnsetSettingsTool(){
    removeToolBar(_newSimulationIdToolBar);
    delete _newLabelSimIdToolBar;
    delete _newLineMapNameSimIdToolBar;
    delete _newSimulationButton;
}

void MainWindow::_DeleteTools(){

    delete _settingsToolBar;
    delete _simulationToolBar;
    if(_actualPage == SimulationPage)
        _UnsetSimulationTool();
    else
        _UnsetSettingsTool();
}

void MainWindow::_CreateActions(){
    _helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(_helpToolAction, &QAction::triggered, this, &MainWindow::_HelpTextToolActionSlot);

    _settingsToolAction = new QAction(QIcon(":/icons/settingsTool.png"), "&Settings", this);
    connect(_settingsToolAction, &QAction::triggered, this, &MainWindow::_SettingsToolActionSlot);

    _simulationToolAction = new QAction(QIcon(":/icons/simulationTool.png"), "&Simulation", this);
    connect(_simulationToolAction, &QAction::triggered, this, &MainWindow::_SimulationToolActionSlot);


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
    disconnect(_simulationToolAction, 0, 0, 0);
    delete _helpToolAction;
    delete _settingsToolAction;
    delete _simulationToolAction;
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

    _simulationWind->RunSimScene();
}
void MainWindow::_PauseSimulationActionSlot(){

    _core->SetRunSim(false);
    _simulationWind->StopSimScene();
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
        _simulationWind->StoreSimScene();
    }
    _settingsWind->close();
}

void MainWindow::_SettingsToolActionSlot(){
    if(_actualPage != SettingsPage){
        _actualPage = SettingsPage;
        setWindowTitle("Settings");

        if(_core->IsSimRun())
            _PauseSimulationActionSlot();
        /*_settingsWind->SetMapValue(QString::fromStdString(_core->GetMapValue()));
        _settingsWind->SetSpeedValue(_core->GetSpeedValue());
        _settingsWind->SetAngleValue(_core->GetAngleValue());
        _settingsWind->show();*/
        _UnsetSimulationTool();
        _SetSettingsTool();
        _simulationWind->UnsetSimulationEngine();
    }
}


void MainWindow::_SimulationToolActionSlot(){
    if(_actualPage != SimulationPage){
        _actualPage = SimulationPage;
        setWindowTitle("Simulation");
        _UnsetSettingsTool();
        _SetSimulationTool();
        _simulationWind->SetSimulationEngine();
    }
}


void MainWindow::_GetNewSimToParserSlot(){
    std::cout << "NEW SIM: " << _newLineMapNameSimIdToolBar->text().toStdString() << std::endl;
}

void MainWindow::_CreateSimulationWindow(){

    _simulationWind = new SimulationWindow(this);
    setCentralWidget(_simulationWind);
}


void MainWindow::_CreateMenu(){
    appMenu = menuBar()->addMenu("Menu");
    simulationModeAction = appMenu->addAction("Simulation");
    connect(simulationModeAction, &QAction::triggered, this, &MainWindow::_CreateSimModeSlot);
    downloadNewModeMapAction = appMenu->addAction("Download map");
    connect(downloadNewModeMapAction, &QAction::triggered, this, &MainWindow::_CreateNewMapModeSlot);
    buildMapModeAction = appMenu->addAction("Build map");
    connect(buildMapModeAction, &QAction::triggered, this, &MainWindow::_CreateBuildMapModeSlot);
}

void MainWindow::_DeleteMenu(){
    delete simulationModeAction;
    delete downloadNewModeMapAction;
    delete buildMapModeAction;
    delete appMenu;
}

void MainWindow::_CreateNewMapModeSlot(){
    if(_newMapWind != nullptr){
        delete _newMapWind;
    }
    _newMapWind = new NewMapWindow();
    connect(_newMapWind->downloadButton, &QPushButton::clicked, this, &MainWindow::_StoreNewMap);
    _newMapWind->show();
}

void MainWindow::_CreateBuildMapModeSlot(){
    // TODO: stop sim run
    // TODO: clean set tools
    // TODO: create settings tools
    // TODO: create settings buttons

}
void MainWindow::_CreateSimModeSlot(){
    // TODO: clean sim tools
    // TODO: clean sim buttons
    // TODO: create build tools
}

void MainWindow::_StoreNewMap(){
    // TODO: stop sim run
    std::cout << "STORE NEW MAP: " << _newMapWind->GetNewMapPath() << std::endl;
    delete _newMapWind;
    _newMapWind = nullptr;
}































