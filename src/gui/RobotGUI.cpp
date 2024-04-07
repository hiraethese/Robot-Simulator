#include "RobotGUI.h"

RobotGUI::RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn)
    : QGraphicsEllipseItem(x, y, w, h, nullptr)
{
    this->conn = conn;
}

void RobotGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::RightButton){
        std::cout << "Test" << std::endl;
        emit conn->connectSig(_orderIndex);
    }
}
