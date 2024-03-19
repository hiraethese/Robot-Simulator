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



// ************************************  PART APPLICATION    *********************************************************
void MainWindow::_CreateAppWindows(){
    _CreateSimulationWindow();
    _CreateMenu();
    _CreateSimModeSlot();
    _SetPallet();
}

void MainWindow::_SetPallet(){
    //palMainWindow = QPalette();
    //palMainWindow.setColor(QPalette::Window, Qt::lightGray);//lightGray);
    //setPalette(palMainWindow);
}

void MainWindow::_DeleteAppWindows(){

    _DeleteTools();
    _DeleteMenu();
    if(_newMapWind){
        delete _newMapWind;
    }
    if(_settingsWind){ // TODO: close settings wind if close main wind
        delete _settingsWind;
    }
    if(_wallSettingsWindow){
        delete _wallSettingsWindow;
    }
    delete _simulationWind;

}


void MainWindow::_DeleteTools(){

    if(_actualPage == SimulationPage){
        _DeleteSimModeTools();
    }

}

// ************************************  PART MENU    *********************************************************

void MainWindow::_CreateMenu(){

    appMenu = menuBar()->addMenu("Menu");

    simulationModeAction = appMenu->addAction("Simulation");
    connect(simulationModeAction, &QAction::triggered, this, &MainWindow::_CreateSimModeSlot);

    buildSubMenu = appMenu->addMenu("Build");

    buildMapModeAction = buildSubMenu->addAction("Build map");
    connect(buildMapModeAction, &QAction::triggered, this, &MainWindow::_CreateBuildMapModeSlot);

    buildUserRobotLayout = buildSubMenu->addAction("User robot layout");
    connect(buildUserRobotLayout, &QAction::triggered, this, &MainWindow::_BuildUserRobotLayoutSlot);

    buildBotRobotLayout = buildSubMenu->addAction("Bot robot layout");
    connect(buildBotRobotLayout, &QAction::triggered, this, &MainWindow::_BuildBotRobotLayoutSlot);

    buildWallLayout = buildSubMenu->addAction("Wall layout");
    connect(buildWallLayout, &QAction::triggered, this, &MainWindow::_BuildWallLayoutSlot);


    downloadNewModeMapAction = appMenu->addAction("Download map");
    connect(downloadNewModeMapAction, &QAction::triggered, this, &MainWindow::_CreateNewMapModeSlot);

}

void MainWindow::_DeleteMenu(){
    delete simulationModeAction;
    delete downloadNewModeMapAction;
    delete buildMapModeAction;
    delete buildUserRobotLayout;
    delete buildBotRobotLayout;
    delete buildWallLayout;
    delete buildSubMenu;
    delete appMenu;
}

void MainWindow::_BuildUserRobotLayoutSlot(){

    if(_settingsWind){
        delete _settingsWind;
    }
    _settingsWind = new SettingsWindow();
    _settingsWind->show();

}

void MainWindow::_BuildBotRobotLayoutSlot(){

    if(_settingsWind){
        delete _settingsWind;
    }
    _settingsWind = new SettingsWindow();
    _settingsWind->show();


}

void MainWindow::_BuildWallLayoutSlot(){

    if(_wallSettingsWindow){
        delete _wallSettingsWindow;
    }
    _wallSettingsWindow = new WallSettingsWindow();
    _wallSettingsWindow->show();


}
// ************************************  PART NEW MAP MODE    *********************************************************

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

    setWindowTitle("Build map");
    if(_actualPage != BuildPage){
        _DeleteSimModeTools();
        _simulationWind->DeleteSimulationEngineLayout();
        _CreateBuildModeTools();
        _actualPage = BuildPage;
    }
}
void MainWindow::_CreateSimModeSlot(){
    // TODO: clean sim tools
    // TODO: clean sim buttons
    // TODO: create build tools

    setWindowTitle("Simulation");
    if(_actualPage != SimulationPage){
        _DeleteBuildModeTools();
        _CreateSimModeTools();
        _simulationWind->CreateSimulationEngineLayout();
        _actualPage = SimulationPage;
    }
}

void MainWindow::_StoreNewMap(){
    // TODO: stop sim run
    std::cout << "STORE NEW MAP: " << _newMapWind->GetNewMapPath() << std::endl;
    delete _newMapWind;
    _newMapWind = nullptr;
}

// ************************************  PART SIM MODE    *********************************************************

void MainWindow::_CreateSimModeTools(){

    _helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(_helpToolAction, &QAction::triggered, this, &MainWindow::_HelpTextToolActionSlot);

    _runSimulationAction = new QAction(QIcon(":/icons/playTool.png"), "&Run", this);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_RunSimulationActionSlot);

    _restartSimulationAction = new QAction(QIcon(":/icons/restartTool.png"), "&Continue", this);
    connect(_restartSimulationAction, &QAction::triggered, this, &MainWindow::_RestartSimulationActionSlot);

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

void MainWindow::_DeleteSimModeTools(){

    disconnect(_helpToolAction, 0, 0, 0);
    disconnect(_runSimulationAction, 0, 0, 0);
    disconnect(_restartSimulationAction, 0, 0, 0);
    delete _helpToolAction;
    delete _runSimulationAction;
    delete _restartSimulationAction;
    removeToolBar(_engineSimRunToolBar);
    removeToolBar(_simulationIdToolBar);
    removeToolBar(_helpToolBar);
    delete _labelSimIdToolBar;
    delete _lineMapNameSimIdToolBar;
    delete _engineSimRunToolBar;
    delete _simulationIdToolBar;
    delete _helpToolBar;

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


// ************************************  PART SIM WIND    *********************************************************


void MainWindow::_CreateSimulationWindow(){

    _simulationWind = new SimulationWindow(this);
    setCentralWidget(_simulationWind);
}


// ************************************  PART BUILD MODE    *********************************************************
void MainWindow::_CreateBuildModeTools(){

    _cursorAction = new QAction(QIcon(":/icons/cursorTool.png"), "Cursor", this);
    connect(_cursorAction, &QAction::triggered, this, &MainWindow::_CursorActionSlot);

    _buildUserRobotAction = new QAction(QIcon(":/icons/userRobotTool.png"), "User robot", this);
    connect(_buildUserRobotAction, &QAction::triggered, this, &MainWindow::_BuildUserRobotActionSlot);

    _buildBotRobotAction = new QAction(QIcon(":/icons/botRobotTool.png"), "Bot robot", this);
    connect(_buildBotRobotAction, &QAction::triggered, this, &MainWindow::_BuildBotRobotActionSlot);

    _buildWallAction = new QAction(QIcon(":/icons/wallTool.png"), "Wall", this);
    connect(_buildWallAction, &QAction::triggered, this, &MainWindow::_BuildWallActionSlot);

    _hummerAction = new QAction(QIcon(":/icons/hummerTool.png"), "Object settings", this);
    connect(_hummerAction, &QAction::triggered, this, &MainWindow::_HummerActionSlot);

    _engineBuildToolBar = addToolBar("engineBuild");
    _engineBuildToolBar->addAction(_hummerAction);
    _engineBuildToolBar->addAction(_buildUserRobotAction);
    _engineBuildToolBar->addAction(_buildBotRobotAction);
    _engineBuildToolBar->addAction(_buildWallAction);
    _engineBuildToolBar->addAction(_cursorAction);
}

void MainWindow::_DeleteBuildModeTools(){
    if(_actualPage != NotSetPage){
        disconnect(_cursorAction, 0, 0, 0);
        disconnect(_buildUserRobotAction, 0, 0, 0);
        disconnect(_buildBotRobotAction, 0, 0, 0);
        disconnect(_buildWallAction, 0, 0, 0);
        delete _cursorAction;
        delete _buildUserRobotAction;
        delete _buildBotRobotAction;
        delete _buildWallAction;
        removeToolBar(_engineBuildToolBar);
        delete _engineBuildToolBar;
    }

}

void MainWindow::_CursorActionSlot(){}
void MainWindow::_BuildUserRobotActionSlot(){}
void MainWindow::_BuildBotRobotActionSlot(){}
void MainWindow::_BuildWallActionSlot(){}
void MainWindow::_HummerActionSlot(){}
