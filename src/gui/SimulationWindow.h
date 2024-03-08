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
#include "SimulationBody.h"
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
private:
    QPointF actualPositionOfItem;
    unsigned actualUserRobotPen;
    unsigned getActualUserRobotPen();
    std::vector<QBrush*> brashVector;
    std::vector<QPen*> penVector;
    QBrush* redBrush;       // 0
    QBrush* yellowBrush; // 1
    QBrush* greanBrush;   // 2
    QBrush* blueBrush;     // 3
    QBrush* blackBrush;   // 4
    QBrush* whiteBrush;   // 5
    QPen* blackPen;       // 0
    QPen* whitePen;       // 1


    QTimer timerSimEmit;
    QGraphicsView* simGraphView = nullptr;
    QGraphicsScene* simGraphScene = nullptr;
    std::vector<QGraphicsEllipseItem*> robotsVectorGUI;
    //QVector<QGraphicsRectItem*> wallsVectorGUI;

    //SimulationBody* simBody;

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

    void createSimGUI();
    void deleteSimGUI();
    void cleanSimGUI();

    void createSimulattionsButtons();
    void deleteSimulationsButtons();
    void createSimulationsLayout();
    void deleteSimulationsLayout();
    void setSimualtionEngineSignals();

    void setUnsetSimButtons(bool flagIsSet);

signals:

private slots:
    void updateSimGUI();
};

#endif // SIMULATIONWINDOW_H
