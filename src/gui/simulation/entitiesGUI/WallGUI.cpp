/**
 * @file WallGUI.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for display simulation object from core with type "wall"
 */

#include "WallGUI.h"


WallGUI::WallGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex, colors colorsCode)
    :QGraphicsRectItem(0, 0, w, h)
{
    _conn = conn;
    _orderIndex = orderIndex;

    setPen(getPen());
    setBrush(getBrushByCode(colorsCode));
    setPos(x, y);
}

int WallGUI::GetOrderIndex(){

    return _orderIndex;

}

void WallGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // only for double click by right mouse button
    if(event->button() == Qt::RightButton){
        // signal about it
        emit _conn->connectSig(GetOrderIndex(), false);
    }

}
