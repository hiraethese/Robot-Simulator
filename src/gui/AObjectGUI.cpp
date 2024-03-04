#include "AObjectGUI.h"

AObjectGUI::AObjectGUI(QPainter* localPainter, QColor objectColor, unsigned objectCount) {
    simPainter = localPainter;
    std::cout << "yes" << std::endl;
    this->objectColor = objectColor;
    this->objectCount = objectCount;
}

void AObjectGUI::setObjectColor(QColor newObjectColor){
    objectColor = newObjectColor;
}

void AObjectGUI::setObjectCount(unsigned newObjectCount){
    objectColor = newObjectCount;
}
