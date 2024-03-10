#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>
#include <vector>

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SimulationScene(QObject *parent = nullptr);
    void cleanedSimScene();
private:
    std::vector<QGraphicsEllipseItem*>robotsVectorGUI;
    std::vector<QGraphicsRectItem*>wallsVectorGUI;
    std::vector<QBrush*> brushVector;
    QBrush* redBrush;       // 0 in brushVector
    QBrush* yellowBrush;    // 1 in brushVector
    QBrush* greanBrush;     // 2 in brushVector
    QBrush* blueBrush;      // 3 in brushVector
    QBrush* blackBrush;     // 4 in brushVector
    QBrush* whiteBrush;     // 5 in brushVector

    std::vector<QPen*> penVector;
    unsigned getActualUserRobotPen();
    QPen* blackPen;         // 0 in penVector
    QPen* whitePen;         // 1 in penVector
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

};

#endif // SIMULATIONSCENE_H
