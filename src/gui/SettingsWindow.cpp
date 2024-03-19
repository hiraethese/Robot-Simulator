#include "SettingsWindow.h"

SettingsWindow::SettingsWindow() {
    this->setWindowTitle("Robot");
    setWindowFlags(Qt::WindowTitleHint);
    _settingGridLayot = new QGridLayout();

    _newMapLabel = new QLabel("New map path: ");
    _newMapLine = new QLineEdit();
    _newMapLine->setEnabled(false);
    _newMapCheckBox = new QCheckBox();
    connect(_newMapCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::_BlockNewMapLineSlot);
    _settingGridLayot->addWidget(_newMapLabel, 0, 0);
    _settingGridLayot->addWidget(_newMapLine, 0, 1);
    _settingGridLayot->addWidget(_newMapCheckBox, 0, 2);

    _speedLabel = new QLabel("Speed(%) : ");
    _speedSpinBox = new QSpinBox();
    _speedCheckBox = new QCheckBox();
    _speedSpinBox->setMinimum(1);
    _speedSpinBox->setMaximum(100);
    _speedSpinBox->setEnabled(false);
    connect(_speedCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::_BlockSpeedSpinBoxSlot);
    _settingGridLayot->addWidget(_speedLabel, 1, 0);
    _settingGridLayot->addWidget(_speedSpinBox, 1, 1);
    _settingGridLayot->addWidget(_speedCheckBox, 1, 2);

    _angleLabel = new QLabel("Angle(degree) : ");
    _angleSpinBox = new QSpinBox();
    _angleCheckBox = new QCheckBox();
    _angleSpinBox->setMinimum(0);
    _angleSpinBox->setMaximum(360);
    _angleSpinBox->setEnabled(false);
    connect(_angleCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::_BlockAngleSpinBoxSlot);
    _settingGridLayot->addWidget(_angleLabel, 2, 0);
    _settingGridLayot->addWidget(_angleSpinBox, 2, 1);
    _settingGridLayot->addWidget(_angleCheckBox, 2, 2);

    setPushButton = new QPushButton("set");
    _settingGridLayot->addWidget(setPushButton, 3, 0);
    setLayout(_settingGridLayot);
}

SettingsWindow::~SettingsWindow(){
    delete _newMapLabel;
    delete _newMapLine;
    disconnect(_newMapCheckBox, 0, 0, 0);
    delete _newMapCheckBox;

    delete _speedLabel;
    delete _speedSpinBox;
    disconnect(_speedCheckBox, 0, 0, 0);
    delete _speedCheckBox;

    delete _angleLabel;
    delete _angleSpinBox;
    disconnect(_angleCheckBox, 0, 0, 0);
    delete _angleCheckBox;

    disconnect(setPushButton, 0, 0, 0);
    delete setPushButton;

    delete _settingGridLayot;
}


bool SettingsWindow::IsSetMapValue(){
    return _newMapCheckBox->isChecked();
}
QString SettingsWindow::GetMapValue(){
    return _newMapLine->text();
}
void SettingsWindow::SetMapValue(QString map){
    _newMapLine->setText(map);
}


bool SettingsWindow::IsSetSpeedValue(){
    return _speedCheckBox->isChecked();
}
int SettingsWindow::GetSpeedValue(){
    return _speedSpinBox->value();
}
void SettingsWindow::SetSpeedValue(int speed){
    _speedSpinBox->setValue(speed);
}


bool SettingsWindow::IsSetAngleValue(){
    return _angleCheckBox->isChecked();
}
int SettingsWindow::GetAngleValue(){
    return _angleSpinBox->value();
}
void SettingsWindow::SetAngleValue(int angle){
    _angleSpinBox->setValue(angle);
}


void SettingsWindow::_BlockNewMapLineSlot(){
    if(IsSetMapValue()) _newMapLine->setEnabled(true);
    else _newMapLine->setEnabled(false);
}
void SettingsWindow::_BlockSpeedSpinBoxSlot(){
    if(IsSetSpeedValue()) _speedSpinBox->setEnabled(true);
    else _speedSpinBox->setEnabled(false);
}
void SettingsWindow::_BlockAngleSpinBoxSlot(){
    if(IsSetSpeedValue()) _angleSpinBox->setEnabled(true);
    else _angleSpinBox->setEnabled(false);
}

