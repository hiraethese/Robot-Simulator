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

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();

    unsigned actualUserRobotColor = 0;
    unsigned actualWallColor = 3;
    unsigned actualBotRobotColor = 4;
    unsigned actualMapColor = 5;

    void StoreSimGUI();
    void RunSimGUI();
    void StopSimGUI();
private:
    Core* _core;
    // -- SIMULATION GUI --
    QTimer _timerOneFrame;

    QGraphicsView* _simGraphView = nullptr;
    QGraphicsScene* _simGraphScene = nullptr;

    std::vector<QGraphicsEllipseItem*> _robotsVectorGUI;
    //QVector<QGraphicsRectItem*> _wallsVectorGUI;
    Rectangle _robotsFromController;

    QPointF _actualPositionOfItem;
    unsigned _actualUserRobotPen;

    std::vector<QBrush*> _brushVector;
    QBrush* _redBrush;       // 0 in _brushVector
    QBrush* _yellowBrush;    // 1 in _brushVector
    QBrush* _greanBrush;     // 2 in _brushVector
    QBrush* _blueBrush;      // 3 in _brushVector
    QBrush* _blackBrush;     // 4 in _brushVector
    QBrush* _whiteBrush;     // 5 in _brushVector

    std::vector<QPen*> _penVector;
    unsigned _GetActualUserRobotPen();
    QPen* _blackPen;         // 0 in _penVector
    QPen* _whitePen;         // 1 in _penVector


    void _CreateSimGUI();
    void _DeleteSimGUI();
    void _CleanSimGUI();


    // -- FRONT --

    QVBoxLayout* _simulationsLayot;
    QHBoxLayout* _simBodyowBoxLayout;      // simulations window layout
    QHBoxLayout* _simulatyonEngineLayout;  // engine for simulation
    QVBoxLayout* _robotsEngineLayout;      // moves button layput
    QHBoxLayout* _highRobotsEngineLayout;  // forward move button layout
    QHBoxLayout* _lowRobotsEngineLayout;   // right/stop/left buttons layout

    QPushButton* _startSimulationButton;
    QPushButton* _stopSimulatopnButton;
    QPushButton* _continueSimulationButton;
    QPushButton* _forwardMoveButton;
    QPushButton* _leftMoveButton;
    QPushButton* _stopMoveButton;
    QPushButton* _rightMoveButton;

    void _CreateSimulattionsButtons();
    void _DeleteSimulationsButtons();
    void _CreateSimulationsLayout();
    void _DeleteSimulationsLayout();
    void _SetSimualtionEngineSignals();

    void _SetUnsetSimButtons(bool flagIsSet);

signals:

private slots:
    void _OneSimFrameGUI();
};

#endif // SIMULATIONWINDOW_H
