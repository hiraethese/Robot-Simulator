#ifndef IOBJECTGUI_H
#define IOBJECTGUI_H

#include <QPainter>
#include <QColor>
class IObjectGUI
{
public:
    IObjectGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount);
    QPainter* simPainter;
    QColor objectColor;
    unsigned objectCount;
    virtual void draw() = 0;
    void setObjectColor(QColor newObjectColor);
    void setObjectCount(unsigned newObjectCount);
};

#endif // IOBJECTGUI_H
