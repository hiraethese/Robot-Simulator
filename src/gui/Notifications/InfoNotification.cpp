#include "InfoNotification.h"

void InfoNotification::_WarningMsgSimNotSet(){
    QMessageBox::warning(nullptr, "Warning", "ICP2024 can not engine with simulation, because user not set map.\nPlease, go to the \"Settings\".");
}
