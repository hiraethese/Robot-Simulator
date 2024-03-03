#include "SimulationBody.h"

SimulationBody::SimulationBody(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1800, 750);
    pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}

SimulationBody::~SimulationBody(){
    //if(simRobotsGUI) delete simRobotsGUI;
    //delete painter;
}

void SimulationBody::paintEvent(QPaintEvent *event){
    std::cout << "PAINT EVENT" << std::endl;
    Q_UNUSED(event);
    //if(drawFlag) drawGUISimObj();
}


void SimulationBody::connectSignals(){
    connect(this, SIGNAL(runGUISimSig()), this, SLOT(runGUISim()));
    connect(this, SIGNAL(storGUIeSimSig()), this, SLOT(storeGUISim()));
}
/*
void SimulationBody::drawGUISimObj(){
    std::cout << "DRAW SIM OBJECT" << std::endl;
    painter->begin(this);
    simRobotsGUI->draw();
    painter->end();
}*/

void SimulationBody::emitRunGUISimSig(){
    emit runGUISimSig();
}

void SimulationBody::emitStoreGUISimSig(){
    emit storeGUISimSig();
}

void SimulationBody::runGUISim(){
    while(contr_is_sim_run()){}
}
void SimulationBody::storeGUISim(){}
