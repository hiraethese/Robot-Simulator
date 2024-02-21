#include "simulationwindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1000, 1000);
    setWindowTitle("Simulation");
    initSimulationWindowButtons();
}

SimulationWindow::~SimulationWindow(){
    deleteSimulationWindowButtons();
}

void SimulationWindow::initSimulationWindowButtons(){
    startButton = new QPushButton("start", this);
    startButton->show();
}

void SimulationWindow::deleteSimulationWindowButtons(){
    delete startButton;
}
