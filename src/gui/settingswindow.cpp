#include "settingswindow.h"

settingsWindow::settingsWindow() {
    this->setWindowTitle("Settings");
    setWindowFlags(Qt::WindowTitleHint);
    settingGridLayot = new QGridLayout();

    newMapLabel = new QLabel(tr("New map path: "));
    newMapLine = new QLineEdit();
    newMapCheckBox = new QCheckBox();
    settingGridLayot->addWidget(newMapLabel, 0, 0);
    settingGridLayot->addWidget(newMapLine, 0, 1);
    settingGridLayot->addWidget(newMapCheckBox, 0, 2);

    speedLabel = new QLabel(tr("Speed(%) : "));
    speedSpinBox = new QSpinBox();
    speedCheckBox = new QCheckBox();
    speedSpinBox->setMinimum(1);
    speedSpinBox->setMaximum(100);
    settingGridLayot->addWidget(speedLabel, 1, 0);
    settingGridLayot->addWidget(speedSpinBox, 1, 1);
    settingGridLayot->addWidget(speedCheckBox, 1, 2);

    cornerLabel = new QLabel(tr("Corner(degree) : "));
    cornerSpinBox = new QSpinBox();
    cornerCheckBox = new QCheckBox();
    cornerSpinBox->setMinimum(0);
    cornerSpinBox->setMaximum(360);
    settingGridLayot->addWidget(cornerLabel, 2, 0);
    settingGridLayot->addWidget(cornerSpinBox, 2, 1);
    settingGridLayot->addWidget(cornerCheckBox, 2, 2);

    setPushButton = new QPushButton(tr("set"));
    settingGridLayot->addWidget(setPushButton, 3, 0);
    setLayout(settingGridLayot);
}

settingsWindow::~settingsWindow(){
    delete newMapLabel;
    delete newMapLine;
    delete newMapCheckBox;

    delete speedLabel;
    delete speedSpinBox;
    delete speedCheckBox;

    delete cornerLabel;
    delete cornerSpinBox;
    delete cornerCheckBox;

    delete setPushButton;

    delete settingGridLayot;
}


bool settingsWindow::isSetMapValue(){
    return newMapCheckBox->isChecked();
}
QString settingsWindow::getMapValue(){
    return this->newMapLine->text();
}
void settingsWindow::setMapValue(QString map){
    this->newMapLine->setText(map);
}


bool settingsWindow::isSetSpeedValue(){
    return speedCheckBox->isChecked();
}
int settingsWindow::getSpeedValue(){
    return this->speedSpinBox->value();
}
void settingsWindow::setSpeedValue(int speed){
    this->speedSpinBox->setValue(speed);
}


bool settingsWindow::isSetCornerValue(){
    return cornerCheckBox->isChecked();
}
int settingsWindow::getCornerValue(){
    return this->cornerSpinBox->value();
}
void settingsWindow::setCornerValue(int corner){
    this->cornerSpinBox->setValue(corner);
}


