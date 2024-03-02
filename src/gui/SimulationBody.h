#ifndef SIMULATIONBODY_H
#define SIMULATIONBODY_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QRectF>
#include <QPushButton>
#include <QColor>
#include <iostream>

#include "../core/core.h"
#include "RobotsGUI.h"

class SimulationBody : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationBody(QWidget *parent = nullptr);
    ~SimulationBody();
    void simStore();
protected:
    void paintEvent(QPaintEvent *event);
private:
    bool drawFlag = false;
    RobotsGUI* simRobotsGUI = nullptr;
    QPalette pal;
    QPainter* painter;
    void drawSimObjects();
signals:
public slots:
    //void moveSimRectDown();
};

#endif // SIMULATIONBODY_H
