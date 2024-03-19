#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    //simBody = new SimulationBody();
    _core = Core::getInstance();
    _CreateSimGUI();
    _CreateSimulationsLayout();
}

SimulationWindow::~SimulationWindow(){
    _DeleteSimGUI();

    if(flagSimEngineLayout)
        DeleteSimulationEngineLayout();

    _DeleteSimulationsLayout();
}

void SimulationWindow::_CreateSimGUI(){
    _simulationScene = new SimulationScene();
    _simulationView = new QGraphicsView(_simulationScene);

    _simulationView->setStyleSheet("background-color: black;");
    _simulationView->setSceneRect(0,0,1800, 750);  // TODO: size from core
    _simulationView->setFixedSize(1800+20, 750+20);  // TODO size from core
    StoreSimScene();
}

void SimulationWindow::_DeleteSimGUI(){
    _simulationScene->DeleteSimulationScene();

    delete _simulationScene;
    delete _simulationView;
}


void SimulationWindow::_CreateSimulationsLayout(){
    _simulationsLayot = new QVBoxLayout();

    _simBodyowBoxLayout = new QHBoxLayout();
    _simBodyowBoxLayout->addStretch();
    _simBodyowBoxLayout->addWidget(_simulationView);
    _simBodyowBoxLayout->addStretch();


    _simulationsLayot->addLayout(_simBodyowBoxLayout);
    setLayout(_simulationsLayot);
}
void SimulationWindow::_DeleteSimulationsLayout(){
    delete _simBodyowBoxLayout;
    delete _simulationsLayot;
}
void SimulationWindow::CreateSimulationEngineLayout(){
    flagSimEngineLayout = true;
    _forwardMoveButton = new QPushButton("forward");
    _leftMoveButton = new QPushButton("left");
    _stopMoveButton = new QPushButton("stop");
    _rightMoveButton = new QPushButton("right");

    _SetUnsetSimButtons(true); // default should be false

    connect(_leftMoveButton, &QPushButton::clicked, this, [=](){_core->LeftRotateMoveSig();});
    connect(_rightMoveButton, &QPushButton::clicked, this, [=](){_core->RightRotateMoveSig();});
    connect(_forwardMoveButton, &QPushButton::clicked, this, [=](){_core->ForwardMoveSig();});
    connect(_stopMoveButton, &QPushButton::clicked, this, [=](){_core->StopMoveSig();});

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

    _simulationsLayot->addLayout(_simulatyonEngineLayout);
}

void SimulationWindow::DeleteSimulationEngineLayout(){
    flagSimEngineLayout = false;
    _simulationsLayot->removeItem(_simulatyonEngineLayout);

    disconnect(_forwardMoveButton, 0, 0, 0);
    disconnect(_leftMoveButton, 0, 0, 0);
    disconnect(_stopMoveButton, 0, 0, 0);
    disconnect(_rightMoveButton, 0, 0, 0);

    delete _forwardMoveButton;
    delete _leftMoveButton;
    delete _stopMoveButton;
    delete _rightMoveButton;

    delete _highRobotsEngineLayout;
    delete _lowRobotsEngineLayout;
    delete _robotsEngineLayout;
    delete _simulatyonEngineLayout;

}

void SimulationWindow::_SetUnsetSimButtons(bool flagIsSet){
    _forwardMoveButton->setEnabled(flagIsSet);
    _leftMoveButton->setEnabled(flagIsSet);
    _stopMoveButton->setEnabled(flagIsSet);
    _rightMoveButton->setEnabled(flagIsSet);
}


void SimulationWindow::RunSimScene(){
    _simulationScene->InitSimRun();
}
void SimulationWindow::StopSimScene(){
    _simulationScene->StopSimRun();
}
void SimulationWindow::StoreSimScene(){
    _simulationScene->StoreSimObj();
}
