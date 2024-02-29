#ifndef SIMULATIONBODY_H
#define SIMULATIONBODY_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include "simulationwindow.h"
class SimulationBody : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationBody(QWidget *parent = nullptr);
    ~SimulationBody();
private:
    SimulationWindow* simWind;

    QVBoxLayout* simulationsLayot;
    QHBoxLayout* simWindowBoxLayout;      // simulations window layout
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
signals:
};

#endif // SIMULATIONBODY_H
