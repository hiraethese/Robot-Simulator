#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    _core = Core::getInstance();
    _CreateSimGUI();
    _CreateSimulationsLayout();

}

SimulationWindow::~SimulationWindow(){

    _DeleteSimGUI();
    _DeleteSimulationsLayout();

}

void SimulationWindow::_CreateSimGUI(){

    _simulationScene = new SimulationScene();
    _simulationView = new QGraphicsView(_simulationScene);
    
    _simulationView->setInteractive(false);
    
    _simulationView->setStyleSheet("background-color: black;");
    _simulationView->setSceneRect(0,0,1800, 750);  // TODO: size from core
    _simulationView->setFixedSize(1800+20, 750+20);  // TODO size from core

    // creating new sim obj by user click
    connect(_simulationScene, &SimulationScene::ClickSig, this, &SimulationWindow::_CreateNewSimObjGUISlot);
    
    // push requesting about sim obj from scene to window
    connect(_simulationScene, &SimulationScene::RequestSimObjSig, this, [=](int orderIndex, bool isRobot){emit RequestSimObjSig(orderIndex, isRobot);});
    // signal to loading new sim obj to GUI from core
    connect(this, &SimulationWindow::LoadSimSceneSig, _simulationScene, &SimulationScene::LoadSimObj);
    
    connect(this, &SimulationWindow::CleareSimulationSceneSig, this , [=](){_simulationScene->CleareSimulationScene();});
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

    setLayout(_simulationsLayot);

}

void SimulationWindow::_DeleteSimulationsLayout(){

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


    delete _simBodyowBoxLayout;
    delete _simulationsLayot;

}

void SimulationWindow::SwitchBetweenSimAndBuild(bool flagIsBuild){

    _simulationView->setInteractive(flagIsBuild);

    StopSimScene();

}


void SimulationWindow::_SetUnsetSimButtons(bool flagIsSet){

    _forwardMoveButton->setEnabled(flagIsSet);
    _leftMoveButton->setEnabled(flagIsSet);
    _stopMoveButton->setEnabled(flagIsSet);
    _rightMoveButton->setEnabled(flagIsSet);

}


void SimulationWindow::RunSimScene(){

    _SetUnsetSimButtons(true);

    _simulationScene->InitSimRun();

}

void SimulationWindow::StopSimScene(){


    _SetUnsetSimButtons(false);

    _simulationScene->StopSimRun();


}


void SimulationWindow::keyPressEvent(QKeyEvent *event){

    if(_forwardMoveButton->isEnabled()){

        if(event->key() == Qt::Key_W){

            emit _forwardMoveButton->clicked();

        }
        else if(event->key() == Qt::Key_A){

            emit _leftMoveButton->clicked();

        }
        else if(event->key() == Qt::Key_D){

            emit _rightMoveButton->clicked();

        }
        else if(event->key() == Qt::Key_S){

            emit _stopMoveButton->clicked();

        }

    }

}


ICP_CODE SimulationWindow::RemoveSimObjByOrderIndexSlot(int orderIndex, bool isRobot){

    if(isRobot){

        return _simulationScene->RemoveRobotByOrderIndex(orderIndex);

    }
    else{

        return _simulationScene->RemoveWallByOrderIndex(orderIndex);

    }

}


void SimulationWindow::_CreateNewSimObjGUISlot(QPointF clickPoint){
    emit UperClickSig(clickPoint);
    ICP_CODE check_creaing;
    SimObjView view;
    switch(buildModeStatus){
        case ControllRobotStatus:
            std::cout << "Create Controlled Robot" << std::endl;
            check_creaing = _core->CreateNewControlledRobotFromTemplate(clickPoint.x(), clickPoint.y());
            if(check_creaing){
                emit UperErrorCodeSig(check_creaing);
            }
            else{
                _core->GetViewByOrderGUI(&view, _core->GetLastOrderIndex(), true);

                std::cout << "B =" << view.x << "A=  " << view.y<<std::endl;
                _simulationScene->CreateNewRobot(view); // TODO: Myron do this please this shit
            }
            break;
        case BotRobotStatus:
            std::cout << "Create Bot Robot" << std::endl;
            check_creaing = _core->CreateNewAutomatedRobotFromTemplate(clickPoint.x(), clickPoint.y());
            if(check_creaing){
                emit UperErrorCodeSig(check_creaing);
            }
            else{
                _core->GetViewByOrderGUI(&view, _core->GetLastOrderIndex(), true);
                std::cout << "A =" << view.x << "B=  " << view.y<<std::endl;
                _simulationScene->CreateNewRobot(view);
            }
            break;
        case WallStatus:
            std::cout << "Create Wall" << std::endl;
            check_creaing = _core->CreateNewWallFromTemplate(clickPoint.x(), clickPoint.y());
            if(check_creaing){
                emit UperErrorCodeSig(check_creaing);
            }
            else{
                _core->GetViewByOrderGUI(&view, _core->GetLastOrderIndex(), false);
                _simulationScene->CreateNewWall(view);
            }
            break;
        default:
            break;
    }

}

ICP_CODE SimulationWindow::UpdateSimObjGuiState(SimObjView view)
{
    return _simulationScene->UpdateSimObjGuiState(view);
}
