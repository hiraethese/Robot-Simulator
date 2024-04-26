#ifndef WALLGUI_H
#define WALLGUI_H

#include "ConnectorGUI.h"

class WallGUI : public QGraphicsRectItem
{
public:
    WallGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex)
        :QGraphicsRectItem(x, y, w, h)
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
            emit _conn->connectSig(GetOrderIndex(), false);
        }

    }
};
#endif // WALLGUI_H
