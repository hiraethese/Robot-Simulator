#include "RobotSetting.h"

RobotSetting::RobotSetting(QWidget* parent, bool isControlRobot) : QDialog(parent){

    this->setWindowTitle("Template");

    _settingGridLayot = new QGridLayout(this);


    _typeRobotLabel = new QLabel("Type : ", this);
    _typeRobotLineEdit = new QLineEdit(this);
    _typeRobotLineEdit->setEnabled(false);
    _settingGridLayot->addWidget(_typeRobotLabel, 0, 0);
    _settingGridLayot->addWidget(_typeRobotLineEdit, 0, 1);

    if(isControlRobot){

        _typeRobotLineEdit->setText("Controll");

    }else{

        _typeRobotLineEdit->setText("Bot");

    }


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

    _wayLable = new QLabel("Direction(degree) : ", this);
    _waySpinBox = new QSpinBox(this);  // combox
    _waySpinBox->setMinimum(0);
    _waySpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_wayLable, 4, 0);
    _settingGridLayot->addWidget(_waySpinBox, 4, 1);

    _colorLable = new QLabel("Color : ");
    _colorComboBox = new QComboBox(this);
    _colorComboBox->addItem("red");
    _colorComboBox->addItem("blue");
    _colorComboBox->addItem("green");
    _colorComboBox->addItem("gray");
    _colorComboBox->addItem("black");
    _colorComboBox->addItem("yellow");
    _colorComboBox->addItem("gray");
    _settingGridLayot->addWidget(_colorLable, 5, 0);
    _settingGridLayot->addWidget(_colorComboBox, 5, 1);



    setPushButton = new QPushButton("set", this);
    _settingGridLayot->addWidget(setPushButton, 6, 0);
    setLayout(_settingGridLayot);


    deletePushButton = new QPushButton("delete", this);
    deletePushButton->setEnabled(false);
    _settingGridLayot->addWidget(deletePushButton, 7, 0);
}


void RobotSetting::DownloadDataFromView(RobotView robot){
    _diameterSpinBox->setValue(int(robot.rect.h)*2);
    _speedSpinBox->setValue(int(robot.speed));
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(robot.color)));
    _angleSpinBox->setValue(robot.angle);
    _waySpinBox->setValue(robot.way);

    if(robot.isControlled){

        _typeRobotLineEdit->setText("controlled");

    }
    else{

        _typeRobotLineEdit->setText("bot");

    }
}




