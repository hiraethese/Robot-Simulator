/**
 * @file MainWindow.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implement main GUI class
 */
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
    _core = Core::getInstance();  // connect to core

    _CreateAppWindows();  // init all GUi part items of app
}


MainWindow::~MainWindow()
{

    _DeleteAppWindows();  // delete all GUI part items of app
    _core->ClearCoreMemory();
    delete ui;

}


void MainWindow::_CreateAppWindows(){

    _CreateSimulationWindow();

    _CreateSettings();

    _CreateMenu();

    _CreateSimModeSlot();

}

void MainWindow::_DeleteAppWindows(){

    _DeleteTools();

    _DeleteMenu();

    delete _simulationWind;

}


void MainWindow::_DeleteTools(){

    if(_actualPage == SimulationPage){  // if actual page is simualtion mode

        _DeleteSimModeTools();

    }
    else{  // if actual page is build mode

        _DeleteBuildModeTools();

    }

}

// ************************************  PART MENU    *********************************************************

void MainWindow::_CreateMenu(){

    appMenu = menuBar()->addMenu("Menu");

    templatesSubMenu = appMenu->addMenu("Templates");

    // connect to loading and showing settings info about controlled robots
    buildControlledRobotTemplate = templatesSubMenu->addAction("Controlled robot");
    connect(buildControlledRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetControlledRobotTemp(), -1);_robotSetWind->ChangeEnablingOfSettingsObjects(false); _robotSetWind->exec();});

    // connect to loading and showing settings info about automated robots
    buildAutoRobotTemplate = templatesSubMenu->addAction("Automated robot");
    connect(buildAutoRobotTemplate, &QAction::triggered, this, [=](){_robotSetWind->DownloadDataFromView(_core->GetAutomatedRobotTemp(), -1); _robotSetWind->ChangeEnablingOfSettingsObjects(false);_robotSetWind->exec();});

    // connect to loading and showing settings info about wall
    buildWallTemplate = templatesSubMenu->addAction("Wall");
    connect(buildWallTemplate, &QAction::triggered, this, [=](){_wallSetWind->DownloadDataFromView(_core->GetWallTemp(), -1);_wallSetWind->ChangeEnablingOfSettingsObjects(false);_wallSetWind->exec();});

    // connect to switching mode to simulation
    simulationModeAction = appMenu->addAction("Simulation");
    connect(simulationModeAction, &QAction::triggered, this, &MainWindow::_CreateSimModeSlot);

    // connect to switching mode to build
    buildMapModeAction = appMenu->addAction("Build map");
    connect(buildMapModeAction, &QAction::triggered, this, &MainWindow::_CreateBuildMapModeSlot);

    // connect to loading specification map file
    downloadNewModeMapAction = appMenu->addAction("Download map");
    connect(downloadNewModeMapAction, &QAction::triggered, this, [=](){_simulationWind->StopSimScene();_newMapWind->exec();});

}

void MainWindow::_DeleteMenu(){

    delete simulationModeAction;
    delete downloadNewModeMapAction;
    delete buildMapModeAction;
    delete buildControlledRobotTemplate;
    delete buildAutoRobotTemplate;
    delete buildWallTemplate;
    delete templatesSubMenu;
    delete appMenu;

}


// ************************************  PART SIM MODE    *********************************************************

void MainWindow::_CreateSimModeSlot(){

    setWindowTitle("Simulation");

    if(_actualPage != SimulationPage){  // refresh if is not simulation

        _DeleteBuildModeTools();
        _CreateSimModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(false); 
        _actualPage = SimulationPage;

    }

}

void MainWindow::_CreateSimModeTools(){

    // conect to launcher of simulation runnig
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


void MainWindow::_RunSimulationActionSlot(){

    // change functional button to simulation stop
    disconnect(_runSimulationAction, 0, 0, 0);
    connect(_runSimulationAction, &QAction::triggered, this, &MainWindow::_PauseSimulationActionSlot);
    _runSimulationAction->setIcon(QIcon(":/icons/pauseTool.svg"));
    _runSimulationAction->setText("Pause");
    _lineSimRunStatus->setText("Run");
    _lineSimRunStatus->setStyleSheet("background-color: lightgreen;");

    _simulationWind->setFocus();

    // run simulation
    _simulationWind->RunSimScene();

}

void MainWindow::_PauseSimulationActionSlot(){
    // stop simulation
    _simulationWind->StopSimScene();
    
    // change functional button to simulation run
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
    // connect to show actual click of user (build mode)
    connect(_simulationWind, &SimulationWindow::UperClickSig, this, [=](QPointF clickPoint){_xCursorTouchLine->setText(QString("%1").arg(clickPoint.x()));_yCursorTouchLine->setText(QString("%1").arg(clickPoint.y()));});
    // connect to request sim obj from scene to core  (build mode)
    connect(_simulationWind, &SimulationWindow::RequestSimObjSig, this, &MainWindow::_RequestSimObjSlot);
    // wait from sim wind errors codes
    connect(_simulationWind, &SimulationWindow::UperErrorCodeSig, this, [=](ICP_CODE err_code){_WarningMsg(err_code);});
}

void MainWindow::_RequestSimObjSlot(int orderIndex, bool isRobot){
    std::cout << "Order index: " << orderIndex << "; is Robot: " << isRobot << std::endl;
    ICP_CODE ret;
    SimObjView view;

    // request from core info about simulation object
    ret = _core->GetViewByOrderGUI(&view, orderIndex, isRobot);

    std::cout << "Test2: " << view.h << " " << view.color << std::endl;
    
    if(ret != CODE_OK){  // if not find or smth error
        _WarningMsg(ret);
    }
    else{  // find
        if(isRobot){  // if robot object
            // download data about sim obj to settings window
            _robotSetWind->DownloadDataFromView(view, orderIndex);
            _robotSetWind->ChangeEnablingOfSettingsObjects(true);
            _robotSetWind->exec();
        }
        else{  // if wall object
            // download data about sim obj to settings window
            _wallSetWind->DownloadDataFromView(view, orderIndex);
            _wallSetWind->ChangeEnablingOfSettingsObjects(true);
            _wallSetWind->exec();
        }
    }
}

void MainWindow::_UpdateSimObjSlot(SimObjView view){

    if(view.orderIndex == -1){  // update tamplates
        if(view.isRobot){
            if(view.isControlled){
                _core->SetControlledRobotTemp(view);  // upd
            }
            else{
                _core->SetAutomatedRobotTemp(view);  // upd
            }
        }
        else{
            _core->SetWallTemp(view);  // upd
        }
    }
    else{  // update simulation obj
        ICP_CODE ret;
        if(view.isRobot){

            ret = _core->UpdateRobotState(view);  //  upd

        }
        else{

            ret = _core->UpdateWallState(view);  // upd

        }

        if(ret != CODE_OK){  // if unsuccessfull upd

            _WarningMsg(ret);

        }
        else{  // upd GUI after CORE

            ret = _simulationWind->UpdateSimObjGuiState(view.orderIndex, view.isRobot);  // upd
            if(ret != CODE_OK){  // if unsuccessfull upd
                _WarningMsg(ret);
            }
        }

    }

}

void MainWindow::_DeleteSimObjSlot(SimObjView view){

    if(view.orderIndex != -1){  // if not template
        ICP_CODE ret;
        if(view.isRobot){
        
            ret = _core->RemoveRobotByOrderIndex(view.orderIndex);  // del from core
        
        }
        else{
        
            ret = _core->RemoveWallByOrderIndex(view.orderIndex);  // del from core
        
        }
        
        if(ret != CODE_OK){  // if unsuccessful del

            _WarningMsg(ret);
        
        }   
        else{
        
            ret = _simulationWind->RemoveSimObjByOrderIndexSlot(view.orderIndex, view.isRobot);  // del from gui

            if(ret != CODE_OK){  // if unsuccessful del
                
                _WarningMsg(ret);

            }

        }
    }

}


void MainWindow::_CreateBuildMapModeSlot(){

    setWindowTitle("Build map");

    if(_actualPage != BuildPage){  // refresh if pervuse is not build mode

        _DeleteSimModeTools();
        _CreateBuildModeTools();
        _simulationWind->SwitchBetweenSimAndBuild(true);
        _actualPage = BuildPage;

    }

}

void MainWindow::_CreateBuildModeTools(){

    // connect to setting cursor to creation new controlled robots
    _buildControlRobotAction = new QAction(QIcon(":/icons/userRobotTool.png"), "Controlled robot", this);
    connect(_buildControlRobotAction, &QAction::triggered, this, [=](){_simulationWind->buildModeStatus = ControllRobotStatus;_statusModeLine->setText("Build controlled robot");});

    // connect to setting cursor to creation new automatic robots
    _buildAutoRobotAction = new QAction(QIcon(":/icons/botRobotTool.png"), "Automatic robot", this);
    connect(_buildAutoRobotAction, &QAction::triggered, this, [=](){_simulationWind->buildModeStatus = AutoRobotStatus; _statusModeLine->setText("Build automatic robots");});

    // connect to setting cursor to creation new wall
    _buildWallAction = new QAction(QIcon(":/icons/wallTool.png"), "Wall", this);
    connect(_buildWallAction, &QAction::triggered, this, [=](){_simulationWind->buildModeStatus = WallStatus;_statusModeLine->setText("Build walls");});

    _engineBuildToolBar = addToolBar("engineBuild");
    _engineBuildToolBar->addAction(_buildControlRobotAction);
    _engineBuildToolBar->addAction(_buildAutoRobotAction);
    _engineBuildToolBar->addAction(_buildWallAction);

    // actual user clicl on OX-OY
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

    // actual created sim obj type
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

        disconnect(_buildControlRobotAction, 0, 0, 0);
        disconnect(_buildAutoRobotAction, 0, 0, 0);
        disconnect(_buildWallAction, 0, 0, 0);
        delete _buildControlRobotAction;
        delete _buildAutoRobotAction;
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


void MainWindow::_CreateSettings(){

    // connect to given new map value to core and check result loading
    _newMapWind = new NewMapSetting(this);
    connect(_newMapWind, &NewMapSetting::DownloadSig, this, &MainWindow::_PushNewMapToCoreSlot);

    // connect to given core information about upd/del sim robot from gui to core and check it
    _robotSetWind = new RobotSetting(this, "Robot settings");
    connect(_robotSetWind, &RobotSetting::SetSig, this, &MainWindow::_UpdateSimObjSlot);
    connect(_robotSetWind, &RobotSetting::DeleteSig, this, &MainWindow::_DeleteSimObjSlot);

    // connect to given core information about upd/del wall from gui to core and check it
    _wallSetWind = new WallSetting(this, "Wall settings");
    connect(_wallSetWind, &WallSetting::SetSig, this, &MainWindow::_UpdateSimObjSlot);
    connect(_wallSetWind, &WallSetting::DeleteSig, this, &MainWindow::_DeleteSimObjSlot);

}



void MainWindow::_PushNewMapToCoreSlot(){
    
    // del all from prevuse map
    emit _simulationWind->CleareSimulationSceneSig();
    
    // call loading map and creating new sim obj in core side
    ICP_CODE code = _core->LoadingMap(_newMapWind->GetNewMapPath());

    if(code == CODE_OK){  // ok
        
        // draw new obj
        emit _simulationWind->LoadSimSceneSig();

    }
    else {  // err and info user about it
        
        _WarningMsg(code);

    }

}

