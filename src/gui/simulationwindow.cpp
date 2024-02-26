#include "simulationwindow.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1800, 750);
    pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    rect = new QRectF(200.0, 200.0, 100.0, 100.0);
}
SimulationWindow::~SimulationWindow(){
    delete rect;
    delete painter;
}
void SimulationWindow::paintEvent(QPaintEvent *event){
    painter = new QPainter(this);
    painter->drawRect(*rect);
    painter->end();
}

