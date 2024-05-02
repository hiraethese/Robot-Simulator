/**
 * @file WallGUI.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for display simulation object from core with type "wall"
 */
#ifndef WALLGUI_H
#define WALLGUI_H

#include "ConnectorGUI.h"

/**
 * @brief Class for display simulation object from core with type "wall"
 * 
 */
class WallGUI : public QGraphicsRectItem
{
public:
    /**
     * @brief Construct a new WallGUI object
     * 
     * @param x left high corner of display on OX
     * @param y left high corner of display on OY
     * @param w width of display
     * @param h height of display
     * @param conn object for connection simulation scene with display
     * @param orderIndex index of simulation object with type "wall" which will be displayed
     */
    WallGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex)
        :QGraphicsRectItem(x, y, w, h)
    {
        _conn = conn;
        _orderIndex = orderIndex;
    }

    /**
     * @brief Get order index of wall which displayed
     * 
     * @return int 
     */
    int GetOrderIndex(){


        return _orderIndex;

    }

private:

    /**
     * @brief order index of wall which displayed
     */
    int _orderIndex;

    /**
     * @brief object for connection simulation scene with display
     */
    ConnectorGUI* _conn;

protected:

    /**
     * @brief Override abstract method from base class for catching users click on walls display
     * 
     * @param event catched users event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override{
        // only for double click by right mouse button
        if(event->button() == Qt::RightButton){
            // signal about it
            emit _conn->connectSig(GetOrderIndex(), false);
        }

    }
};
#endif // WALLGUI_H
