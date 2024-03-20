#include "WallSettingsWindow.h"

WallSettingsWindow::WallSettingsWindow() {
    this->setWindowTitle("Wall");
    setWindowFlags(Qt::WindowTitleHint);
    _settingGridLayot = new QGridLayout();


    _heightLabel = new QLabel("Height : ");
    _heightSpinBox = new QSpinBox();
    _heightSpinBox->setMinimum(10);   // value ???
    _heightSpinBox->setMaximum(200);  // value ???
    _settingGridLayot->addWidget(_heightLabel, 0, 0);
    _settingGridLayot->addWidget(_heightSpinBox, 0, 1);

    _widthLabel = new QLabel("Width : ");
    _widthSpinBox = new QSpinBox();
    _widthSpinBox->setMinimum(10);   // value ???
    _widthSpinBox->setMaximum(200);  // value ???
    _settingGridLayot->addWidget(_widthLabel, 1, 0);
    _settingGridLayot->addWidget(_widthSpinBox, 1, 1);


    _colorLable = new QLabel("Color : ");
    _colorComboBox = new QComboBox();
    _colorComboBox->addItem("red");
    _colorComboBox->addItem("blue");
    _colorComboBox->addItem("green");
    _colorComboBox->addItem("gray");
    _colorComboBox->addItem("black");
    _settingGridLayot->addWidget(_colorLable, 2, 0);
    _settingGridLayot->addWidget(_colorComboBox, 2, 1);

    setPushButton = new QPushButton("set");
    _settingGridLayot->addWidget(setPushButton, 3, 0);
    setLayout(_settingGridLayot);
}

WallSettingsWindow::~WallSettingsWindow(){
    delete _heightLabel;
    delete _heightSpinBox;
    delete _widthLabel;
    delete _widthSpinBox;
    delete _colorLable;
    delete _colorComboBox;

    disconnect(setPushButton, 0, 0, 0);
    delete setPushButton;

    delete _settingGridLayot;
}
