/**
 * @file style.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implement of helpful function for frontend styling
 */
#include "style.h"

QBrush getBrushByCode(colors colorCode){
    // declare all base colors for sim obj
    QBrush redBrush(Qt::red);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QBrush whiteBrush(Qt::white);
    QBrush grayBrush(Qt::gray);
    QBrush blackBrush(Qt::black);

    // find correct brush for colors code
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
    // conv code
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

bool convertColorsStringToCode(std::string colorsString, colors* colorsCode) {
    // for low/high litterals
    for (char& colorsChar : colorsString) colorsChar = std::toupper(colorsChar);

    std::cout << "COLOR: " << colorsString << std::endl;
    // convert    
    if (colorsString == "WHITE") *colorsCode = WHITE;
    else if (colorsString == "BLACK") *colorsCode = BLACK;
    else if (colorsString == "BLUE") *colorsCode = BLUE;
    else if (colorsString == "GREEN") *colorsCode = GREEN;
    else if (colorsString == "YELLOW") *colorsCode = YELLOW;
    else if (colorsString == "GRAY") *colorsCode = GRAY;
    else if (colorsString == "RED") *colorsCode = RED;
    else if (colorsString == "BLACK") *colorsCode = BLACK;
    else return false;  // not convert
    
    
    return true;
}

