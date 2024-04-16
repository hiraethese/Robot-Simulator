#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{
    _core = Core::getInstance();
    connect(&_simTimer, &QTimer::timeout, this, &SimulationScene::_OneSimFrameSlot);
    setBackgroundBrush(getBrushByCode(WHITE));
    connect(&_conn, &ConnectorGUI::connectSig, this, [=](int orderIndex, bool isRobot){emit RequestSimObjSig(orderIndex, isRobot);});
}

void SimulationScene::CleareSimulationScene(){


    for(auto robot: _robotsGUIVector){

        removeItem(robot);
        delete robot;
    }


    for(auto wall: _wallsGUIVector){

        removeItem(wall);
        delete wall;
    }

    _robotsGUIVector.clear();
    _wallsGUIVector.clear();

}

void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){

    if(event->button() == Qt::LeftButton){

        emit ClickSig(event->scenePos());
    }
}


void SimulationScene::InitSimRun(){

    _simTimer.start(16);

}

void SimulationScene::StopSimRun(){

    _simTimer.stop();

}

void SimulationScene::LoadSimObj(){

    CleareSimulationScene();

    std::vector<SimObjView> robotsView = _core->GetVectorRobotsView();
    std::vector<SimObjView> wallsView = _core->GetVectorWallsView();

    for(SimObjView robot: robotsView){

        CreateNewRobot(robot, robot.x, robot.y);

    }

    for(SimObjView wall: wallsView){

        CreateNewWall(wall, wall.x, wall.y);

    }
}

void SimulationScene::_OneSimFrameSlot(){

    _core->MoveAllObjects();

    std::vector<SimObjView> robotsView = _core->GetVectorRobotsView();

    for(long unsigned int i = 0; i < _robotsGUIVector.size(); i++){  // TODO: raise EXCEPTION when not simular size of gui and view vector

        std::cout << robotsView[i].x <<" "<< robotsView[i].y << std::endl;

        _robotsGUIVector[i]->setPos(robotsView[i].x, robotsView[i].y);

    }

}

void SimulationScene::CreateNewRobot(SimObjView view, float x, float y){

    RobotGUI* newRobot = new RobotGUI(0, 0, view.w, view.h, &_conn, view.orderIndex);
    newRobot->setPen(getPen());
    newRobot->setBrush(getBrushByCode(view.color));
    newRobot->setPos(x,y);
    addItem(newRobot);
    _robotsGUIVector.push_back(newRobot);

}


void SimulationScene::CreateNewWall(SimObjView view, float x, float y){

    WallGUI* newWall = new WallGUI(0, 0, view.w, view.h, &_conn, view.orderIndex);
    newWall->setPos(x,y);
    newWall->setPen(getPen());
    newWall->setBrush(getBrushByCode(view.color));
    addItem(newWall);
    _wallsGUIVector.push_back(newWall);
}

std::vector<RobotGUI*>::iterator SimulationScene::_GetRobotByOrderIndex(int orderIndex){

    auto it = _robotsGUIVector.begin();

    while(it != _robotsGUIVector.end()){

        if((*it)->GetOrderIndex() == orderIndex){
            return it;
        }

        ++it;

    }

    return it;

}


std::vector<WallGUI*>::iterator SimulationScene::_GetWallByOrderIndex(int orderIndex){

    auto it = _wallsGUIVector.begin();
    while( it != _wallsGUIVector.end()){

        if((*it)->GetOrderIndex() == orderIndex){
            return it;
        }

        ++it;

    }

    return it;
}


void SimulationScene::RemoveRobotByOrderIndex(int orderIndex){

    auto itRobotToRemove = _GetRobotByOrderIndex(orderIndex);
    if(itRobotToRemove != _robotsGUIVector.end()){

        RobotGUI* robotToRemove = *itRobotToRemove;
        _robotsGUIVector.erase(itRobotToRemove);
        removeItem(robotToRemove);
        delete robotToRemove;

    }

}

void SimulationScene::RemoveWallByOrderIndex(int orderIndex){

    auto itWallToRemove = _GetWallByOrderIndex(orderIndex);
    if(itWallToRemove != _wallsGUIVector.end()){

        WallGUI* wallToRemove = *itWallToRemove;
        _wallsGUIVector.erase(itWallToRemove);
        removeItem(wallToRemove);
        delete wallToRemove;

    }
}
