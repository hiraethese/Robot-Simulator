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
    QRectF rect = newRect->GetTransform()->GuiGetQRectF();
}
SimulationWindow::~SimulationWindow(){
    delete rect;
    delete painter;
}
void SimulationWindow::paintEvent(QPaintEvent *event){
    painter = new QPainter(this);
    painter->setBrush(QColor(255, 0, 0)); // Красный цвет (RGB)
    painter->drawRect(*rect);
    painter->end();
}
