#include "RobotSetting.h"

RobotSetting::RobotSetting(QWidget* parent, QString title) : ASettings(parent, title){

    _typeRobotLabel = new QLabel("Type : ", this);
    _typeRobotComboBox = new QComboBox(this);
    _typeRobotComboBox->addItem(_autoRobotString);
    _typeRobotComboBox->addItem(_contrRobotString);

    _settingGridLayot->addWidget(_typeRobotLabel, 0, 0);
    _settingGridLayot->addWidget(_typeRobotComboBox, 0, 1);

    _diameterLabel = new QLabel("Radius : ", this);
    _diameterSpinBox = new QSpinBox(this);
    _diameterSpinBox->setMinimum(10);
    _diameterSpinBox->setMaximum(200);
    _settingGridLayot->addWidget(_diameterLabel, 1, 0);
    _settingGridLayot->addWidget(_diameterSpinBox, 1, 1);


    _speedLabel = new QLabel("Speed(%) : ", this);
    _speedSpinBox = new QSpinBox(this);
    _speedSpinBox->setMinimum(1);
    _speedSpinBox->setMaximum(100);
    _settingGridLayot->addWidget(_speedLabel, 2, 0);
    _settingGridLayot->addWidget(_speedSpinBox, 2, 1);

    _angleStepLabel = new QLabel("Angle step (degree) : ", this);
    _angleStepSpinBox = new QSpinBox(this);
    _angleStepSpinBox->setMinimum(0);
    _angleStepSpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_angleStepLabel, 3, 0);
    _settingGridLayot->addWidget(_angleStepSpinBox, 3, 1);

    _angleDegreesLable = new QLabel("Angle direction (degree) : ", this);
    _angleDegreesSpinBox = new QSpinBox(this);  // combox
    _angleDegreesSpinBox->setMinimum(0);
    _angleDegreesSpinBox->setMaximum(360);
    _settingGridLayot->addWidget(_angleDegreesLable, 4, 0);
    _settingGridLayot->addWidget(_angleDegreesSpinBox, 4, 1);

    _collisionDistanceLabel = new QLabel("Collision distance", this);
    _collisionDistanceSpinBox = new QSpinBox(this);
    _collisionDistanceSpinBox->setMinimum(0);
    _collisionDistanceSpinBox->setMaximum(1800);
    _settingGridLayot->addWidget(_collisionDistanceLabel, 5, 0);
    _settingGridLayot->addWidget(_collisionDistanceSpinBox, 5, 1);
    
    _rotateClockwiseLabel = new QLabel("Rotate clock wise", this);
    _rotateClockwiseComboBox = new QComboBox(this);
    _rotateClockwiseComboBox->addItem(_leftClockW);
    _rotateClockwiseComboBox->addItem(_rightClockW);
    _settingGridLayot->addWidget(_rotateClockwiseLabel, 6, 0);
    _settingGridLayot->addWidget(_rotateClockwiseComboBox, 6, 1);

    _CreateColorsSettings(7);
    _CreateButtonsSettings(8);
}


void RobotSetting::DownloadDataFromView(SimObjView view, int orderIndex){
    _orderIndex = orderIndex;
    _isControlled = view.isControlled;
    _isRobot = true;
    _diameterSpinBox->setValue(int(view.h));
    _speedSpinBox->setValue(int(view.speed));
    _colorComboBox->setCurrentText(QString::fromStdString(getColorString(view.color)));
    _angleStepSpinBox->setValue(view.angleStep);
    _angleDegreesSpinBox->setValue(view.angleDegrees);
    _collisionDistanceSpinBox->setValue(int(view.collisionDistance));

    if(view.isControlled){

        _typeRobotComboBox->setCurrentText(_contrRobotString);

    }
    else{

        _typeRobotComboBox->setCurrentText(_autoRobotString);

    }
    if(view.rotateClockwise == 1){
        
        _rotateClockwiseComboBox->setCurrentText(_rightClockW);
    
    }
    else{
    
        _rotateClockwiseComboBox->setCurrentText(_leftClockW);
    
    }
}

SimObjView RobotSetting::GetSimObjView(){
    // TODO: delete this comment
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
    int rotateClockwise;
    colors colorsCode;
    if(_rotateClockwiseLabel->text() == _leftClockW){
        rotateClockwise = -1;
    }
    else{
        rotateClockwise = 1;
    }
    if(!convertColorsStringToCode(_colorComboBox->currentText().toStdString(), &colorsCode)){
        colorsCode = RED;
    }
    return  {
            0.0,
            0.0,
            float(_diameterSpinBox->value()),
            float(_diameterSpinBox->value()),
            float(_speedSpinBox->value()),
            float(_collisionDistanceSpinBox->value()),
            _angleStepSpinBox->value(),
            _angleDegreesSpinBox->value(),
            rotateClockwise,
            colorsCode,
            _orderIndex,
            _isControlled,
            true
    };
}


void RobotSetting::ChangeEnablingOfSettingsObjects(bool flag){
    ASettings::ChangeEnablingOfSettingsObjects(flag);
    _typeRobotComboBox->setEnabled(flag);
}

