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
#include <QColor>
#include <QPointF>
#include <iostream>
#include "../core/Core.h"
#include "SimulationScene.h"

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();

    void SetSettingsEngine();
    void UnsetSettingsEngine();
    void SetSimulationEngine();
    void UnsetSimulationEngine();

    void RunSimScene();
    void StopSimScene();
    void StoreSimScene();

    void CreateSimulationEngineLayout();
    void DeleteSimulationEngineLayout();
private:
    Core* _core;
    bool flagSimEngineLayout = false;
    QGraphicsView* _simulationView = nullptr;
    SimulationScene* _simulationScene = nullptr;


    void _CreateSimGUI();
    void _DeleteSimGUI();
    void _CleanSimGUI();


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
    QPushButton* _forwardMoveButton;
    QPushButton* _leftMoveButton;
    QPushButton* _stopMoveButton;
    QPushButton* _rightMoveButton;

    QPushButton* _setSettingsButton;

    void _CreateSimulationsLayout();
    void _DeleteSimulationsLayout();
    void _SetUnsetSimButtons(bool flagIsSet);

};

#endif // SIMULATIONWINDOW_H
