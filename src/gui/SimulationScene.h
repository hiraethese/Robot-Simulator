#ifndef SIMULATIONSCENE_H
#define SIMULATIONSCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QBrush>
#include <QPen>
#include <QTimer>
#include <vector>

#include "style.h"

class SimulationScene : public QGraphicsScene
{
    Q_OBJECT
    bool flagSettingMode = false;
public:
    explicit SimulationScene(QObject *parent = nullptr);
    void deleteSimulationScene();

    void storeSimGUI();
    void runSimGUI();
    void stopSimGUI();

    void runSettingsMode();
    void stopSettingsMode();
    void cleanSettingsMode();
    bool findSimObjGUI();
private:
    QGraphicsRectItem* pseudoSiObjGUI = nullptr;
    QTimer timerSimGUI;
    std::vector<QGraphicsEllipseItem*>robotsVectorGUI;
    std::vector<QGraphicsRectItem*>wallsVectorGUI;

    void oneSimFrameGUI();

    void createPseudoSimObj(unsigned w, unsigned h);
    void deletePseudoSimObj();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private slots:
    void createNewSimObj();
    void deleteSimObj();
    void updateSimObj();
};

#endif // SIMULATIONSCENE_H
