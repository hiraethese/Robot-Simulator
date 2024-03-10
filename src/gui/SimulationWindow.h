#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
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
#include "../core/core.h"
#include "../controller/controller.h"

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

    void storeSimGUI();
    void runSimGUI();
    void stopSimGUI();

    void runSettingsMode();
    void stopSettingsMode();
    void createSetNet();
    void deleteSetNet();
private:
    static const unsigned SIM_WIN_Y = 750;
    static const unsigned SIM_WIN_X = 1800;
    static const unsigned NET_ITEM = 30;
    std::vector<QGraphicsLineItem*> setNetVectorGUI;

    // -- SIMULATION GUI --
    QTimer timerOneFrame;

    QGraphicsView* simGraphView = nullptr;
    QGraphicsScene* simGraphScene = nullptr;

    std::vector<QGraphicsEllipseItem*> robotsVectorGUI;
    //QVector<QGraphicsRectItem*> wallsVectorGUI;
    Rectangle robotsFromController;

    QPointF actualPositionOfItem;
    unsigned actualUserRobotPen;

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


    void createSimGUI();
    void deleteSimGUI();
    void cleanSimGUI();


    // -- FRONT --

    QVBoxLayout* simulationsLayot;
    QHBoxLayout* simBodyowBoxLayout;      // simulations window layout
    QHBoxLayout* simulatyonEngineLayout;  // engine for simulation
    QVBoxLayout* robotsEngineLayout;      // moves button layput
    QHBoxLayout* highRobotsEngineLayout;  // forward move button layout
    QHBoxLayout* lowRobotsEngineLayout;   // right/stop/left buttons layout

    QPushButton* startSimulationButton;
    QPushButton* stopSimulatopnButton;
    QPushButton* continueSimulationButton;
    QPushButton* forwardMoveButton;
    QPushButton* leftMoveButton;
    QPushButton* stopMoveButton;
    QPushButton* rightMoveButton;

    void createSimulattionsButtons();
    void deleteSimulationsButtons();
    void createSimulationsLayout();
    void deleteSimulationsLayout();
    void setSimualtionEngineSignals();

    void setUnsetSimButtons(bool flagIsSet);

signals:

private slots:
    void oneSimFrameGUI();
};

#endif // SIMULATIONWINDOW_H
