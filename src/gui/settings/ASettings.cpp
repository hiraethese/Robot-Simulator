/**
 * @file ASettings.cpp
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Implementation of abstract class for sim obj settings 
 */
#include "ASettings.h"

ASettings::ASettings(QWidget* parent, QString title): QDialog(parent) {
    setStyleSheet("background-color: lightgray;");
    _settingGridLayot = new QGridLayout(this);
    setLayout(_settingGridLayot);
    setWindowTitle(title);
}

void ASettings::_CreateColorsSettings(int row){

    _colorLable = new QLabel("Color : ");
    _colorComboBox = new QComboBox(this);
    // variants for color
    _colorComboBox->addItem(QString::fromStdString(getColorString(RED)));
    _colorComboBox->addItem(QString::fromStdString(getColorString(BLUE)));
    _colorComboBox->addItem(QString::fromStdString(getColorString(GREEN)));
    _colorComboBox->addItem(QString::fromStdString(getColorString(GRAY)));
    _colorComboBox->addItem(QString::fromStdString(getColorString(BLACK)));
    _colorComboBox->addItem(QString::fromStdString(getColorString(YELLOW)));
    _settingGridLayot->addWidget(_colorLable, row, 0);
    _settingGridLayot->addWidget(_colorComboBox, row, 1);

}

void ASettings::_CreateButtonsSettings(int row){

    _setPushButton = new QPushButton("set", this);

    _deletePushButton = new QPushButton("delete", this);
    _deletePushButton->setEnabled(false);


    _settingGridLayot->addWidget(_setPushButton, row, 0);

    _settingGridLayot->addWidget(_deletePushButton, ++row, 0);
    // connect to sending information about upd sim obj
    connect(_setPushButton, &QPushButton::clicked, this, [=](){close(); emit SetSig(GetSimObjView());});
    // connect to sending information about del sim obj
    connect(_deletePushButton, &QPushButton::clicked, this, [=](){close(); emit DeleteSig(GetSimObjView());});

}

void ASettings::ChangeEnablingOfSettingsObjects(bool flag){
    // change enabling
    _deletePushButton->setEnabled(flag);
}

