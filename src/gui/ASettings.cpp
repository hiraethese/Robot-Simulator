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

    connect(_setPushButton, &QPushButton::clicked, this, [=](){emit setSig();});
}
