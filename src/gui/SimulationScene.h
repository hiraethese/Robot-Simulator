#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QTimer>
#include <vector>

#include "style.h"

#include "../core/Core.h"
#include "SimObjGUI.h"

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SimulationScene(QObject *parent = nullptr);
    void CleareSimulationScene();
    bool flagSettingMode = false;
    void LoadSimObj();
    void InitSimRun();
    void StopSimRun();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    ConnectorGUI _conn;
    Core* _core;
    QTimer _simTimer;
    std::vector<RobotGUI*>_robotsGUIVector;
    std::vector<WallGUI*>_wallsGUIVector;
    Rectangle _robotsFromCore;

signals:

    void ClickSig(QPointF clickPoint);
    void RequestSimObjSig(int orderIndex);

private slots:

    void _OneSimFrameSlot();
};

#endif // SIMULATIONSCENE_H
