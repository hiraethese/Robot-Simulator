#include "WallSetting.h"

WallSetting::WallSetting(QWidget* parent, QString title):ASettings(parent, title) {

    _isRobot = false;  // after deleted

    _heightLabel = new QLabel("Height : ", this);
    _heightSpinBox = new QSpinBox(this);
    _heightSpinBox->setMinimum(10);   // TODO: value ???
    _heightSpinBox->setMaximum(200);  // TODO: value ???
    _settingGridLayot->addWidget(_heightLabel, 0, 0);
    _settingGridLayot->addWidget(_heightSpinBox, 0, 1);

    _widthLabel = new QLabel("Width : ", this);
    _widthSpinBox = new QSpinBox(this);
    _widthSpinBox->setMinimum(10);   // TODO: value ???
    _widthSpinBox->setMaximum(200);  // TODO: value ???
    _settingGridLayot->addWidget(_widthLabel, 1, 0);
    _settingGridLayot->addWidget(_widthSpinBox, 1, 1);

    _CreateColorsSettings(2);

    _CreateButtonsSettings(3);

}


void WallSetting::DownloadDataFromView(SimObjView view, int orderIndex){
    _orderIndex = orderIndex;
    _heightSpinBox->setValue(view.h);
    _widthSpinBox->setValue(view.w);
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(view.color)));
}

SimObjView WallSetting::GetSimObjView(){
    /*float x;
    float y;
    float w;
    float h;
    float speed;
    float collisionDistance;
    int angleStep;
    int angleDegrees;
    int rotateClockwise;
    colors color;
    int orderIndex;
    bool isControlled;
    bool isRobot;*/
    colors colorsCode;
    if(!convertColorsStringToCode(_colorComboBox->currentText().toStdString(), &colorsCode)){
        colorsCode = BLACK;
    }
    return  {
        0.0,
        0.0,
        float(_widthSpinBox->value()),
        float(_heightSpinBox->value()),
        0.0,
        0.0,
        0,
        0,
        0,
        colorsCode,
        _orderIndex,
        false,
        false
    };
}
