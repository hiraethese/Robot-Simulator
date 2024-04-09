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
#include "SimObjGUI/RobotGUI.h"
#include "SimObjGUI/WallGUI.h"

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

    void CreateNewRobot(SimObjView view, float x, float y);
    void CreateNewWall(SimObjView view,  float x, float y);

    void RemoveRobotByOrderIndex(int orderIndex);
    void RemoveWallByOrderIndex(int orderIndex);

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:

    ConnectorGUI _conn;

    Core* _core;

    QTimer _simTimer;

    std::vector<RobotGUI*>_robotsGUIVector;
    std::vector<WallGUI*>_wallsGUIVector;
    std::vector<RobotGUI*>::iterator _GetRobotByOrderIndex(int orderIndex);
    std::vector<WallGUI*>::iterator _GetWallByOrderIndex(int orderIndex);

    Rectangle _robotsFromCore;

    int _index = 1; // after deleted; index will be inside view
    SimObjView FromRectToView(Rectangle rect); // after delete; will not use Rectangle(use view)
signals:

    void ClickSig(QPointF clickPoint);
    void RequestSimObjSig(int orderIndex, bool isRobot);

private slots:

    void _OneSimFrameSlot();

};

#endif // SIMULATIONSCENE_H
