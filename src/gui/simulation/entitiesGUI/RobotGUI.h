#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include "ConnectorGUI.h"

class RobotGUI : public QGraphicsEllipseItem
{

public:

    RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex)
        :QGraphicsEllipseItem(x, y, w, h)
    {

        _conn = conn;
        _orderIndex = orderIndex;

    }


    int GetOrderIndex(){

        return _orderIndex;

    }

private:

    int _orderIndex;
    ConnectorGUI* _conn;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override{
        if(event->button() == Qt::RightButton){
            std::cout << "Clikc on Order index: " << _orderIndex << std::endl;
            emit _conn->connectSig(GetOrderIndex(), true);
        }
    }

};

#endif // ROBOTGUI_H
