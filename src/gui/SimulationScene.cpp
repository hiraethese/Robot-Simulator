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

    _robotsFromCore = _core->RectFromCore();
    const std::vector<Wall *> &wallsFromCore = _core->GetVectorWalls();
    for(int robot = 0; robot < 1; robot++){

        CreateNewRobot(FromRectToView(_robotsFromCore), _robotsFromCore.x, _robotsFromCore.y);

    }

    for(Wall* wall:wallsFromCore){

        CreateNewWall(wall->GetSimObjView(), wall->GetTransform()->GetRect().x, wall->GetTransform()->GetRect().y);
    }

}

void SimulationScene::_OneSimFrameSlot(){

    _core->MoveAllObjects();
    _robotsFromCore = _core->RectFromCore();

    for(auto robot: _robotsGUIVector){

        std::cout << _robotsFromCore.x <<" "<< _robotsFromCore.y << std::endl;

        robot->setPos(_robotsFromCore.x,_robotsFromCore.y);

    }

}

void SimulationScene::CreateNewRobot(SimObjView view, float x, float y){

    RobotGUI* newRobot = new RobotGUI(0,0,view.w,view.h, &_conn, _index);
    newRobot->setPen(getPen());
    newRobot->setBrush(getBrushByCode(RED));
    newRobot->setPos(x,y);
    addItem(newRobot);
    _robotsGUIVector.push_back(newRobot);
    ++_index;

}


void SimulationScene::CreateNewWall(SimObjView view, float x, float y){

    WallGUI* newWall = new WallGUI(0,0,view.w, view.h, &_conn, _index);
    newWall->setPos(x,y);
    newWall->setPen(getPen());
    newWall->setBrush(getBrushByCode(BLUE));
    addItem(newWall);
    newWall->show();
    _wallsGUIVector.push_back(newWall);
    ++_index;

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

SimObjView SimulationScene::FromRectToView(Rectangle rect){

    return SimObjView{rect.h, rect.w, RED, true, false, 12, 12, 12};

}
