#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QApplication::setApplicationDisplayName("ICP2024");
    setWindowTitle("ICP2024");
    setStyleSheet("background-color: lightgray;");
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
    _CreateSettings();
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

    buildUserRobotTemplate = buildSubMenu->addAction("Controlled robot template");  // upd lambda with dependecy injection
    connect(buildUserRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetControlledRobotTemp()); _robotSetWind->exec();});

    buildBotRobotTemplate = buildSubMenu->addAction("Bot robot template");
    connect(buildBotRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetBotRobotTemp());_robotSetWind->exec();});

    buildWallLayout = buildSubMenu->addAction("Wall layout");
    connect(buildWallLayout, &QAction::triggered, this, [=](){_wallSetWind->DownloadDataFromView(_core->GetWallTemplate());_wallSetWind->exec();});


    downloadNewModeMapAction = appMenu->addAction("Download map");
    connect(downloadNewModeMapAction, &QAction::triggered, this, [=](){_simulationWind->StopSimScene();_newMapWind->show();});

}

void MainWindow::_DeleteMenu(){

    delete simulationModeAction;
    delete downloadNewModeMapAction;
    delete buildMapModeAction;
    delete buildUserRobotTemplate;
    delete buildBotRobotTemplate;
    delete buildWallLayout;
    delete buildSubMenu;
    delete appMenu;

}


// ************************************  PART NEW MAP MODE    *********************************************************

void MainWindow::_CreateBuildMapModeSlot(){

    setWindowTitle("Build map");

    if(_actualPage != BuildPage){

        _DeleteSimModeTools();
        _CreateBuildModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(true);
        _actualPage = BuildPage;

    }

}
void MainWindow::_CreateSimModeSlot(){

    setWindowTitle("Simulation");

    if(_actualPage != SimulationPage){

        _DeleteBuildModeTools();
        _CreateSimModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(false);
        _actualPage = SimulationPage;

    }

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

    _runSimulationAction = nullptr;
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
    _runSimulationAction->setText("Pause");
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
    _runSimulationAction->setText("Run");
    _lineMapNameSimIdToolBar->setStyleSheet("background-color: white;");

}

void MainWindow::_RestartSimulationActionSlot(){

    if(_core->IsSimReady()){

        _WarningMsgSimNotSet();
        return;

    }

}


// ************************************  PART SIM WIND    *********************************************************


void MainWindow::_CreateSimulationWindow(){

    _simulationWind = new SimulationWindow(this);
    setCentralWidget(_simulationWind);
    connect(_simulationWind, &SimulationWindow::UperClickSig, this, &MainWindow::_UserClickSimSceneLogicSlot);
}

void MainWindow::_UserClickSimSceneLogicSlot(){
    QPointF* test = _simulationWind->GetUserClick();
    std::cout << "User click on x=" << test->x() << " y=" << test->y() << std::endl;
}
// ************************************  PART BUILD MODE    *********************************************************
void MainWindow::_CreateBuildModeTools(){

    _helpToolAction = new QAction(QIcon(":/icons/helpTool.jpg"), "&Help", this);
    connect(_helpToolAction, &QAction::triggered, this, &MainWindow::_HelpTextToolActionSlot);

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


    _settingsBuildToolBar = addToolBar("settingsBuild");
    _settingsBuildToolBar->addAction(_hummerAction);

    _engineBuildToolBar = addToolBar("engineBuild");
    _engineBuildToolBar->addAction(_buildUserRobotAction);
    _engineBuildToolBar->addAction(_buildBotRobotAction);
    _engineBuildToolBar->addAction(_buildWallAction);
    _engineBuildToolBar->addAction(_cursorAction);

    _statusModeBuildToolBar = addToolBar("statusModeBuild");
    _statusModeLabel = new QLabel("Build mode: ");
    _statusModeBuildToolBar->addWidget(_statusModeLabel);
    _statusModeLine = new QLineEdit();
    _statusModeLine->setReadOnly(true);
    _statusModeLine->setFixedWidth(150);
    _statusModeBuildToolBar->addWidget(_statusModeLine);


    _helpToolBar = addToolBar("help");
    _helpToolBar->addAction(_helpToolAction);

}

void MainWindow::_DeleteBuildModeTools(){

    if(_actualPage != NotSetPage){

        disconnect(_cursorAction, 0, 0, 0);
        disconnect(_buildUserRobotAction, 0, 0, 0);
        disconnect(_buildBotRobotAction, 0, 0, 0);
        disconnect(_buildWallAction, 0, 0, 0);
        disconnect(_helpToolAction, 0, 0, 0);
        delete _cursorAction;
        delete _buildUserRobotAction;
        delete _buildBotRobotAction;
        delete _buildWallAction;
        delete _statusModeLabel;
        delete _statusModeLine;
        removeToolBar(_settingsBuildToolBar);
        removeToolBar(_engineBuildToolBar);
        removeToolBar(_statusModeBuildToolBar);
        delete _settingsBuildToolBar;
        delete _engineBuildToolBar;
        delete _statusModeBuildToolBar;

    }

}

void MainWindow::_CursorActionSlot(){

    _statusModeLine->setText("Interaction");

}

void MainWindow::_BuildUserRobotActionSlot(){

    _statusModeLine->setText("Build users robot");

}

void MainWindow::_BuildBotRobotActionSlot(){

    _statusModeLine->setText("Build bot robots");

}


void MainWindow::_BuildWallActionSlot(){

    _statusModeLine->setText("Build walls");

}
void MainWindow::_HummerActionSlot(){

}


// ************************************  PART BUILD MODE    *********************************************************

void MainWindow::_CreateSettings(){

    _newMapWind = new NewMapSetting(this);
    connect(_newMapWind, &NewMapSetting::downloadSig, this, &MainWindow::_PushNewMapToCoreSlot);

    _robotSetWind = new RobotSetting(this, "Robot settings");
    connect(_robotSetWind, &RobotSetting::setSig, this, [=](){std::cout << "CLICK SET ROBOT SETTINGS" << std::endl;});  // TODO : create slot with prototype function for all settings with setting new data

    _wallSetWind = new WallSetting(this, "Wall settings");
    connect(_wallSetWind, &WallSetting::setSig, this, [=](){std::cout << "CLICK SET WALL SETTINGS" << std::endl;});  // TODO : create slot with prototype function for all settings with setting new data

}



void MainWindow::_PushNewMapToCoreSlot(){

    int code = _core->LoadingMap(_newMapWind->GetNewMapPath());
    std::cout << "code: " << code <<std::endl;

    if(!code){
        _lineMapNameSimIdToolBar->setText(QString::fromStdString(_core->GetMapValue()));
        _simulationWind->LoadSimScene();

    }

}
