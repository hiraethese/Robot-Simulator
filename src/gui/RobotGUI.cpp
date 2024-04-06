#include "RobotGUI.h"

RobotGUI::RobotGUI(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, w, h, parent)
{
}

void RobotGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::RightButton){
        std::cout << "Test" << std::endl;
    }
}
