#ifndef SIMOBJGUI_H
#define SIMOBJGUI_H

#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QObject>

class ConnectorGUI : public QObject
{
    Q_OBJECT
public:
    explicit ConnectorGUI(QObject *parent = nullptr): QObject{parent}
    {}

signals:
    void connectSig(int data);
};



class RobotGUI : public QGraphicsEllipseItem
{

public:

    explicit RobotGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex): QGraphicsEllipseItem(x, y, w, h, nullptr)
    {
        this->conn = conn;
        _orderIndex = orderIndex;
    }


    ConnectorGUI* conn;

private:

    int _orderIndex;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override{
        if(event->button() == Qt::RightButton){
            std::cout << "Test" << std::endl;
            emit conn->connectSig(_orderIndex);
        }
    }

};


class WallGUI : public QGraphicsRectItem
{
public:
    explicit WallGUI(qreal x, qreal y, qreal w, qreal h, ConnectorGUI* conn, int orderIndex): QGraphicsRectItem(x, y, w, h, nullptr)
    {
        this->conn = conn;
        _orderIndex = orderIndex;
    }

    ConnectorGUI* conn;

private:
    int _orderIndex;
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override{

        if(event->button() == Qt::RightButton){
            std::cout << "Test" << std::endl;
            emit conn->connectSig(_orderIndex);
        }

    }
};

#endif // SIMOBJGUI_H
