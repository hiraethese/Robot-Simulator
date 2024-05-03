/**
 * @file WallGUI.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for display simulation object from core with type "wall"
 */

#include "WallGUI.h"


WallGUI::WallGUI(SimObjView view, ConnectorGUI* conn)
    :QGraphicsRectItem(0, 0, view.w, view.h)
{
    
    _conn = conn;
    _orderIndex = view.orderIndex;

    setPen(getPen());
    setBrush(getBrushByCode(view.color));
    setPos(view.x_GUI, view.y_GUI);

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
