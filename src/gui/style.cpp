#include "style.h"

QBrush getBrushByCode(colors colorCode){
    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush whiteBrush(Qt::white);
    QBrush grayBrush(Qt::gray);
    QBrush blackBrush(Qt::black);

    switch (colorCode) {
    case WHITE:
        return whiteBrush;
    case BLACK:
        return blackBrush;
    case BLUE:
        return blueBrush;
    case GREEN:
        return greenBrush;
    case YELLOW:
        return yellowBrush;
    case GRAY:
        return grayBrush;
    case RED:
        return redBrush;
    default:
        return blackBrush;
    }
}

QPen getPen(){
    QPen blackPen(Qt::black);
    //QPen whitePen(Qt::white);

    return blackPen;
}


std::string getColorString(colors colorsCode){
    switch (colorsCode) {
    case WHITE:
        return "white";
    case BLACK:
        return "black";
    case BLUE:
        return "blue";
    case GREEN:
        return "green";
    case YELLOW:
        return "yellow";
    case GRAY:
        return "gray";
    case RED:
        return "red";
    default:
        return "black";
    }

}

QPalette getTextPalette(){
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::blue);
    return palette;
}
