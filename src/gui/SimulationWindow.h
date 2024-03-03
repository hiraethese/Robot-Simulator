#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>
#include "SimulationBody.h"
#include "../core/core.h"

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();

    void emitStoreGUISimSigFromSimWind();
    void emitRunGUISimSigFromSimWind();
private:
    SimulationBody* simBody;

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

signals:
private slots:
};

#endif // SIMULATIONWINDOW_H
