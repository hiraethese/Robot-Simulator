#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{
    _core = Core::getInstance();
    connect(&_simTimer, &QTimer::timeout, this, &SimulationScene::_OneSimFrame);
    setBackgroundBrush(whiteBrush);
}

void SimulationScene::DeleteSimulationScene(){

    clear();

    _robotsGUIVector.clear();

    _wallsGUIVector.clear();
}

void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){
    event->ignore();
    if(true){//flagSettingMode
        std::cout << "Run settings mode!" << std::endl;
        /*cleanSettingsMode();
        QPointF choosePos = event->scenePos();
        std::cout << "click to: " <<  choosePos.x() << " " << choosePos.y() << std::endl;
        if((choosePos.x()-15 > 0 && choosePos.x()+15 <= width()) && (choosePos.y()-15 > 0 && choosePos.y()+15 <= height())){  // TODO: core method for calc new position
            SimObjGUI* actualItem = findSimObjGUI(choosePos.x(), choosePos.y());
            if(actualItem){ // on choosing position have simulation object
                std::cout << "find item on position" << choosePos.x() << " " << choosePos.y() << std::endl;
            }
            else{  // empty place on simulation map
                std::cout << "new simulation object" << choosePos.x() << " " << choosePos.y() << std::endl;
                createPseudoSimObj(choosePos.x(), choosePos.y());
                //openItemSetWind();
            }
        }*/
    }
}


void SimulationScene::InitSimRun(){
    std::cout << "TEST1" << std::endl;
    _simTimer.start(16);
}
void SimulationScene::StopSimRun(){
    _simTimer.stop();
}
void SimulationScene::StoreSimObj(){
    _robotsFromCore = _core->RectFromCore();
    for(int robot = 0; robot < 1; robot++){
        QGraphicsEllipseItem* newRobot = new QGraphicsEllipseItem(0,0,_robotsFromCore.w,_robotsFromCore.h);
        newRobot->setPen(blackPen);
        newRobot->setBrush(redBrush);
        newRobot->setPos(_robotsFromCore.x,_robotsFromCore.y);
        addItem(newRobot);
        _robotsGUIVector.push_back(newRobot);
    }
}

void SimulationScene::_OneSimFrame(){
    std::cout << "TEST2" << std::endl;
    _core->MoveAllObjects();
    _robotsFromCore = _core->RectFromCore();
    for(auto robot: _robotsGUIVector){
        std::cout << _robotsFromCore.x <<" "<< _robotsFromCore.y << std::endl;

        robot->setPos(_robotsFromCore.x,_robotsFromCore.y);
    }
}
