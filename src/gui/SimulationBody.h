#ifndef SIMULATIONBODY_H
#define SIMULATIONBODY_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QRectF>
#include <QPushButton>
#include <QColor>
#include <iostream>
#include <QTimer>
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
    void emitStopGUISimSig();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer* simTimer;
    RobotsGUI* simRobotsGUI = nullptr;
    QPalette pal;
    QPainter* painter = nullptr;
    void drawGUISim();
    void connectSignals();
    void createGUISimObj();
    void deleteGUISimObj();
signals:
    void runGUISimSig();
    void storeGUISimSig();
    void stopGUISimSig();
private slots:
    void runGUISim();
    void storeGUISim();
    void stopGUISim();
};

#endif // SIMULATIONBODY_H
