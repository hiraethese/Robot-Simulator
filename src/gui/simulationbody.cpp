#include "simulationbody.h"

SimulationBody::SimulationBody(QWidget *parent)
    : QWidget{parent}
{

    simWind = new SimulationWindow();
    createSimulattionsButtons();
    createSimulationsLayout();
}

SimulationBody::~SimulationBody(){
    delete simWind;
    deleteSimulationsButtons();
    deleteSimulationsLayout();
}
void SimulationBody::createSimulationsLayout(){
    simulationsLayot = new QVBoxLayout();

    simWindowBoxLayout = new QHBoxLayout();
    simWindowBoxLayout->addStretch();
    simWindowBoxLayout->addWidget(simWind);
    simWindowBoxLayout->addStretch();

    simulatyonEngineLayout = new QHBoxLayout();
    robotsEngineLayout = new QVBoxLayout();
    //simulationRunEngineLayout = new QHBoxLayout();

    highRobotsEngineLayout = new QHBoxLayout();
    highRobotsEngineLayout->addStretch();
    highRobotsEngineLayout->addWidget(forwardMoveButton);
    highRobotsEngineLayout->addStretch();

    lowRobotsEngineLayout = new QHBoxLayout();
    lowRobotsEngineLayout->addStretch();
    lowRobotsEngineLayout->addWidget(leftMoveButton);
    lowRobotsEngineLayout->addWidget(stopMoveButton);
    lowRobotsEngineLayout->addWidget(rightMoveButton);
    lowRobotsEngineLayout->addStretch();

    robotsEngineLayout->addLayout(highRobotsEngineLayout);
    robotsEngineLayout->addLayout(lowRobotsEngineLayout);

    simulatyonEngineLayout->addStretch();
    simulatyonEngineLayout->addLayout(robotsEngineLayout);
    simulatyonEngineLayout->addStretch();

    simulationsLayot->addLayout(simWindowBoxLayout);
    simulationsLayot->addLayout(simulatyonEngineLayout);
    setLayout(simulationsLayot);
}
void SimulationBody::deleteSimulationsLayout(){
    delete simWindowBoxLayout;
    delete highRobotsEngineLayout;
    delete lowRobotsEngineLayout;
    delete robotsEngineLayout;
    delete simulatyonEngineLayout;
    delete simulationsLayot;
}
void SimulationBody::createSimulattionsButtons(){

    //startSimulationButton = new QPushButton("start");
    //stopSimulatopnButton = new QPushButton("stop");
    //continueSimulationButton = new QPushButton("continue");

    forwardMoveButton = new QPushButton("forward");
    leftMoveButton = new QPushButton("left");
    stopMoveButton = new QPushButton("stop");
    rightMoveButton = new QPushButton("right");

}

void SimulationBody::deleteSimulationsButtons(){

    //delete startSimulationButton;
    //delete stopSimulatopnButton;
    //delete continueSimulationButton;

    delete forwardMoveButton;
    delete leftMoveButton;
    delete stopMoveButton;
    delete rightMoveButton;
}
