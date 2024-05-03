/**
 * @file RobotGUI.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for display simulation object from core with type "robot"
 */
#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QColor>
#include "ConnectorGUI.h"
#include "../../style.h"

/**
 * @brief Class for display simulation object from core with type "robot"
 * 
 */
class RobotGUI : public QGraphicsEllipseItem
{

public:

    /**
     * @brief Construct a new Robot G U I object
     * 
     * @param x left high corner of display on OX
     * @param y left high corner of display on OY
     * @param w width of display
     * @param h height of display
     * @param conn object for connection simulation scene with display
     * @param orderIndex index of simulation object with type "robot" which will be displayed
     */
    RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex, qreal collisionDistance, colors colorsCode, bool isControlled)
        :QGraphicsEllipseItem(0, 0, w, h)
    {

        _conn = conn;
        _orderIndex = orderIndex;
        _isControlled = isControlled;

        if(!_isControlled){
            _CreateDetectedZone(x, y, w, h, collisionDistance);
        }

        setPen(getPen());
        setBrush(getBrushByCode(colorsCode));
        setPos(x, y);
    }


    /**
     * @brief Get order index of robot which displayed
     * 
     * @return int 
     */
    int GetOrderIndex(){

        return _orderIndex;

    }

    bool GetRobotType(){

        return _isControlled;

    }

    QGraphicsEllipseItem* GetDetectedZone(){
        
        return _detectedZone;
    
    }

    /**
     * @brief Delete detected zones display for robot
     * 
     */
    void DeleteDetectedZone(){
        
        if(_detectedZone != nullptr){
        
            delete _detectedZone;
            _detectedZone = nullptr;

        }

    }


private:

    /**
     * @brief Order index of robot which displayed
     */
    int _orderIndex;

    bool _isControlled;

    /**
     * @brief Object for connection simulation scene with display
     */
    ConnectorGUI* _conn;

    /**
     * @brief Displaying detected zone arround robots
     * 
     */
    QGraphicsEllipseItem* _detectedZone = nullptr;

    /**
     * @brief Create new detected zone for robot
     * 
     * @param detectedDistance distance on wich robot can detect wall
     */
    void _CreateDetectedZone(qreal x, qreal y, qreal w, qreal h,qreal collisionDistance){
        
        DeleteDetectedZone();
        
        if(_detectedZone == nullptr){

            _detectedZone = new QGraphicsEllipseItem(0, 0, w + collisionDistance * 2, h + collisionDistance * 2);
            _detectedZone->setPos(x - collisionDistance, y - collisionDistance);
            setPen(getPen());
            
        }
    }

protected:

    /**
     * @brief Override abstract method from base class for catching users click on rpbots display
     * 
     * @param event catched users event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override{
        // only for double click by right mouse button
        if(event->button() == Qt::RightButton){
            // signal about it
            emit _conn->connectSig(GetOrderIndex(), true);
        }
    }

};

#endif // ROBOTGUI_H
