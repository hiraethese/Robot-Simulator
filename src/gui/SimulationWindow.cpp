#include "SimulationWindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{

    simBody = new SimulationBody();
    createSimulattionsButtons();
    createSimulationsLayout();
}

SimulationWindow::~SimulationWindow(){
    delete simBody;
    deleteSimulationsButtons();
    deleteSimulationsLayout();
}

void SimulationWindow::createSimulationsLayout(){
    simulationsLayot = new QVBoxLayout();

    simBodyowBoxLayout = new QHBoxLayout();
    simBodyowBoxLayout->addStretch();
    simBodyowBoxLayout->addWidget(simBody);
    simBodyowBoxLayout->addStretch();

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

    simulationsLayot->addLayout(simBodyowBoxLayout);
    simulationsLayot->addLayout(simulatyonEngineLayout);
    setLayout(simulationsLayot);
}
void SimulationWindow::deleteSimulationsLayout(){
    delete simBodyowBoxLayout;
    delete highRobotsEngineLayout;
    delete lowRobotsEngineLayout;
    delete robotsEngineLayout;
    delete simulatyonEngineLayout;
    delete simulationsLayot;
}

void SimulationWindow::createSimulattionsButtons(){

    forwardMoveButton = new QPushButton("forward");
    leftMoveButton = new QPushButton("left");
    stopMoveButton = new QPushButton("stop");
    rightMoveButton = new QPushButton("right");

    setUnsetSimButtons(false);

    connect(forwardMoveButton, &QPushButton::clicked, this, [=](){contr_forward_move_sig();});
    connect(leftMoveButton, &QPushButton::clicked, this, [=](){contr_left_rotate_move_sig();});
    connect(stopMoveButton, &QPushButton::clicked, this, [=](){contr_stop_move_sig();});
    connect(rightMoveButton, &QPushButton::clicked, this, [=](){contr_right_rotate_move_sig();});
}

void SimulationWindow::setUnsetSimButtons(bool flagIsSet){
    forwardMoveButton->setEnabled(flagIsSet);
    leftMoveButton->setEnabled(flagIsSet);
    stopMoveButton->setEnabled(flagIsSet);
    rightMoveButton->setEnabled(flagIsSet);
}
void SimulationWindow::deleteSimulationsButtons(){
    delete forwardMoveButton;
    delete leftMoveButton;
    delete stopMoveButton;
    delete rightMoveButton;
}

void SimulationWindow::emitStoreGUISimSigFromSimWind(){
    std::cout << "EMIT STORING FROM SIM WIND!!!" << std::endl;
    simBody->emitStoreGUISimSig();
}
void SimulationWindow::emitRunGUISimSigFromSimWind(){
    std::cout << "EMIT RUNING FROM SIM WIND!!!" << std::endl;
    simBody->emitRunGUISimSig();
    setUnsetSimButtons(true);
}

void SimulationWindow::emitStopGUISimSigFromSimWind(){
    std::cout << "EMIT STOP FROM SIM WIND!!!" << std::endl;
    setUnsetSimButtons(false);
    simBody->emitStopGUISimSig();
}
