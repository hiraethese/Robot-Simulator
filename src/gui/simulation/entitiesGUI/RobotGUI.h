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
     * @param view information about robot
     * @param conn object for connection simulation scene with display
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

    /**
     * @brief Get robots detected zone
     * 
     * @return QGraphicsEllipseItem* 
     */
    QGraphicsEllipseItem* GetDetectedZone();

    /**
     * @brief Get robots line direction
     * 
     * @return QGraphicsLineItem* 
     */
    QGraphicsLineItem* GetLineDirection();

    /**
     * @brief Delete detected zones display for robot
     */
    void DeleteDetectedZone();

    /**
     * @brief Delete line direction display for robot
     */
    void DeleteLineDirection();


    /**
     * @brief Update robots display by one frame
     *
     * @param view information about robots updating
     */
    void UpdatePosition(SimObjView view);

private:

    /**
     * @brief Order index of robot which displayed
     */
    int _orderIndex;

    /**
     * @brief subtype of robot
     */
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
     * @param pos left high coordinates for detected zone
     * @param size width and height for detected zone
     */
    void _CreateDetectedZone(Vector2d pos, Vector2d size);


    /**
     * @brief Line wich display moving direction for robot
     * 
     */
    QGraphicsLineItem* _lineDirection = nullptr;

    /**
     * @brief Create robots line direction
     * 
     * @param xCentre line from centrs coordinates on OX
     * @param yCentre line from centrs coordinates on OY
     * @param xCircle line to point on circle coordinates on OX
     * @param yCircle line to point on circle coordinates on OY
     */
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
