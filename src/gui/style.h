/**
 * @file style.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of helpful function for frontend styling
 */
#ifndef STYLE_H
#define STYLE_H
#include "../core/icplib.h"
#include <QBrush>
#include <QPen>
#include <QColor>
#include <string>
#include <iostream>
#include <QPalette>

/**
 * @brief Get Qt brash for sim object GUI by code of color
 * 
 * @param colorCode code of color
 * @return QBrush 
 */
QBrush getBrushByCode(colors colorCode);

/**
 * @brief Get the Pen object for simulation object GUI
 * 
 * @return QPen 
 */
QPen getPen();

/**
 * @brief Convert colors code to string with humans name of color
 * 
 * @param colorsCode code of color
 * @return std::string with human name of color
 */
std::string getColorString(colors colorsCode);

/**
 * @brief Convert string with humans name of color to colors code
 * 
 * @param colorsString  string with humans name of code
 * @param colorsCode ptr to colors code for storing output of convertation 
 * @return true 
 * @return false 
 */
bool convertColorsStringToCode(std::string colorsString, colors* colorsCode);
#endif // STYLE_H
