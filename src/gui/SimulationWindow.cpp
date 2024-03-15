#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    //simBody = new SimulationBody();
    _core = Core::getInstance();
    _CreateSimGUI();
    _CreateSimulattionsButtons();
    _CreateSimulationsLayout();

    connect(&_timerOneFrame, &QTimer::timeout, this, &SimulationWindow::_OneSimFrameGUI);
}

SimulationWindow::~SimulationWindow(){
    //for(QBrush* br: brashVector) delete br;  // TODO: SIGMFALL
    //for(QPen* pen: _penVector) delete pen;    // TODO: SIGMFALL
    _DeleteSimGUI();
    _DeleteSimulationsButtons();
    _DeleteSimulationsLayout();
}

void SimulationWindow::_CreateSimGUI(){
    _simGraphScene = new QGraphicsScene();
    _simGraphView = new QGraphicsView(_simGraphScene);

    _simGraphView->setSceneRect(0,0,1800, 750);
    _simGraphView->setFixedSize(1800+20, 750+20);
    //_simGraphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //_simGraphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    _redBrush = new QBrush(Qt::red);
    _yellowBrush = new QBrush(Qt::yellow);
    _greanBrush = new QBrush(Qt::green);
    _blueBrush = new QBrush(Qt::blue);
    _blackBrush = new QBrush(Qt::black);
    _whiteBrush = new QBrush(Qt::white);
    _blackPen = new QPen(Qt::black);
    _whitePen = new QPen(Qt::white);
    _brushVector.push_back(_redBrush);
    _brushVector.push_back(_yellowBrush);
    _brushVector.push_back(_greanBrush);
    _brushVector.push_back(_greanBrush);
    _brushVector.push_back(_blueBrush);
    _brushVector.push_back(_blackBrush);
    _brushVector.push_back(_whiteBrush);

    _penVector.push_back(_blackPen);
    _penVector.push_back(_whitePen);
}

void SimulationWindow::_CleanSimGUI(){
    _simGraphScene->clear();
    _robotsVectorGUI.clear();
}

void SimulationWindow::_DeleteSimGUI(){
    _CleanSimGUI();
    delete _simGraphScene;
    delete _simGraphView;
}

unsigned SimulationWindow::_GetActualUserRobotPen(){
    if(actualUserRobotColor != 4) return 0;
    return 1;
}

void SimulationWindow::_CreateSimulationsLayout(){
    _simulationsLayot = new QVBoxLayout();

    _simBodyowBoxLayout = new QHBoxLayout();
    _simBodyowBoxLayout->addStretch();
    _simBodyowBoxLayout->addWidget(_simGraphView);
    _simBodyowBoxLayout->addStretch();

    _simulatyonEngineLayout = new QHBoxLayout();
    _robotsEngineLayout = new QVBoxLayout();

    _highRobotsEngineLayout = new QHBoxLayout();
    _highRobotsEngineLayout->addStretch();
    _highRobotsEngineLayout->addWidget(_forwardMoveButton);
    _highRobotsEngineLayout->addStretch();

    _lowRobotsEngineLayout = new QHBoxLayout();
    _lowRobotsEngineLayout->addStretch();
    _lowRobotsEngineLayout->addWidget(_leftMoveButton);
    _lowRobotsEngineLayout->addWidget(_stopMoveButton);
    _lowRobotsEngineLayout->addWidget(_rightMoveButton);
    _lowRobotsEngineLayout->addStretch();

    _robotsEngineLayout->addLayout(_highRobotsEngineLayout);
    _robotsEngineLayout->addLayout(_lowRobotsEngineLayout);

    _simulatyonEngineLayout->addStretch();
    _simulatyonEngineLayout->addLayout(_robotsEngineLayout);
    _simulatyonEngineLayout->addStretch();

    _simulationsLayot->addLayout(_simBodyowBoxLayout);
    _simulationsLayot->addLayout(_simulatyonEngineLayout);
    setLayout(_simulationsLayot);
}
void SimulationWindow::_DeleteSimulationsLayout(){
    delete _simBodyowBoxLayout;
    delete _highRobotsEngineLayout;
    delete _lowRobotsEngineLayout;
    delete _robotsEngineLayout;
    delete _simulatyonEngineLayout;
    delete _simulationsLayot;
}

void SimulationWindow::_CreateSimulattionsButtons(){

    _forwardMoveButton = new QPushButton("forward");
    _leftMoveButton = new QPushButton("left");
    _stopMoveButton = new QPushButton("stop");
    _rightMoveButton = new QPushButton("right");

    _SetUnsetSimButtons(false);

    connect(_leftMoveButton, &QPushButton::clicked, this, [=](){_core->LeftRotateMoveSig();});
    connect(_rightMoveButton, &QPushButton::clicked, this, [=](){_core->RightRotateMoveSig();});
    connect(_forwardMoveButton, &QPushButton::clicked, this, [=](){_core->ForwardMoveSig();});
    connect(_stopMoveButton, &QPushButton::clicked, this, [=](){_core->StopMoveSig();});
}

void SimulationWindow::_SetUnsetSimButtons(bool flagIsSet){
    _forwardMoveButton->setEnabled(flagIsSet);
    _leftMoveButton->setEnabled(flagIsSet);
    _stopMoveButton->setEnabled(flagIsSet);
    _rightMoveButton->setEnabled(flagIsSet);
}

void SimulationWindow::_DeleteSimulationsButtons(){
    delete _forwardMoveButton;
    delete _leftMoveButton;
    delete _stopMoveButton;
    delete _rightMoveButton;
}

void SimulationWindow::_OneSimFrameGUI(){
    //std::cout << "EMIT UPDATING SIM GUI" << std::endl;
    _core->MoveAllObjects();
    _robotsFromController = _core->RectFromCore();
    for(auto robot: _robotsVectorGUI){
        _actualPositionOfItem = robot->pos();
        robot->setPos(_robotsFromController.x,_robotsFromController.y);
    }
}

void SimulationWindow::StoreSimGUI(){
    _CleanSimGUI();
    _simGraphScene->setBackgroundBrush(*_whiteBrush);
    std::cout << "EMIT STORING SIM GUI!!!" << std::endl;
    _robotsFromController = _core->RectFromCore();
    for(unsigned robot = 0; robot < 1; robot++){
        QGraphicsEllipseItem* newRobot = new QGraphicsEllipseItem(0,0,_robotsFromController.w,_robotsFromController.h);
        newRobot->setPen(*_penVector[_GetActualUserRobotPen()]);
        newRobot->setBrush(*_brushVector[actualUserRobotColor]);
        newRobot->setPos(_robotsFromController.x,_robotsFromController.y);
        _simGraphScene->addItem(newRobot);
        _robotsVectorGUI.push_back(newRobot);
    }
}

void SimulationWindow::RunSimGUI(){
    std::cout << "EMIT RUNING SIM GUI !!!" << std::endl;
    _timerOneFrame.start(16);
    _SetUnsetSimButtons(true);
}

void SimulationWindow::StopSimGUI(){
    std::cout << "EMIT STOP SIM GUI !!!" << std::endl;
    _timerOneFrame.stop();
    _SetUnsetSimButtons(false);
}
