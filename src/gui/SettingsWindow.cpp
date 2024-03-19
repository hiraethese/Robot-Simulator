#include "SettingsWindow.h"

SettingsWindow::SettingsWindow() {
    this->setWindowTitle("Settings");
    setWindowFlags(Qt::WindowTitleHint);
    settingGridLayot = new QGridLayout();

    newMapLabel = new QLabel(tr("New map path: "));
    newMapLine = new QLineEdit();
    newMapLine->setEnabled(false);
    newMapCheckBox = new QCheckBox();
    connect(newMapCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::blockNewMapLineSlot);
    settingGridLayot->addWidget(newMapLabel, 0, 0);
    settingGridLayot->addWidget(newMapLine, 0, 1);
    settingGridLayot->addWidget(newMapCheckBox, 0, 2);

    speedLabel = new QLabel(tr("Speed(%) : "));
    speedSpinBox = new QSpinBox();
    speedCheckBox = new QCheckBox();
    speedSpinBox->setMinimum(1);
    speedSpinBox->setMaximum(100);
    speedSpinBox->setEnabled(false);
    connect(speedCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::blockSpeedSpinBoxSlot);
    settingGridLayot->addWidget(speedLabel, 1, 0);
    settingGridLayot->addWidget(speedSpinBox, 1, 1);
    settingGridLayot->addWidget(speedCheckBox, 1, 2);

    angleLabel = new QLabel(tr("Angle(degree) : "));
    angleSpinBox = new QSpinBox();
    angleCheckBox = new QCheckBox();
    angleSpinBox->setMinimum(0);
    angleSpinBox->setMaximum(360);
    angleSpinBox->setEnabled(false);
    connect(angleCheckBox, &QCheckBox::stateChanged, this, &SettingsWindow::blockAngleSpinBoxSlot);
    settingGridLayot->addWidget(angleLabel, 2, 0);
    settingGridLayot->addWidget(angleSpinBox, 2, 1);
    settingGridLayot->addWidget(angleCheckBox, 2, 2);

    setPushButton = new QPushButton(tr("set"));
    settingGridLayot->addWidget(setPushButton, 3, 0);
    setLayout(settingGridLayot);
}

SettingsWindow::~SettingsWindow(){
    std::cout << "YES I AM DELETED" << std::endl;
    delete newMapLabel;
    delete newMapLine;
    disconnect(newMapCheckBox, 0, 0, 0);
    delete newMapCheckBox;

    delete speedLabel;
    delete speedSpinBox;
    disconnect(speedCheckBox, 0, 0, 0);
    delete speedCheckBox;

    delete angleLabel;
    delete angleSpinBox;
    disconnect(angleCheckBox, 0, 0, 0);
    delete angleCheckBox;

    disconnect(setPushButton, 0, 0, 0);
    delete setPushButton;

    delete settingGridLayot;
}


bool SettingsWindow::isSetMapValue(){
    return newMapCheckBox->isChecked();
}
QString SettingsWindow::getMapValue(){
    return this->newMapLine->text();
}
void SettingsWindow::setMapValue(QString map){
    this->newMapLine->setText(map);
}


bool SettingsWindow::isSetSpeedValue(){
    return speedCheckBox->isChecked();
}
int SettingsWindow::getSpeedValue(){
    return this->speedSpinBox->value();
}
void SettingsWindow::setSpeedValue(int speed){
    this->speedSpinBox->setValue(speed);
}


bool SettingsWindow::isSetAngleValue(){
    return angleCheckBox->isChecked();
}
int SettingsWindow::getAngleValue(){
    return this->angleSpinBox->value();
}
void SettingsWindow::setAngleValue(int angle){
    this->angleSpinBox->setValue(angle);
}


void SettingsWindow::blockNewMapLineSlot(){
    if(isSetMapValue()) newMapLine->setEnabled(true);
    else newMapLine->setEnabled(false);
}
void SettingsWindow::blockSpeedSpinBoxSlot(){
    if(isSetSpeedValue()) speedSpinBox->setEnabled(true);
    else speedSpinBox->setEnabled(false);
}
void SettingsWindow::blockAngleSpinBoxSlot(){
    if(isSetSpeedValue()) angleSpinBox->setEnabled(true);
    else angleSpinBox->setEnabled(false);
}

