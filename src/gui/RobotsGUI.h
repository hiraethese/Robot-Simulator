#ifndef ROBOTSGUI_H
#define ROBOTSGUI_H

#include <vector>
#include <QRectF>
#include <QPainter>
#include <QColor>
#include <iostream>
#include "../core/core.h"
#include "AObjectGUI.h"


class RobotsGUI : public AObjectGUI
{
public:
    RobotsGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount);
    ~RobotsGUI();
    QRectF* getTestRobot();
    void draw() override;
private:
    std::vector<QRectF*> robotsGUIVector;

};

#endif // ROBOTSGUI_H
