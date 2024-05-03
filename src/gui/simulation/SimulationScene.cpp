/**
 * @file SimulationScene.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for simulation scene
 */
#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{
    // connect to core
    _core = Core::getInstance();
    
    setBackgroundBrush(getBrushByCode(WHITE));

    // when timer have timeout -> make new animations frame
    connect(&_simTimer, &QTimer::timeout, this, &SimulationScene::_OneSimFrameSlot);
    // when client request settings about simulation scene -> send it to SimulationWindow
    connect(&_conn, &ConnectorGUI::connectSig, this, [=](int orderIndex, bool isRobot){emit RequestSimObjSig(orderIndex, isRobot);});
}

void SimulationScene::CleareSimulationScene(){


    for(auto robot: _robotsGUIVector){  // remove every robots display
        
        if(!robot->GetRobotType()){
            removeItem(robot->GetDetectedZone());
            robot->DeleteDetectedZone();
        }

        removeItem(robot->GetLineDirection());
        robot->DeleteLineDirection();

        removeItem(robot);
        delete robot;
    }


    for(auto wall: _wallsGUIVector){  // remove every wall display

        removeItem(wall);
        delete wall;
    }

    _robotsGUIVector.clear();
    _wallsGUIVector.clear();

}

void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){

    // create new simualtions objects display only by left click mouse button 
    if(event->button() == Qt::LeftButton){

        // signalizate about it
        emit ClickSig(event->scenePos());
    }
}


void SimulationScene::InitSimRun(){

    // one animations frame interval init
    _simTimer.start(1000 / 60);

}

void SimulationScene::StopSimRun(){

    // stop animation
    _simTimer.stop();

}

void SimulationScene::LoadSimObj(){

    // delete previous simulations objects displays
    CleareSimulationScene();

    // store view of actual simulations objects from core
    std::vector<SimObjView> robotsView = _core->GetVectorRobotsView();
    std::vector<SimObjView> wallsView = _core->GetVectorWallsView();

    // init and push new robots displays
    for(SimObjView robot: robotsView){

        PushNewRobotToMap(robot);

    }

    // init and push new walls displays
    for(SimObjView wall: wallsView){

        PushNewWallToMap(wall);

    }
}

void SimulationScene::_OneSimFrameSlot(){

    // signal about moving all object on new animations frame
    _core->MoveAllObjects();

    // call new view for every robots from core
    std::vector<SimObjView> robotsView = _core->GetVectorRobotsView();

    for(long unsigned int i = 0; i < _robotsGUIVector.size(); i++){  // TODO: raise EXCEPTION when not simular size of gui and view vector

        _robotsGUIVector[i]->UpdatePosition(robotsView[i]);

    }

    // update simulation scene
    update();

}

RobotGUI* SimulationScene::_CreateNewRobotGui(SimObjView view){
    // create new robot
    RobotGUI* newRobot = new RobotGUI(view, &_conn);
    
    // add detected zone for robot
    if(!newRobot->GetRobotType()){
        addItem(newRobot->GetDetectedZone());
    }
    
    // insert new robot to scene
    addItem(newRobot);
    
    // add robots line direction
    addItem(newRobot->GetLineDirection());

    update();
    return newRobot;

}

WallGUI* SimulationScene::_CreateNewWallGUI(SimObjView view){
    // create new wall
    WallGUI* newWall = new WallGUI(view, &_conn);
    
    // insert new wall to scene
    addItem(newWall);
    
    update();
    return newWall;
}

void SimulationScene::PushNewRobotToMap(SimObjView view){
    // create new robots display
    RobotGUI* newRobot = _CreateNewRobotGui(view); 
    // push on vector
    _robotsGUIVector.push_back(newRobot);

}


void SimulationScene::PushNewWallToMap(SimObjView view){
    // create new walls display
    WallGUI* newWall = _CreateNewWallGUI(view);
    // push on vector
    _wallsGUIVector.push_back(newWall);

}

std::vector<RobotGUI*>::iterator SimulationScene::_GetRobotByOrderIndex(int orderIndex){
    
    auto it = _robotsGUIVector.begin();

    while(it != _robotsGUIVector.end()){
        
        if((*it)->GetOrderIndex() == orderIndex){
            // find robots display by order index
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
            // find walls display by order index
            return it;
        }

        ++it;

    }

    return it;
}


ICP_CODE SimulationScene::RemoveRobotByOrderIndex(int orderIndex){
    // search robots display
    auto itRobotToRemove = _GetRobotByOrderIndex(orderIndex);
    // if find
    if(itRobotToRemove != _robotsGUIVector.end()){

        RobotGUI* robotToRemove = *itRobotToRemove;
        
        // cut from vector
        _robotsGUIVector.erase(itRobotToRemove);
        
        // delete detected zone (only for automatic robot)
        if(!robotToRemove->GetRobotType()){
            removeItem(robotToRemove->GetDetectedZone());
            robotToRemove->DeleteDetectedZone();
        }

        // delete line direction
        removeItem(robotToRemove->GetLineDirection());
        robotToRemove->DeleteLineDirection();

        // delete from scene robot
        removeItem(robotToRemove);
        delete robotToRemove;

        return CODE_OK;
    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_GUI;

}

ICP_CODE SimulationScene::RemoveWallByOrderIndex(int orderIndex){
    // search wall display
    auto itWallToRemove = _GetWallByOrderIndex(orderIndex);
    // if find
    if(itWallToRemove != _wallsGUIVector.end()){

        WallGUI* wallToRemove = *itWallToRemove;
        
        // cur from vector
        _wallsGUIVector.erase(itWallToRemove);
        
        // delete from scene
        removeItem(wallToRemove);
        delete wallToRemove;

        return CODE_OK;
    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_GUI;
}

ICP_CODE SimulationScene::UpdateSimObjGuiState(int orderIndex, bool isRobot){
    SimObjView view;
    // search view simulations object to updating
    _core->GetViewByOrderGUI(&view, orderIndex, isRobot);
    if(isRobot){  // update robots display
        
        // find display in vector
        auto itRobotForUpd = _GetRobotByOrderIndex(orderIndex);
        if(itRobotForUpd != _robotsGUIVector.end()){
            
            // delete detected zone (only for automatic robot)
            if(!(*itRobotForUpd)->GetRobotType()){
                removeItem((*itRobotForUpd)->GetDetectedZone());
                (*itRobotForUpd)->DeleteDetectedZone();
            }

            // delete robots line direction
            removeItem((*itRobotForUpd)->GetLineDirection());
            (*itRobotForUpd)->DeleteLineDirection();

            // delete robots display from scene
            removeItem(*itRobotForUpd);
            delete *itRobotForUpd;
            
            // recrate with updating
            *itRobotForUpd = _CreateNewRobotGui(view);
            return CODE_OK;
        }

    }
    else{  // update walls display
        // find display in vector
        auto itWallForUpd = _GetWallByOrderIndex(view.orderIndex);
        if(itWallForUpd != _wallsGUIVector.end()){
            
            // delete walls display from scene
            removeItem(*itWallForUpd);
            delete *itWallForUpd;
            
            // recrate with new view
            *itWallForUpd = _CreateNewWallGUI(view);
            return CODE_OK;
        }

    }

    return CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_GUI;
}
