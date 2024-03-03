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
#include "../controller/controller.h"
#include "../controller/PseudoCore.h"


class SimulationBody : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationBody(QWidget *parent = nullptr);
    ~SimulationBody();
    void emitStoreGUISimSig();
    void emitRunGUISimSig();
protected:
    void paintEvent(QPaintEvent *event);
private:
    RobotsGUI* simRobotsGUI = nullptr;
    QPalette pal;
    QPainter* painter = nullptr;
    void drawGUISimObj();
    void connectSignals();
signals:
    void runGUISimSig();
    void storeGUISimSig();
public slots:
    void runGUISim();
    void storeGUISim();
};

#endif // SIMULATIONBODY_H
