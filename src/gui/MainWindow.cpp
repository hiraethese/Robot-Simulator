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

    buildUserRobotTemplate = templatesSubMenu->addAction("Controlled robot");
    connect(buildUserRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetControlledRobotTemp(), -1);_robotSetWind->ChangeEnablingOfSettingsObjects(false); _robotSetWind->exec();});

    buildBotRobotTemplate = templatesSubMenu->addAction("Automated robot");
    connect(buildBotRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetAutomatedRobotTemp(), -1); _robotSetWind->ChangeEnablingOfSettingsObjects(false);_robotSetWind->exec();});

    buildWallLayout = templatesSubMenu->addAction("Wall");
    connect(buildWallLayout, &QAction::triggered, this, [=](){_wallSetWind->DownloadDataFromView(_core->GetWallTemp(), -1);_wallSetWind->ChangeEnablingOfSettingsObjects(false);_wallSetWind->exec();});

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

    _engineSimRunToolBar = addToolBar("engineSimRun");
    _engineSimRunToolBar->addAction(_runSimulationAction);

    _simRunStatusToolBar = addToolBar("simulationRunStatus");
    _labelSimIdToolBar = new QLabel("Simulation: ");

    _simRunStatusToolBar->addWidget(_labelSimIdToolBar);

    _lineSimRunStatus = new QLineEdit();
    _lineSimRunStatus->setReadOnly(true);
    _lineSimRunStatus->setFixedWidth(100);

    _simRunStatusToolBar->addWidget(_lineSimRunStatus);

}


void MainWindow::_DeleteSimModeTools(){

    disconnect(_runSimulationAction, 0, 0, 0);
    delete _runSimulationAction;

    _runSimulationAction = nullptr;

    removeToolBar(_engineSimRunToolBar);
    removeToolBar(_simRunStatusToolBar);
    delete _labelSimIdToolBar;
    delete _lineSimRunStatus;
    delete _engineSimRunToolBar;
    delete _simRunStatusToolBar;

}


void MainWindow::_HelpTextToolActionSlot(){
    // !!! need add help text for users interface actions
    QMessageBox::about(this, "Help", "<b>This place will be for help users text!</b>");
}

void MainWindow::_RunSimulationActionSlot(){

    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_PauseSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/pauseTool.svg"));
    _runSimulationAction->setText("Pause");
    _lineSimRunStatus->setText("Run");
    _lineSimRunStatus->setStyleSheet("background-color: lightgreen;");

    _simulationWind->setFocus();

    _simulationWind->RunSimScene();

}

void MainWindow::_PauseSimulationActionSlot(){

    _simulationWind->StopSimScene();
    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_RunSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/playTool.png"));
    _runSimulationAction->setText("Run");
    _lineSimRunStatus->setText("Pause");
    _lineSimRunStatus->setStyleSheet("background-color: white;");

}


// ************************************  PART SIM WIND    *********************************************************


void MainWindow::_CreateSimulationWindow(){

    _simulationWind = new SimulationWindow(this);
    setCentralWidget(_simulationWind);
    // show actual click of user
    connect(_simulationWind, &SimulationWindow::UperClickSig, this, [=](QPointF clickPoint){_xCursorTouchLine->setText(QString("%1").arg(clickPoint.x()));_yCursorTouchLine->setText(QString("%1").arg(clickPoint.y()));});
    // request sim obj from scene to core
    connect(_simulationWind, &SimulationWindow::RequestSimObjSig, this, &MainWindow::_RequestSimObjSlot);
    // wait from sim wind errors codes
    connect(_simulationWind, &SimulationWindow::UperErrorCodeSig, this, [=](ICP_CODE err_code){_WarningMsg(err_code);});
}

void MainWindow::_RequestSimObjSlot(int orderIndex, bool isRobot){
    std::cout << "Order index: " << orderIndex << "; is Robot: " << isRobot << std::endl;
    ICP_CODE ret;
    SimObjView view;
    ret = _core->GetViewByOrderGUI(&view, orderIndex, isRobot);

    std::cout << "Test2: " << view.h << " " << view.color << std::endl;
    if(ret != CODE_OK){
        _WarningMsg(ret);
    }
    else{
        if(isRobot){
            // download data about sim obj to settings window
            _robotSetWind->DownloadDataFromView(view, orderIndex);  // TODO: order index get to cor request
            _robotSetWind->ChangeEnablingOfSettingsObjects(true);
            _robotSetWind->exec();
        }
        else{
            // download data about sim obj to settings window
            _wallSetWind->DownloadDataFromView(view, orderIndex);  // TODO: order index get to cor request
            _wallSetWind->ChangeEnablingOfSettingsObjects(true);
            _wallSetWind->exec();
        }
    }
}

void MainWindow::_UpdateSimObjSlot(SimObjView view){

    if(view.orderIndex == -1){  // update tamplates
        if(view.isRobot){
            if(view.isControlled){
                _core->SetControlledRobotTemp(view);
            }
            else{
                _core->SetAutomatedRobotTemp(view);
            }
        }
        else{
            _core->SetWallTemp(view);
        }
    }
    else{  // update obj
        ICP_CODE ret;
        if(view.isRobot){

            ret = _core->UpdateRobotState(view);

        }
        else{

            ret = _core->UpdateWallState(view);

        }

        if(ret != CODE_OK){  // if unsuccessfull updation

            _WarningMsg(ret);

        }
        else{  // update GUI after CORE

            ret = _simulationWind->UpdateSimObjGuiState(view.orderIndex, view.isRobot);
            if(ret != CODE_OK){
                _WarningMsg(ret);
            }
        }

    }

}

void MainWindow::_DeleteSimObjSlot(SimObjView view){

    if(view.orderIndex != -1){
        ICP_CODE ret;
        if(view.isRobot){
        
            ret = _core->RemoveRobotByOrderIndex(view.orderIndex);
        
        }
        else{
        
            ret = _core->RemoveWallByOrderIndex(view.orderIndex);
        
        }
        
        if(ret != CODE_OK){

            _WarningMsg(ret);
        
        }   
        else{
        
            ret = _simulationWind->RemoveSimObjByOrderIndexSlot(view.orderIndex, view.isRobot);

            if(ret != CODE_OK){
                
                _WarningMsg(ret);

            }

        }
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

}

void MainWindow::_CreateBuildModeTools(){

    _buildUserRobotAction = new QAction(QIcon(":/icons/userRobotTool.png"), "User robot", this);
    connect(_buildUserRobotAction, &QAction::triggered, this, &MainWindow::_BuildUserRobotActionSlot);

    _buildBotRobotAction = new QAction(QIcon(":/icons/botRobotTool.png"), "Bot robot", this);
    connect(_buildBotRobotAction, &QAction::triggered, this, &MainWindow::_BuildBotRobotActionSlot);

    _buildWallAction = new QAction(QIcon(":/icons/wallTool.png"), "Wall", this);
    connect(_buildWallAction, &QAction::triggered, this, &MainWindow::_BuildWallActionSlot);

    _engineBuildToolBar = addToolBar("engineBuild");
    _engineBuildToolBar->addAction(_buildUserRobotAction);
    _engineBuildToolBar->addAction(_buildBotRobotAction);
    _engineBuildToolBar->addAction(_buildWallAction);

    _engineCursorToolBar = addToolBar("engineCursor");
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

        disconnect(_buildUserRobotAction, 0, 0, 0);
        disconnect(_buildBotRobotAction, 0, 0, 0);
        disconnect(_buildWallAction, 0, 0, 0);
        delete _buildUserRobotAction;
        delete _buildBotRobotAction;
        delete _buildWallAction;
        delete _statusModeLabel;
        delete _statusModeLine;
        delete _xCursorTouchLab;
        delete _xCursorTouchLine;
        delete _yCursorTouchLab;
        delete _yCursorTouchLine;
        removeToolBar(_engineBuildToolBar);
        removeToolBar(_engineCursorToolBar);
        removeToolBar(_statusModeBuildToolBar);
        delete _engineBuildToolBar;
        delete _engineCursorToolBar;
        delete _statusModeBuildToolBar;

    }

}

void MainWindow::_BuildUserRobotActionSlot(){

    _simulationWind->buildModeStatus = ControllRobotStatus;
    _statusModeLine->setText("Build users robot");

}

void MainWindow::_BuildBotRobotActionSlot(){

    _simulationWind->buildModeStatus = BotRobotStatus;
    _statusModeLine->setText("Build bot robots");

}


void MainWindow::_BuildWallActionSlot(){

    _simulationWind->buildModeStatus = WallStatus;
    _statusModeLine->setText("Build walls");

}


// ************************************  PART SETTINGS MODE    *********************************************************

void MainWindow::_CreateSettings(){

    _newMapWind = new NewMapSetting(this);
    connect(_newMapWind, &NewMapSetting::DownloadSig, this, &MainWindow::_PushNewMapToCoreSlot);

    _robotSetWind = new RobotSetting(this, "Robot settings");
    connect(_robotSetWind, &RobotSetting::SetSig, this, &MainWindow::_UpdateSimObjSlot);
    connect(_robotSetWind, &RobotSetting::DeleteSig, this, &MainWindow::_DeleteSimObjSlot);

    _wallSetWind = new WallSetting(this, "Wall settings");
    connect(_wallSetWind, &WallSetting::SetSig, this, &MainWindow::_UpdateSimObjSlot);
    connect(_wallSetWind, &WallSetting::DeleteSig, this, &MainWindow::_DeleteSimObjSlot);

}



void MainWindow::_PushNewMapToCoreSlot(){
    
    emit _simulationWind->CleareSimulationSceneSig();

    ICP_CODE code = _core->LoadingMap(_newMapWind->GetNewMapPath());  // call loading map and creating new sim obj

    if(code == CODE_OK){  // ok

        emit _simulationWind->LoadSimSceneSig();  // draw new obj

    }
    else {  // err and info user about it
        
        _WarningMsg(code);

    }

}

