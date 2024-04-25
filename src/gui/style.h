#ifndef STYLE_H
#define STYLE_H
#include "../core/icplib.h"
#include <QBrush>
#include <QPen>
#include <QColor>
#include <string>
#include <iostream>
#include <QPalette>
/*
extern QBrush redBrush;
extern QBrush yellowBrush;
extern QBrush greanBrush;
extern QBrush blueBrush;
extern QBrush whiteBrush;
extern QBrush grayBrush;
extern QBrush blackBrush;

extern QPen blackPen;
extern QPen whitePen;
*/
QBrush getBrushByCode(colors colorCode);
QPen getPen();
std::string getColorString(colors colorsCode);
bool convertColorsStringToCode(std::string colorsString, colors* colorsCode);
#endif // STYLE_H
