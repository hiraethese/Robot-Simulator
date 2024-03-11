#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{
    createBrunch();
    createPen();
    connect(&timerSimGUI, &QTimer::timeout, this, &SimulationScene::oneSimFrameGUI);
}

void SimulationScene::deleteSimulationScene(){
    cleanSettingsMode();
}


void SimulationScene::storeSimGUI(){}

void SimulationScene::runSimGUI(){
    timerSimGUI.start(16);
}
void SimulationScene::stopSimGUI(){

}

void SimulationScene::runSettingsMode(){
    stopSimGUI();
    flagSettingMode = true;
}
void SimulationScene::stopSettingsMode(){
    flagSettingMode = false;
}


void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(flagSettingMode){
        cleanSettingsMode();
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
        }
    }
}

void SimulationScene::oneSimFrameGUI(){
    std::cout << "NEW SIMULATION FRAME" << std::endl;
}

void SimulationScene::createNewSimObj(){
    // core_create_new_item()
}
void SimulationScene::deleteSimObj(){

}
void SimulationScene::updateSimObj(){

}

void SimulationScene::cleanSettingsMode(){
    deletePseudoSimObj();
}

void SimulationScene::createPseudoSimObj(unsigned w, unsigned h){
    if(!pseudoSiObjGUI){
        pseudoSiObjGUI = new QGraphicsRectItem(0, 0, 30, 30);
        pseudoSiObjGUI->setPos(w, h);
        pseudoSiObjGUI->setPen(blackPen);
        addItem(pseudoSiObjGUI);
    }
}
void SimulationScene::deletePseudoSimObj(){
    if(pseudoSiObjGUI){
        removeItem(pseudoSiObjGUI);
        delete pseudoSiObjGUI;
        pseudoSiObjGUI = nullptr;
    }
}

void core_findSimObjGUI(){

}
