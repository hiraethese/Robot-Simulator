/**
 * @file InfoNotification.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class for warning notifications
 */
#ifndef INFONOTIFICATION_H
#define INFONOTIFICATION_H

#include <QMessageBox>
#include "../../core/icplib.h"

/**
 * @brief Class for windows about waring notifications
 * 
 */
class InfoNotification
{
protected:
    /**
     * @brief Calling differents warning by errors code
     * 
     * @param code errors type
     */
    void _WarningMsg(ICP_CODE code);
};

#endif // INFONOTIFICATION_H
