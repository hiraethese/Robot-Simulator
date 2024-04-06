#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
class RobotGUI : public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit RobotGUI(qreal x, qreal y, qreal w, qreal h, QGraphicsItem *parent = nullptr);
private:
    int _orderIndex = 100;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void getActualOrderIndex(int orderIndex);

};

#endif // ROBOTGUI_H
