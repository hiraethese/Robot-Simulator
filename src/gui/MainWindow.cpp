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

    _CreateTools();

    _CreateSimModeSlot();

}

void MainWindow::_DeleteAppWindows(){

    _DeleteTools();

    _DeleteMenu();

    delete _simulationWind;

}


void MainWindow::_CreateTools(){

    _helpToolAction = new QAction(QIcon(":/icons/helpTool.png"), "&Help", this);
    connect(_helpToolAction, &QAction::triggered, this, &MainWindow::_HelpTextToolActionSlot);

    _helpToolBar = addToolBar("help");
    _helpToolBar->addAction(_helpToolAction);

}

void MainWindow::_DeleteTools(){

    if(_actualPage == SimulationPage){

        _DeleteSimModeTools();

    }
    else{

        _DeleteBuildModeTools();

    }


    disconnect(_helpToolAction, 0, 0, 0);
    delete _helpToolAction;
    removeToolBar(_helpToolBar);
    delete _helpToolBar;

}

// ************************************  PART MENU    *********************************************************

void MainWindow::_CreateMenu(){

    appMenu = menuBar()->addMenu("Menu");

    templatesSubMenu = appMenu->addMenu("Templates");

    buildUserRobotTemplate = templatesSubMenu->addAction("Controlled robot");  // upd lambda with dependecy injection
    connect(buildUserRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetControlledRobotTemp()); _robotSetWind->exec();});

    buildBotRobotTemplate = templatesSubMenu->addAction("Bot robot");
    connect(buildBotRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetBotRobotTemp());_robotSetWind->exec();});

    buildWallLayout = templatesSubMenu->addAction("Wall");
    connect(buildWallLayout, &QAction::triggered, this, [=](){_wallSetWind->DownloadDataFromView(_core->GetWallTemplate());_wallSetWind->exec();});

    simulationModeAction = appMenu->addAction("Simulation");
    connect(simulationModeAction, &QAction::triggered, this, &MainWindow::_CreateSimModeSlot);

    buildMapModeAction = appMenu->addAction("Build map");
    connect(buildMapModeAction, &QAction::triggered, this, &MainWindow::_CreateBuildMapModeSlot);

    downloadNewModeMapAction = appMenu->addAction("Download map");
    connect(downloadNewModeMapAction, &QAction::triggered, this, [=](){_simulationWind->StopSimScene();_newMapWind->exec();});

}

void MainWindow::_DeleteMenu(){

    delete simulationModeAction;
    delete downloadNewModeMapAction;
    delete buildMapModeAction;
    delete buildUserRobotTemplate;
    delete buildBotRobotTemplate;
    delete buildWallLayout;
    delete templatesSubMenu;
    delete appMenu;

}


// ************************************  PART SIM MODE    *********************************************************

void MainWindow::_CreateSimModeSlot(){

    setWindowTitle("Simulation");

    if(_actualPage != SimulationPage){

        _DeleteBuildModeTools();
        _CreateSimModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(false);
        _actualPage = SimulationPage;

    }

}

void MainWindow::_CreateSimModeTools(){

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
    _lineMapNameSimIdToolBar->setText(QString::fromStdString(_core->GetMapValue()));

    _simulationIdToolBar->addWidget(_lineMapNameSimIdToolBar);

}


void MainWindow::_DeleteSimModeTools(){

    disconnect(_runSimulationAction, 0, 0, 0);
    disconnect(_restartSimulationAction, 0, 0, 0);

    delete _runSimulationAction;

    _runSimulationAction = nullptr;
    delete _restartSimulationAction;

    removeToolBar(_engineSimRunToolBar);
    removeToolBar(_simulationIdToolBar);
    delete _labelSimIdToolBar;
    delete _lineMapNameSimIdToolBar;
    delete _engineSimRunToolBar;
    delete _simulationIdToolBar;

}


void MainWindow::_HelpTextToolActionSlot(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::_RunSimulationActionSlot(){

    if(!_core->IsSimReady()){  // check is prepared simulation map to running

        _WarningMsgSimNotSet();
        return;

    }

    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_PauseSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/pauseTool.svg"));
    _runSimulationAction->setText("Pause");
    _lineMapNameSimIdToolBar->setStyleSheet("background-color: lightgreen;");

    _core->SetRunSim(true);

    _simulationWind->setFocus();

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
    connect(_simulationWind, &SimulationWindow::RequestSimObjSig, this, &MainWindow::_RequestSimObjSlot);
}

void MainWindow::_UserClickSimSceneLogicSlot(){

    QPointF* test = _simulationWind->GetUserClick();

    _xCursorTouchLine->setText(QString("%1").arg(test->x()));
    _yCursorTouchLine->setText(QString("%1").arg(test->y()));

}

void MainWindow::_RequestSimObjSlot(int orderIndex){
    std::cout << "Order index: " << orderIndex << std::endl;
/*
    TODO:
        -- request by core view about simobj
        -- show settings window about it
    after simulation of working
*/
    if(orderIndex == 1){
        _robotSetWind->DownloadDataFromView(_core->GetControlledRobotTemp());
        _robotSetWind->SetUnsetDeleteButton(true);
        _robotSetWind->exec();
    }
    else{
        _wallSetWind->DownloadDataFromView(_core->GetControlledRobotTemp());
        _wallSetWind->SetUnsetDeleteButton(true);
        _wallSetWind->exec();
    }
}

// ************************************  PART BUILD MODE    *********************************************************

void MainWindow::_CreateBuildMapModeSlot(){

    setWindowTitle("Build map");

    if(_actualPage != BuildPage){

        _DeleteSimModeTools();
        _CreateBuildModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(true);
        _actualPage = BuildPage;

    }

    emit _cursorAction->triggered();  // default on cursor

}

void MainWindow::_CreateBuildModeTools(){

    _cursorAction = new QAction(QIcon(":/icons/cursorTool.png"), "Cursor", this);
    connect(_cursorAction, &QAction::triggered, this, &MainWindow::_CursorActionSlot);

    _buildUserRobotAction = new QAction(QIcon(":/icons/userRobotTool.png"), "User robot", this);
    connect(_buildUserRobotAction, &QAction::triggered, this, &MainWindow::_BuildUserRobotActionSlot);

    _buildBotRobotAction = new QAction(QIcon(":/icons/botRobotTool.png"), "Bot robot", this);
    connect(_buildBotRobotAction, &QAction::triggered, this, &MainWindow::_BuildBotRobotActionSlot);

    _buildWallAction = new QAction(QIcon(":/icons/wallTool.png"), "Wall", this);
    connect(_buildWallAction, &QAction::triggered, this, &MainWindow::_BuildWallActionSlot);

    //_hummerAction = new QAction(QIcon(":/icons/hummerTool.png"), "Object settings", this);
    //connect(_hummerAction, &QAction::triggered, this, &MainWindow::_HummerActionSlot);


    //_settingsBuildToolBar = addToolBar("settingsBuild");
    //_settingsBuildToolBar->addAction(_hummerAction);

    _engineBuildToolBar = addToolBar("engineBuild");
    _engineBuildToolBar->addAction(_buildUserRobotAction);
    _engineBuildToolBar->addAction(_buildBotRobotAction);
    _engineBuildToolBar->addAction(_buildWallAction);

    _engineCursorToolBar = addToolBar("engineCursor");
    _engineCursorToolBar->addAction(_cursorAction);
    _xCursorTouchLab = new QLabel("X");
    _xCursorTouchLine = new QLineEdit();
    _xCursorTouchLine->setReadOnly(true);
    _xCursorTouchLine->setFixedWidth(35);
    _yCursorTouchLab = new QLabel("Y");
    _yCursorTouchLine = new QLineEdit();
    _yCursorTouchLine->setReadOnly(true);
    _yCursorTouchLine->setFixedWidth(35);
    _engineCursorToolBar->addWidget(_xCursorTouchLab);
    _engineCursorToolBar->addWidget(_xCursorTouchLine);
    _engineCursorToolBar->addWidget(_yCursorTouchLab);
    _engineCursorToolBar->addWidget(_yCursorTouchLine);

    _statusModeBuildToolBar = addToolBar("statusModeBuild");
    _statusModeLabel = new QLabel("Build mode: ");
    _statusModeBuildToolBar->addWidget(_statusModeLabel);
    _statusModeLine = new QLineEdit();
    _statusModeLine->setReadOnly(true);
    _statusModeLine->setFixedWidth(150);
    _statusModeBuildToolBar->addWidget(_statusModeLine);

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
        delete _statusModeLabel;
        delete _statusModeLine;
        delete _xCursorTouchLab;
        delete _xCursorTouchLine;
        delete _yCursorTouchLab;
        delete _yCursorTouchLine;
        //removeToolBar(_settingsBuildToolBar);
        removeToolBar(_engineBuildToolBar);
        removeToolBar(_engineCursorToolBar);
        removeToolBar(_statusModeBuildToolBar);
        //delete _settingsBuildToolBar;
        delete _engineBuildToolBar;
        delete _engineCursorToolBar;
        delete _statusModeBuildToolBar;

    }

}

void MainWindow::_CursorActionSlot(){

    _buildState = Cursor;
    _statusModeLine->setText("Interaction");

}

void MainWindow::_BuildUserRobotActionSlot(){

    _buildState = ControllRobotBuild;
    _statusModeLine->setText("Build users robot");

}

void MainWindow::_BuildBotRobotActionSlot(){

    _buildState = BotRobotBuild;
    _statusModeLine->setText("Build bot robots");

}


void MainWindow::_BuildWallActionSlot(){

    _buildState = WallBuild;
    _statusModeLine->setText("Build walls");

}

/*void MainWindow::_HummerActionSlot(){

}*/


// ************************************  PART SETTINGS MODE    *********************************************************

void MainWindow::_CreateSettings(){

    _newMapWind = new NewMapSetting(this);
    connect(_newMapWind, &NewMapSetting::downloadSig, this, &MainWindow::_PushNewMapToCoreSlot);

    _robotSetWind = new RobotSetting(this, "Robot settings");
    connect(_robotSetWind, &RobotSetting::SetSig, this, [=](){std::cout << "CLICK SET ROBOT SETTINGS" << std::endl;});  // TODO : create slot with prototype function for all settings with setting new data
    connect(_robotSetWind, &RobotSetting::DeleteSig, this, [=](){std::cout << "CLICK DELETE ROBOT SETTINGS" << std::endl;});

    _wallSetWind = new WallSetting(this, "Wall settings");
    connect(_wallSetWind, &WallSetting::SetSig, this, [=](){std::cout << "CLICK SET WALL SETTINGS" << std::endl;});  // TODO : create slot with prototype function for all settings with setting new data
    connect(_wallSetWind, &WallSetting::DeleteSig, this, [=](){std::cout << "CLICK DELETE WALL SETTINGS" << std::endl;});

}



void MainWindow::_PushNewMapToCoreSlot(){

    int code = _core->LoadingMap(_newMapWind->GetNewMapPath());
    std::cout << "code: " << code <<std::endl;

    if(!code){

        _simulationWind->LoadSimScene();
        _lineMapNameSimIdToolBar->setText(QString::fromStdString(_core->GetMapValue()));

    }

}
