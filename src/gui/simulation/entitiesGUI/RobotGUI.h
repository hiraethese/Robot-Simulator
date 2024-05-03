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
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QPen>
#include "ConnectorGUI.h"
#include "../../style.h"
#include "../../../core/icplib.h"
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
     * @param collisionDistance distance on which automatic robot can detect wall
     * @param colorsCode code of robots color
     * @param isControlled subtype of robot (automatic/controlled)
     */
    RobotGUI(SimObjView view, ConnectorGUI* conn);

    /**
     * @brief Get order index of robot which displayed
     * 
     * @return int 
     */
    int GetOrderIndex();

    /**
     * @brief Get the subtype of robot
     * 
     * @return true is controlled subtype
     * @return false  is automatic subtype
     */
    bool GetRobotType();

    QGraphicsEllipseItem* GetDetectedZone();
    QGraphicsLineItem* GetLineDirection();

    /**
     * @brief Delete detected zones display for robot
     * 
     */
    void DeleteDetectedZone();

    void DeleteLineDirection();


    /**
     * @brief Update robots display by one frame
     *
     * @param x left high corner of display on OX
     * @param y left high corner of display on OY
     * @param collisionDistance distance on which automatic robot can detect wall
     */
    void UpdatePosition(SimObjView view);

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
     * @brief Create display of distance arround robot diswplay on wich automatic robot can detect wall
     * 
     * @param x left high corner of display on OX
     * @param y left high corner of display on OY
     * @param w width of display
     * @param h height of display
     * @param collisionDistance distance on which automatic robot can detect wall
     */
    void _CreateDetectedZone(Vector2d pos, Vector2d size);



    QGraphicsLineItem* _lineDirection = nullptr;
    void _CreateLineDirection(qreal xCentre, qreal yCentre, qreal xCircle, qreal yCircle);


protected:

    /**
     * @brief Override abstract method from base class for catching users click on rpbots display
     * 
     * @param event catched users event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // ROBOTGUI_H
