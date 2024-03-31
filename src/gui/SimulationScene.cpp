#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{
    _core = Core::getInstance();
    connect(&_simTimer, &QTimer::timeout, this, &SimulationScene::_OneSimFrame);
    setBackgroundBrush(getBrushByCode(WHITE));
}

void SimulationScene::CleareSimulationScene(){

    clear();

    _robotsGUIVector.clear();

    _wallsGUIVector.clear();

}

void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){

    _actualUserClick = event->scenePos();
    
    emit clickSig();
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

        QGraphicsEllipseItem* newRobot = new QGraphicsEllipseItem(0,0,_robotsFromCore.w,_robotsFromCore.h);
        newRobot->setPen(getPen());
        newRobot->setBrush(getBrushByCode(RED));
        newRobot->setPos(_robotsFromCore.x,_robotsFromCore.y);
        addItem(newRobot);
        _robotsGUIVector.push_back(newRobot);

    }

    for(Wall* wall:wallsFromCore){

        QGraphicsRectItem* newWall = new QGraphicsRectItem(0,0,wall->GetTransform()->GetRect().w, wall->GetTransform()->GetRect().h);
        newWall->setPen(getPen());
        newWall->setBrush(getBrushByCode(BLUE));
        newWall->setPos(wall->GetTransform()->GetRect().x,wall->GetTransform()->GetRect().y);
        addItem(newWall);
        _wallsGUIVector.push_back(newWall);

    }

}

void SimulationScene::_OneSimFrame(){

    _core->MoveAllObjects();
    _robotsFromCore = _core->RectFromCore();

    for(auto robot: _robotsGUIVector){

        std::cout << _robotsFromCore.x <<" "<< _robotsFromCore.y << std::endl;

        robot->setPos(_robotsFromCore.x,_robotsFromCore.y);

    }

}

QPointF* SimulationScene::GetUserClick(){
    return &_actualUserClick;
}
