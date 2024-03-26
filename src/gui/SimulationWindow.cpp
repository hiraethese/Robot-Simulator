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

    if(flagSimEngineLayout){

        _DeleteSimulationEngineLayout();

    }

    _DeleteSimulationsLayout();

}

void SimulationWindow::_CreateSimGUI(){

    _simulationScene = new SimulationScene();
    _simulationView = new QGraphicsView(_simulationScene);
    
    _simulationView->setInteractive(false);
    
    _simulationView->setStyleSheet("background-color: black;");
    _simulationView->setSceneRect(0,0,1800, 750);  // TODO: size from core
    _simulationView->setFixedSize(1800+20, 750+20);  // TODO size from core

    connect(_simulationScene, &SimulationScene::clickSig, this, [=](){emit UperClickSig();});
}

void SimulationWindow::_DeleteSimGUI(){

    _simulationScene->CleareSimulationScene();

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

void SimulationWindow::_CreateSimulationEngineLayout(){

    flagSimEngineLayout = true;

    _forwardMoveButton = new QPushButton("forward");
    _leftMoveButton = new QPushButton("left");
    _rightMoveButton = new QPushButton("right");
    _stopMoveButton = new QPushButton("stop");

    _SetUnsetSimButtons(false); // default should be false

    connect(_forwardMoveButton, &QPushButton::clicked, this, [=](){_core->ForwardMoveSig();});
    connect(_leftMoveButton, &QPushButton::clicked, this, [=](){_core->LeftRotateMoveSig();});
    connect(_rightMoveButton, &QPushButton::clicked, this, [=](){_core->RightRotateMoveSig();});
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

void SimulationWindow::_DeleteSimulationEngineLayout(){

    flagSimEngineLayout = false;
    _simulationsLayot->removeItem(_simulatyonEngineLayout);

    disconnect(_forwardMoveButton, 0, 0, 0);
    disconnect(_leftMoveButton, 0, 0, 0);
    disconnect(_stopMoveButton, 0, 0, 0);
    disconnect(_rightMoveButton, 0, 0, 0);

    delete _forwardMoveButton;
    _forwardMoveButton = nullptr;
    delete _leftMoveButton;
    _leftMoveButton = nullptr;
    delete _stopMoveButton;
    _stopMoveButton = nullptr;
    delete _rightMoveButton;
    _rightMoveButton = nullptr;

    delete _highRobotsEngineLayout;
    delete _lowRobotsEngineLayout;
    delete _robotsEngineLayout;
    delete _simulatyonEngineLayout;

}


void SimulationWindow::SwitchBetweenSimAndBuild(bool flagIsBuild){

    _simulationView->setInteractive(flagIsBuild);

    if(flagIsBuild){

        _simulationView->setInteractive(true);
        _DeleteSimulationEngineLayout();

    }
    else{

        _simulationView->setInteractive(false);
        _CreateSimulationEngineLayout();

    }

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

void SimulationWindow::LoadSimScene(){

    _simulationScene->LoadSimObj();

}


void SimulationWindow::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_W){

        if(_forwardMoveButton){

            emit _forwardMoveButton->clicked();

        }

    }
    else if(event->key() == Qt::Key_A){

        if(_leftMoveButton){

            emit _leftMoveButton->clicked();

        }

    }
    else if(event->key() == Qt::Key_D){

        if(_rightMoveButton){

            emit _rightMoveButton->clicked();

        }

    }
    else if(event->key() == Qt::Key_S){

        if(_stopMoveButton){

            emit _stopMoveButton->clicked();

        }

    }
}

QPointF* SimulationWindow::GetUserClick(){
    return _simulationScene->GetUserClick();
}

