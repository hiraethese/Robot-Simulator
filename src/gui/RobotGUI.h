#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include "ConnectorGUI.h"
class RobotGUI : public QGraphicsEllipseItem
{
public:
    explicit RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* con);
    ConnectorGUI* conn;
private:
    int _orderIndex = 100;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // ROBOTGUI_H
