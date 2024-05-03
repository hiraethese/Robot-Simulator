/**
 * @file RobotGUI.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for display simulation object from core with type "robot"
 */
#include "RobotGUI.h"

RobotGUI::RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex, qreal collisionDistance, colors colorsCode, bool isControlled)
    :QGraphicsEllipseItem(0, 0, w, h)
{

    _conn = conn;
    _orderIndex = orderIndex;
    _isControlled = isControlled;

    // only for automatic robot
    if(!_isControlled){
        _CreateDetectedZone(x, y, w, h, collisionDistance);
    }

    setPen(getPen());
    setBrush(getBrushByCode(colorsCode));
    setPos(x, y);
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

void RobotGUI::_CreateDetectedZone(qreal x, qreal y, qreal w, qreal h,qreal collisionDistance){
    
    DeleteDetectedZone();
    
    if(_detectedZone == nullptr){

        _detectedZone = new QGraphicsEllipseItem(0, 0, w + collisionDistance * 2, h + collisionDistance * 2);
        _detectedZone->setPos(x - collisionDistance, y - collisionDistance);
        setPen(getPen());
        
    }
}


void RobotGUI::UpdatePosition(qreal x, qreal y, qreal collisionDistance){
        
        // only for automatic robot
        if(!_isControlled){
            _detectedZone->setPos(x - collisionDistance, y - collisionDistance);
        }
        
        setPos(x, y);

}

void RobotGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // only for double click by right mouse button
    if(event->button() == Qt::RightButton){
        // signal about it
        emit _conn->connectSig(GetOrderIndex(), true);
    }
}
