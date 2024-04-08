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

    _angleStepLabel = new QLabel("Angle step (degree) : ", this);
    _angleStepSpinBox = new QSpinBox(this);
    _angleStepSpinBox->setMinimum(0);
    _angleStepSpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_angleStepLabel, 3, 0);
    _settingGridLayot->addWidget(_angleStepSpinBox, 3, 1);

    _angleDirectionLable = new QLabel("Angle direction (degree) : ", this);
    _angleDirectionSpinBox = new QSpinBox(this);  // combox
    _angleDirectionSpinBox->setMinimum(0);
    _angleDirectionSpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_angleDirectionLable, 4, 0);
    _settingGridLayot->addWidget(_angleDirectionSpinBox, 4, 1);

    _CreateColorsSettings(5);
    _CreateButtonsSettings(6);
}


void RobotSetting::DownloadDataFromView(SimObjView view){
    _diameterSpinBox->setValue(int(view.h));
    _speedSpinBox->setValue(int(view.speed));
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(view.color)));
    _angleStepSpinBox->setValue(view.angle);
    _angleDirectionSpinBox->setValue(view.way);

    if(view.isControlled){

        _typeRobotLineEdit->setText("controlled");

    }
    else{

        _typeRobotLineEdit->setText("bot");

    }
}


