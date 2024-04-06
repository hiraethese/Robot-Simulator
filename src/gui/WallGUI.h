#ifndef WALLGUI_H
#define WALLGUI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
class WallGUI : public QGraphicsRectItem
{
public:
    WallGUI(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // WALLGUI_H
