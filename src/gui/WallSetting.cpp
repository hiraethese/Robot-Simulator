#include "WallSetting.h"

WallSetting::WallSetting(QWidget* parent):QDialog(parent) {

    _settingGridLayot = new QGridLayout(this);


    _heightLabel = new QLabel("Height : ", this);
    _heightSpinBox = new QSpinBox(this);
    _heightSpinBox->setMinimum(10);   // value ???
    _heightSpinBox->setMaximum(200);  // value ???
    _settingGridLayot->addWidget(_heightLabel, 0, 0);
    _settingGridLayot->addWidget(_heightSpinBox, 0, 1);

    _widthLabel = new QLabel("Width : ", this);
    _widthSpinBox = new QSpinBox(this);
    _widthSpinBox->setMinimum(10);   // value ???
    _widthSpinBox->setMaximum(200);  // value ???
    _settingGridLayot->addWidget(_widthLabel, 1, 0);
    _settingGridLayot->addWidget(_widthSpinBox, 1, 1);


    _colorLable = new QLabel("Color : ", this);
    _colorComboBox = new QComboBox(this);
    _colorComboBox->addItem("red");
    _colorComboBox->addItem("blue");
    _colorComboBox->addItem("green");
    _colorComboBox->addItem("gray");
    _colorComboBox->addItem("black");
    _settingGridLayot->addWidget(_colorLable, 2, 0);
    _settingGridLayot->addWidget(_colorComboBox, 2, 1);

    setPushButton = new QPushButton("set", this);
    _settingGridLayot->addWidget(setPushButton, 3, 0);

    deletePushButton = new QPushButton("delete", this);
    deletePushButton->setEnabled(false);
    _settingGridLayot->addWidget(deletePushButton, 4, 0);

}


void WallSetting::DownloadDataFromView(WallView wall){
    _heightSpinBox->setValue(wall.rect.h);
    _widthSpinBox->setValue(wall.rect.w);
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(wall.color)));
}
