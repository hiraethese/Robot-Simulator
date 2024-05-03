/**
 * @file RobotGUI.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for display simulation object from core with type "robot"
 */
#include "RobotGUI.h"

RobotGUI::RobotGUI(SimObjView view, ConnectorGUI* conn)
    :QGraphicsEllipseItem(0, 0, view.w, view.h)
{

    _conn = conn;
    _orderIndex = view.orderIndex;
    _isControlled = view.isControlled;

    // only for automatic robot
    if(!_isControlled){
        _CreateDetectedZone(view.getDetectedZonePos(), view.getDetectedZoneSize());
    }

    setPen(getPen());
    setBrush(getBrushByCode(view.color));
    setPos(view.x_GUI, view.y_GUI);
}


int RobotGUI::GetOrderIndex(){

    return _orderIndex;

}

bool RobotGUI::GetRobotType(){

    return _isControlled;

}

QGraphicsEllipseItem* RobotGUI::GetDetectedZone(){
    
    return _detectedZone;

}

void RobotGUI::DeleteDetectedZone(){
    
    if(_detectedZone != nullptr){
    
        delete _detectedZone;
        _detectedZone = nullptr;

    }

}

void RobotGUI::_CreateDetectedZone(Vector2d pos, Vector2d size){
    
    DeleteDetectedZone();
    
    if(_detectedZone == nullptr){

        _detectedZone = new QGraphicsEllipseItem(0, 0, size.x, size.y);
        _detectedZone->setPos(pos.x, pos.y);
        setPen(getPen());
        
    }
}


void RobotGUI::UpdatePosition(SimObjView view){
        
        // only for automatic robot
        Vector2d detectedZonePos = view.getDetectedZonePos();
        if(!_isControlled){
            _detectedZone->setPos(detectedZonePos.x, detectedZonePos.y);
        }
        
        setPos(view.x_GUI, view.y_GUI);

}

void RobotGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // only for double click by right mouse button
    if(event->button() == Qt::RightButton){
        // signal about it
        emit _conn->connectSig(GetOrderIndex(), true);
    }
}
