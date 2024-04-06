#include "WallGUI.h"

WallGUI::WallGUI(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, w, h, parent)
{
}

void WallGUI::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::RightButton){
        std::cout << "Test" << std::endl;
    }
}
