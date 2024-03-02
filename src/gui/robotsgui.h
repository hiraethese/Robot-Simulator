#ifndef ROBOTSGUI_H
#define ROBOTSGUI_H

#include <vector>
#include <QRectF>
#include <QPainter>
#include <QColor>

#include "../core/core.h"
#include "IObjectGUI.h"


class RobotsGUI : public IObjectGUI
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
