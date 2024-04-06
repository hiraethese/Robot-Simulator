#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

class RobotGUI : public QGraphicsEllipseItem
{
public:
    RobotGUI(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // ROBOTGUI_H
