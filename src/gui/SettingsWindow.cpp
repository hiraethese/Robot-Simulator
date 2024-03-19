#include "SettingsWindow.h"

SettingsWindow::SettingsWindow() {
    this->setWindowTitle("Robot");
    setWindowFlags(Qt::WindowTitleHint);
    _settingGridLayot = new QGridLayout();

    _speedLabel = new QLabel("Speed(%) : ");
    _speedSpinBox = new QSpinBox();
    _speedSpinBox->setMinimum(1);
    _speedSpinBox->setMaximum(100);
    //_speedSpinBox->setEnabled(false);
    _settingGridLayot->addWidget(_speedLabel, 1, 0);
    _settingGridLayot->addWidget(_speedSpinBox, 1, 1);

    _angleLabel = new QLabel("Angle(degree) : ");
    _angleSpinBox = new QSpinBox();
    _angleSpinBox->setMinimum(0);
    _angleSpinBox->setMaximum(360);
    //_angleSpinBox->setEnabled(false);
    _settingGridLayot->addWidget(_angleLabel, 2, 0);
    _settingGridLayot->addWidget(_angleSpinBox, 2, 1);

    _directionLable = new QLabel("Direction(degree) : ");
    _directionSpinBox = new QSpinBox();  // combox
    _directionSpinBox->setMinimum(0);
    _directionSpinBox->setMaximum(360);
    //_directionSpinBox->setEnabled(false);
    _settingGridLayot->addWidget(_directionLable, 3, 0);
    _settingGridLayot->addWidget(_directionSpinBox, 3, 1);

    _colorLable = new QLabel("Color : ");
    _colorComboBox = new QComboBox();
    _colorComboBox->addItem("red");
    _colorComboBox->addItem("blue");
    _colorComboBox->addItem("green");
    _colorComboBox->addItem("gray");
    _colorComboBox->addItem("black");
    _settingGridLayot->addWidget(_colorLable, 4, 0);
    _settingGridLayot->addWidget(_colorComboBox, 4, 1);



    setPushButton = new QPushButton("set");
    _settingGridLayot->addWidget(setPushButton, 5, 0);
    setLayout(_settingGridLayot);
}

SettingsWindow::~SettingsWindow(){

    delete _speedLabel;
    delete _speedSpinBox;

    delete _angleLabel;
    delete _angleSpinBox;

    delete _directionLable;
    delete _directionSpinBox;

    delete _colorLable;
    delete _colorComboBox;

    disconnect(setPushButton, 0, 0, 0);
    delete setPushButton;

    delete _settingGridLayot;

}

int SettingsWindow::GetSpeedValue(){
    return _speedSpinBox->value();
}

void SettingsWindow::SetSpeedValue(int speed){
    _speedSpinBox->setValue(speed);
}


int SettingsWindow::GetAngleValue(){
    return _angleSpinBox->value();
}
void SettingsWindow::SetAngleValue(int angle){
    _angleSpinBox->setValue(angle);
}


void SettingsWindow::_BlockNewMapLineSlot(){
    /*if(true) _newMapLine->setEnabled(true);
    else _newMapLine->setEnabled(false);*/
}
void SettingsWindow::_BlockSpeedSpinBoxSlot(){
    /*if(true) _speedSpinBox->setEnabled(true);
    else _speedSpinBox->setEnabled(false);*/
}
void SettingsWindow::_BlockAngleSpinBoxSlot(){
    /*if(IsSetSpeedValue()) _angleSpinBox->setEnabled(true);
    else _angleSpinBox->setEnabled(false);*/
}

