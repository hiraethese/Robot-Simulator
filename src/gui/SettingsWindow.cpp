#include "SettingsWindow.h"

SettingsWindow::SettingsWindow(bool isUserRobot) {
    flagIsUserRobot = isUserRobot;
    if(flagIsUserRobot){
        this->setWindowTitle("User Robot");
    }
    else{
        this->setWindowTitle("Bot Robot");
    }
    setWindowFlags(Qt::WindowTitleHint);
    _settingGridLayot = new QGridLayout();

    _diameterLabel = new QLabel("Radius: ");
    _diameterSpinBox = new QSpinBox();
    _diameterSpinBox->setMinimum(10);
    _diameterSpinBox->setMaximum(200);
    _settingGridLayot->addWidget(_diameterLabel, 0, 0);
    _settingGridLayot->addWidget(_diameterSpinBox, 0, 1);


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

    _wayLable = new QLabel("Direction(degree) : ");
    _waySpinBox = new QSpinBox();  // combox
    _waySpinBox->setMinimum(0);
    _waySpinBox->setMaximum(360);
    //_directionSpinBox->setEnabled(false);
    _settingGridLayot->addWidget(_wayLable, 3, 0);
    _settingGridLayot->addWidget(_waySpinBox, 3, 1);

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

    delete _diameterLabel;
    delete _diameterSpinBox;

    delete _speedLabel;
    delete _speedSpinBox;

    delete _angleLabel;
    delete _angleSpinBox;

    delete _wayLable;
    delete _waySpinBox;

    delete _colorLable;
    delete _colorComboBox;

    disconnect(setPushButton, 0, 0, 0);
    delete setPushButton;

    delete _settingGridLayot;

}


