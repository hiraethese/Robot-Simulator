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

#include "../style.h"
#include "../../core/Core.h"
#include "entitiesGUI/RobotGUI.h"
#include "entitiesGUI/WallGUI.h"

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

    void CreateNewRobot(SimObjView view, int orderIndex, float x, float y);
    void CreateNewWall(SimObjView view,  int orderIndex, float x, float y);
    ICP_CODE UpdateSimObjGuiState(SimObjView view);
    ICP_CODE RemoveRobotByOrderIndex(int orderIndex);
    ICP_CODE RemoveWallByOrderIndex(int orderIndex);

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
    
signals:

    void ClickSig(QPointF clickPoint);
    void RequestSimObjSig(int orderIndex, bool isRobot);

private slots:

    void _OneSimFrameSlot();
};

#endif // SIMULATIONSCENE_H
