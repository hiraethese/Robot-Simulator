#include "simulationwindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1800, 750);
    pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}

SimulationWindow::~SimulationWindow(){
    if(simRobotsGUI) delete simRobotsGUI;
    delete painter;
}

void SimulationWindow::paintEvent(QPaintEvent *event){
    std::cout << "TESTEDT3STEST" << std::endl;
    Q_UNUSED(event);
    if(drawFlag) drawSimObjects();
}


void SimulationWindow::simStore(){
    painter = new QPainter(this);
    SimStart();
    if(!simRobotsGUI)simRobotsGUI = new RobotsGUI(painter, QColor(255, 0, 0), 1);
    else{} // update data
}
void SimulationWindow::drawSimObjects(){
    painter->begin(this);
    simRobotsGUI->draw();
    painter->end();
}
/*
void SimulationWindow::moveSimRectDown(){
    repaint();
}*/
