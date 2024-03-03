#include "SettingsWindow.h"

SettingsWindow::SettingsWindow() {
    this->setWindowTitle("Settings");
    setWindowFlags(Qt::WindowTitleHint);
    settingGridLayot = new QGridLayout();

    newMapLabel = new QLabel(tr("New map path: "));
    newMapLine = new QLineEdit();
    newMapLine->setEnabled(false);
    newMapCheckBox = new QCheckBox();
    connect(newMapCheckBox, SIGNAL(stateChanged(int)), this, SLOT(blockNewMapLineSlot()));
    settingGridLayot->addWidget(newMapLabel, 0, 0);
    settingGridLayot->addWidget(newMapLine, 0, 1);
    settingGridLayot->addWidget(newMapCheckBox, 0, 2);

    speedLabel = new QLabel(tr("Speed(%) : "));
    speedSpinBox = new QSpinBox();
    speedCheckBox = new QCheckBox();
    speedSpinBox->setMinimum(1);
    speedSpinBox->setMaximum(100);
    speedSpinBox->setEnabled(false);
    connect(speedCheckBox, SIGNAL(stateChanged(int)), this, SLOT(blockSpeedSpinBoxSlot()));
    settingGridLayot->addWidget(speedLabel, 1, 0);
    settingGridLayot->addWidget(speedSpinBox, 1, 1);
    settingGridLayot->addWidget(speedCheckBox, 1, 2);

    cornerLabel = new QLabel(tr("Corner(degree) : "));
    cornerSpinBox = new QSpinBox();
    cornerCheckBox = new QCheckBox();
    cornerSpinBox->setMinimum(0);
    cornerSpinBox->setMaximum(360);
    cornerSpinBox->setEnabled(false);
    connect(cornerCheckBox, SIGNAL(stateChanged(int)), this, SLOT(blockCornerSpinBoxSlot()));
    settingGridLayot->addWidget(cornerLabel, 2, 0);
    settingGridLayot->addWidget(cornerSpinBox, 2, 1);
    settingGridLayot->addWidget(cornerCheckBox, 2, 2);

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

    delete cornerLabel;
    delete cornerSpinBox;
    disconnect(cornerCheckBox, 0, 0, 0);
    delete cornerCheckBox;

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


bool SettingsWindow::isSetCornerValue(){
    return cornerCheckBox->isChecked();
}
int SettingsWindow::getCornerValue(){
    return this->cornerSpinBox->value();
}
void SettingsWindow::setCornerValue(int corner){
    this->cornerSpinBox->setValue(corner);
}


void SettingsWindow::blockNewMapLineSlot(){
    if(isSetMapValue()) newMapLine->setEnabled(true);
    else newMapLine->setEnabled(false);
}
void SettingsWindow::blockSpeedSpinBoxSlot(){
    if(isSetSpeedValue()) speedSpinBox->setEnabled(true);
    else speedSpinBox->setEnabled(false);
}
void SettingsWindow::blockCornerSpinBoxSlot(){
    if(isSetSpeedValue()) cornerSpinBox->setEnabled(true);
    else cornerSpinBox->setEnabled(false);
}

