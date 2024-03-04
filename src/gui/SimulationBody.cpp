#include "SimulationBody.h"

SimulationBody::SimulationBody(QWidget *parent)
    : QWidget{parent}
{
    simTimer = new QTimer(this);
    setFixedSize(1800, 750);
    pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    painter = new QPainter(this);
    SimStart();
    connectSignals();
}

SimulationBody::~SimulationBody(){
    std::cout << "DELETED SIM BODY" << std::endl;
    deleteGUISimObj();
    delete painter;
    delete simTimer;
}

void SimulationBody::paintEvent(QPaintEvent *event){
    std::cout << "PAINT EVENT" << std::endl;
    Q_UNUSED(event);
    //if(drawFlag) drawGUISimObj();
    painter->begin(this);
    std::cout << contr_is_sim_ready() << std::endl;
    std::cout << contr_is_sim_run() << std::endl;
    if(contr_is_sim_ready() || contr_is_sim_run()){
        simRobotsGUI->draw();
    }
    painter->end();
}


void SimulationBody::connectSignals(){
    connect(this, SIGNAL(stopGUISimSig()), this, SLOT(stopGUISim()));
    connect(this, SIGNAL(runGUISimSig()), this, SLOT(runGUISim()));
    connect(this, SIGNAL(storeGUISimSig()), this, SLOT(storeGUISim()));
    connect(simTimer, SIGNAL(timeout()), this, SLOT(repaint()));
}

void SimulationBody::emitRunGUISimSig(){
    std::cout << "emit 1" << std::endl;
    emit runGUISimSig();
    std::cout << "emit 2" << std::endl;
}

void SimulationBody::emitStopGUISimSig(){

    std::cout << "emit 3" << std::endl;
    emit stopGUISimSig();
    std::cout << "emit 4" << std::endl;
}

void SimulationBody::emitStoreGUISimSig(){
    std::cout << "emit 5" << std::endl;
    emit storeGUISimSig();
    std::cout << "emit 6" << std::endl;
}

void SimulationBody::createGUISimObj(){

    std::cout << "test1" << std::endl;
    if(simRobotsGUI == nullptr){    std::cout << "test2" << std::endl;

        simRobotsGUI = new RobotsGUI(painter, QColor(255, 0, 0),1);
    }
    std::cout << "test3" << std::endl;

}
void SimulationBody::deleteGUISimObj(){
    if(simRobotsGUI != nullptr){
        std::cout << "test2" << std::endl;
        delete simRobotsGUI;
        simRobotsGUI = nullptr;
    }

}
void SimulationBody::runGUISim(){
    std::cout << "start cycle of running" << std::endl;
    simTimer->start(16);
}

void SimulationBody::stopGUISim(){
    std::cout << "stop cycle of running" << std::endl;
    simTimer->stop();
}

void SimulationBody::storeGUISim(){
    std::cout << "storing gui" << std::endl;
    emit stopGUISimSig();
    deleteGUISimObj();
    createGUISimObj();
    repaint();
}
