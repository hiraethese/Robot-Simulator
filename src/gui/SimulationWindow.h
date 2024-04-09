#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include <QTimer>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QColor>
#include <QPointF>
#include <iostream>
#include <QKeyEvent>

#include "../core/Core.h"
#include "SimulationScene.h"

enum BuildModeStatus{
    NotSetStatus,
    CursorStatus,
    ControllRobotStatus,
    BotRobotStatus,
    WallStatus
};

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();

    void SwitchBetweenSimAndBuild(bool flagIsBuild);

    void RunSimScene();
    void StopSimScene();

    BuildModeStatus buildModeStatus = NotSetStatus;

    void RemoveSimObjByOrderIndexSlot(int orderIndex, bool isRobot);

protected:

    void keyPressEvent(QKeyEvent *event) override;

private:

    Core* _core;

    QGraphicsView* _simulationView = nullptr;
    SimulationScene* _simulationScene = nullptr;


    void _CreateSimGUI();
    void _DeleteSimGUI();
    
    
    QVBoxLayout* _simulationsLayot;
    QHBoxLayout* _simBodyowBoxLayout;      // simulations window layout
    QHBoxLayout* _simulatyonEngineLayout;  // engine for simulation
    QVBoxLayout* _robotsEngineLayout;      // moves button layput
    QHBoxLayout* _highRobotsEngineLayout;  // forward move button layout
    QHBoxLayout* _lowRobotsEngineLayout;   // right/stop/left buttons layout
    QGridLayout* _settingsInfoLayout;

    QPushButton* _startSimulationButton;
    QPushButton* _stopSimulatopnButton;
    QPushButton* _continueSimulationButton;
    QPushButton* _forwardMoveButton = nullptr;
    QPushButton* _leftMoveButton = nullptr;
    QPushButton* _stopMoveButton = nullptr;
    QPushButton* _rightMoveButton = nullptr;

    QPushButton* _setSettingsButton;

    void _CreateSimulationsLayout();
    void _DeleteSimulationsLayout();
    void _SetUnsetSimButtons(bool flagIsSet);

signals:

    void UperClickSig(QPointF clickPoint);
    void RequestSimObjSig(int orderIndex, bool isRobot);
    void LoadSimSceneSig();
    void CreateNewSimObjSig(SimObjView view, float x, float y);

};

#endif // SIMULATIONWINDOW_H
