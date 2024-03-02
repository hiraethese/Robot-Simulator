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
    //connect(forwardMoveButton, SIGNAL(clicked()), simWind, SLOT(moveSimRectDown()));
    connect(forwardMoveButton, SIGNAL(clicked()), simWind, SLOT(repaint()));
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

    forwardMoveButton = new QPushButton("forward");
    leftMoveButton = new QPushButton("left");
    stopMoveButton = new QPushButton("stop");
    rightMoveButton = new QPushButton("right");
}

void SimulationBody::deleteSimulationsButtons(){

    delete forwardMoveButton;
    delete leftMoveButton;
    delete stopMoveButton;
    delete rightMoveButton;
}

void SimulationBody::runSimObject(){
    std::cout << "start simulation" << std::endl;
}
void SimulationBody::storeSimulationMap(){
    std::cout << "store simulation" << std::endl;
}
void SimulationBody::pauseSimObject(){
    std::cout << "break simulation" << std::endl;
}
void SimulationBody::continueSimulObject(){
    std::cout << "continue simulation" << std::endl;
}

bool SimulationBody::isSimRun(){
    return devSimIsRun;
}

bool SimulationBody::isSimMapSet(){
    return devSimMapIsSet;
}
