#include "WallSetting.h"

WallSetting::WallSetting(QWidget* parent):ASettings(parent) {

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

    _settingGridLayot->addWidget(setPushButton, 3, 0);

    _settingGridLayot->addWidget(deletePushButton, 4, 0);

}


void WallSetting::DownloadDataFromView(SimObjView view){
    _heightSpinBox->setValue(view.h);
    _widthSpinBox->setValue(view.w);
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(view.color)));
}
