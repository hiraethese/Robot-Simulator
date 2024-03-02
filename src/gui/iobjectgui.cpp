#include "iobjectgui.h"

IObjectGUI::IObjectGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount) {
    simPainter = localPainter;
    this->objectColor = objectColor;
    this->objectCount = objectCount;
}

void IObjectGUI::setObjectColor(QColor newObjectColor){
    objectColor = newObjectColor;
}

void IObjectGUI::setObjectCount(unsigned newObjectCount){
    objectColor = newObjectCount;
}
