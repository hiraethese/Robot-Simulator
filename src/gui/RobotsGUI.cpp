#include "RobotsGUI.h"

RobotsGUI::RobotsGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount):AObjectGUI(localPainter, objectColor, objectCount) {
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
    std::cout << "1r" << simPainter << std::endl;
    Rectangle rectFromCore;
    simPainter->setBrush(objectColor);
    std::cout << "2r" << std::endl;
    for(QRectF* robot : robotsGUIVector){
        std::cout << "3r" << std::endl;
        rectFromCore = newRect->GetTransform()->GetRect();
        robot->setX(rectFromCore.x);
        robot->setY(rectFromCore.y);
        robot->setWidth(rectFromCore.w);
        robot->setHeight(rectFromCore.h);
        simPainter->drawRect(*robot);
    }
    std::cout << "4r" << std::endl;
}
