#include "WallSettingsWindow.h"

WallSettingsWindow::WallSettingsWindow() {
    this->setWindowTitle("Wall");
    setWindowFlags(Qt::WindowTitleHint);
    _settingGridLayot = new QGridLayout();

    _newMapLabel = new QLabel("New map path: ");
    _newMapLine = new QLineEdit();
    _newMapLine->setEnabled(false);
    _newMapCheckBox = new QCheckBox();
    connect(_newMapCheckBox, &QCheckBox::stateChanged, this, &WallSettingsWindow::_BlockNewMapLineSlot);
    _settingGridLayot->addWidget(_newMapLabel, 0, 0);
    _settingGridLayot->addWidget(_newMapLine, 0, 1);
    _settingGridLayot->addWidget(_newMapCheckBox, 0, 2);

    _speedLabel = new QLabel("Speed(%) : ");
    _speedSpinBox = new QSpinBox();
    _speedCheckBox = new QCheckBox();
    _speedSpinBox->setMinimum(1);
    _speedSpinBox->setMaximum(100);
    _speedSpinBox->setEnabled(false);
    connect(_speedCheckBox, &QCheckBox::stateChanged, this, &WallSettingsWindow::_BlockSpeedSpinBoxSlot);
    _settingGridLayot->addWidget(_speedLabel, 1, 0);
    _settingGridLayot->addWidget(_speedSpinBox, 1, 1);
    _settingGridLayot->addWidget(_speedCheckBox, 1, 2);

    _angleLabel = new QLabel("Angle(degree) : ");
    _angleSpinBox = new QSpinBox();
    _angleCheckBox = new QCheckBox();
    _angleSpinBox->setMinimum(0);
    _angleSpinBox->setMaximum(360);
    _angleSpinBox->setEnabled(false);
    connect(_angleCheckBox, &QCheckBox::stateChanged, this, &WallSettingsWindow::_BlockAngleSpinBoxSlot);
    _settingGridLayot->addWidget(_angleLabel, 2, 0);
    _settingGridLayot->addWidget(_angleSpinBox, 2, 1);
    _settingGridLayot->addWidget(_angleCheckBox, 2, 2);

    setPushButton = new QPushButton("set");
    _settingGridLayot->addWidget(setPushButton, 3, 0);
    setLayout(_settingGridLayot);
}

WallSettingsWindow::~WallSettingsWindow(){
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


bool WallSettingsWindow::IsSetMapValue(){
    return _newMapCheckBox->isChecked();
}
QString WallSettingsWindow::GetMapValue(){
    return _newMapLine->text();
}
void WallSettingsWindow::SetMapValue(QString map){
    _newMapLine->setText(map);
}


bool WallSettingsWindow::IsSetSpeedValue(){
    return _speedCheckBox->isChecked();
}
int WallSettingsWindow::GetSpeedValue(){
    return _speedSpinBox->value();
}
void WallSettingsWindow::SetSpeedValue(int speed){
    _speedSpinBox->setValue(speed);
}


bool WallSettingsWindow::IsSetAngleValue(){
    return _angleCheckBox->isChecked();
}
int WallSettingsWindow::GetAngleValue(){
    return _angleSpinBox->value();
}
void WallSettingsWindow::SetAngleValue(int angle){
    _angleSpinBox->setValue(angle);
}


void WallSettingsWindow::_BlockNewMapLineSlot(){
    if(IsSetMapValue()) _newMapLine->setEnabled(true);
    else _newMapLine->setEnabled(false);
}
void WallSettingsWindow::_BlockSpeedSpinBoxSlot(){
    if(IsSetSpeedValue()) _speedSpinBox->setEnabled(true);
    else _speedSpinBox->setEnabled(false);
}
void WallSettingsWindow::_BlockAngleSpinBoxSlot(){
    if(IsSetSpeedValue()) _angleSpinBox->setEnabled(true);
    else _angleSpinBox->setEnabled(false);
}

