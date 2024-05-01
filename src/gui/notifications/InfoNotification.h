#ifndef INFONOTIFICATION_H
#define INFONOTIFICATION_H

#include <QMessageBox>
#include "../../core/icplib.h"

class InfoNotification
{
protected:
    void _WarningMsg(ICP_CODE code);
};

#endif // INFONOTIFICATION_H
