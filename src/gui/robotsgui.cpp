#include "RobotsGUI.h"

RobotsGUI::RobotsGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount):IObjectGUI(localPainter, objectColor, objectCount) {
    Rectangle rectFromCore;
    for(unsigned robot = 0; robot < objectCount; robot++){
        rectFromCore = newRect->GetTransform()->GetRect();
        robotsGUIVector.push_back(new QRectF(rectFromCore.x, rectFromCore.y, rectFromCore.w, rectFromCore.h));
    }
}

RobotsGUI::~RobotsGUI(){
    for(QRectF* robot: robotsGUIVector)
        delete robot;
}
void RobotsGUI::draw(){
    Rectangle rectFromCore;
    simPainter->setBrush(objectColor);
    for(QRectF* robot : robotsGUIVector){
        rectFromCore = newRect->GetTransform()->GetRect();
        robot->setX(rectFromCore.x);
        robot->setY(rectFromCore.y);
        robot->setWidth(rectFromCore.w);
        robot->setHeight(rectFromCore.h);
        simPainter->drawRect(*robot);
    }
}
