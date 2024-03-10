#include "SimulationScene.h"

SimulationScene::SimulationScene(QObject *parent)
    : QGraphicsScene{parent}
{}

void SimulationScene::cleanedSimScene()
{}

void SimulationScene::mousePressEvent(QGraphicsSceneMouseEvent* event){
    QPointF test = event->scenePos();
    std::cout << "click to: " <<  test.x() << " " << test.y() << std::endl;
}
