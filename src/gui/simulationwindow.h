#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include <QPalette>
#include <QPainter>
#include <QRectF>
#include <QPushButton>
#include <QColor>
#include <iostream>

#include "../core/core.h"
#include "robotsgui.h"

class SimulationWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();
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

#endif // SIMULATIONWINDOW_H
