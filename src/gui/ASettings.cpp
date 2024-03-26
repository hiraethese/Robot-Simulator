#include "ASettings.h"

ASettings::ASettings(QWidget* parent): QDialog(parent) {

    _settingGridLayot = new QGridLayout(this);
    setLayout(_settingGridLayot);

    setPushButton = new QPushButton("set", this);

    deletePushButton = new QPushButton("delete", this);
    deletePushButton->setEnabled(false);

}
