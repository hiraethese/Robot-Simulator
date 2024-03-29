#include "RobotSetting.h"

RobotSetting::RobotSetting(QWidget* parent, QString title) : ASettings(parent, title){

    _typeRobotLabel = new QLabel("Type : ", this);
    _typeRobotLineEdit = new QLabel(this);
    _settingGridLayot->addWidget(_typeRobotLabel, 0, 0);
    _settingGridLayot->addWidget(_typeRobotLineEdit, 0, 1);

    _diameterLabel = new QLabel("Radius : ", this);
    _diameterSpinBox = new QSpinBox(this);
    _diameterSpinBox->setMinimum(10);
    _diameterSpinBox->setMaximum(200);
    _settingGridLayot->addWidget(_diameterLabel, 1, 0);
    _settingGridLayot->addWidget(_diameterSpinBox, 1, 1);


    _speedLabel = new QLabel("Speed(%) : ", this);
    _speedSpinBox = new QSpinBox(this);
    _speedSpinBox->setMinimum(1);
    _speedSpinBox->setMaximum(100);
    _settingGridLayot->addWidget(_speedLabel, 2, 0);
    _settingGridLayot->addWidget(_speedSpinBox, 2, 1);

    _angleLabel = new QLabel("Angle(degree) : ", this);
    _angleSpinBox = new QSpinBox(this);
    _angleSpinBox->setMinimum(0);
    _angleSpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_angleLabel, 3, 0);
    _settingGridLayot->addWidget(_angleSpinBox, 3, 1);

    _wayLable = new QLabel("Way(degree) : ", this);
    _waySpinBox = new QSpinBox(this);  // combox
    _waySpinBox->setMinimum(0);
    _waySpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_wayLable, 4, 0);
    _settingGridLayot->addWidget(_waySpinBox, 4, 1);

    _CreateColorsSettings(5);
    _CreateButtonsSettings(6);
}


void RobotSetting::DownloadDataFromView(SimObjView view){
    _diameterSpinBox->setValue(int(view.h));
    _speedSpinBox->setValue(int(view.speed));
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(view.color)));
    _angleSpinBox->setValue(view.angle);
    _waySpinBox->setValue(view.way);

    if(view.isControlled){

        _typeRobotLineEdit->setText("controlled");

    }
    else{

        _typeRobotLineEdit->setText("bot");

    }
}




