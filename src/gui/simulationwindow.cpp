#include "simulationwindow.h"

#include "../core/core.h"

SimulationWindow::SimulationWindow(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(1800, 750);
    pal = QPalette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    SimStart();
    Rectangle r = controlledRobot->GetTransform()->GetRect();
    rect = new QRectF(r.x, r.y, r.w, r.h);
}
SimulationWindow::~SimulationWindow(){
    delete rect;
    delete painter;
}
void SimulationWindow::paintEvent(QPaintEvent *event){
    (void)event; // Avoid unused parameter warning
    painter = new QPainter(this);
    painter->setBrush(QColor(255, 0, 0)); // Red color (RGB)
    painter->drawRect(*rect);
    painter->end();
}
