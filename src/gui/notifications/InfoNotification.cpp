/**
 * @file InfoNotification.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation class for warning notifications
 */
#include "InfoNotification.h"

void InfoNotification::_WarningMsg(ICP_CODE code){
    switch(code){
    case CODE_INTERNAL_ERROR:
        QMessageBox::warning(nullptr, "Error", "Internal error with ICP2024!");
        break;
    case CODE_ERROR_INPUT_FILE_NOT_EXIST:
        QMessageBox::warning(nullptr, "Warning", "Input file with specification for simulations object not founded.");
        break;
    case CODE_SYNTAXE_ERROR_UNKNOWN_OBJ_TYPE:
        QMessageBox::warning(nullptr, "Error", "Use wrong type of simulation object in input file!");
        break;
    case CODE_SYNTAXE_ERROR_INPUT_FILE_CONTR_ROBOT:
        QMessageBox::warning(nullptr, "Error", "Syntaxe error in specification for controlled robot in input file!");
        break;
    case CODE_SYNTAXE_ERROR_INPUT_FILE_AUTO_ROBOT:
        QMessageBox::warning(nullptr, "Error", "Syntaxe error in specification for automation robot in input file!");
        break;
    case CODE_SYNTAXE_ERROR_INPUT_FILE_WALL:
        QMessageBox::warning(nullptr, "Error", "Syntaxe error in specification for wall in input file!");
        break;
    case CODE_NEW_OBJECT_COLLISION_ERROR:
        QMessageBox::warning(nullptr, "Error", "Collision error with new object!");
        break;
    case CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_CORE:
        QMessageBox::warning(nullptr, "Error", "Problem with synchronization between core and gui, requested object is not founded in core!");
        break;
    case CODE_ERROR_SIM_OBJ_IS_NOT_FOUND_IN_GUI:
        QMessageBox::warning(nullptr, "Error", "Problem with synchronization between core and gui, requested object is not founded in GUI!");
        break;
    default:
        QMessageBox::warning(nullptr, "Error", "Unexpected errors!");
        break;
    }
}
