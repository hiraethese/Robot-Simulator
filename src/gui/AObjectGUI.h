#ifndef AOBJECTGUI_H
#define AOBJECTGUI_H

#include <QPainter>
#include <QColor>
#include <iostream>
class AObjectGUI
{
public:
    AObjectGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount);
    virtual ~AObjectGUI(){}
    QPainter* simPainter;
    QColor objectColor;
    unsigned objectCount;
    virtual void draw() = 0;
    void setObjectColor(QColor newObjectColor);
    void setObjectCount(unsigned newObjectCount);
};

#endif // AOBJECTGUI_H
