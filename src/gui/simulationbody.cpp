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

    windowBoxLayout = new QHBoxLayout();
    windowBoxLayout->addStretch();
    windowBoxLayout->addWidget(simWind);
    windowBoxLayout->addStretch();

    buttonsHighLayout = new QHBoxLayout();
    buttonsHighLayout->addStretch();
    buttonsHighLayout->addWidget(forwardMoveButton);
    buttonsHighLayout->addStretch();

    buttonsLowLayout = new QHBoxLayout();
    buttonsLowLayout->addStretch();
    buttonsLowLayout->addWidget(leftMoveButton);
    buttonsLowLayout->addWidget(stopMoveButton);
    buttonsLowLayout->addWidget(rightMoveButton);
    buttonsLowLayout->addStretch();

    simulationsLayot->addLayout(windowBoxLayout);
    simulationsLayot->addLayout(buttonsHighLayout);
    simulationsLayot->addLayout(buttonsLowLayout);
    setLayout(simulationsLayot);
}
void SimulationBody::deleteSimulationsLayout(){
    delete windowBoxLayout;
    delete buttonsHighLayout;
    delete buttonsLowLayout;
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
