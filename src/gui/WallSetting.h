#ifndef WALLSETTING_H
#define WALLSETTING_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QString>
#include "../core/icplib.h"
#include "style.h"
#include "ASettings.h"


class WallSetting : public ASettings
{
public:

    WallSetting(QWidget* parent);
    void DownloadDataFromView(SimObjView view) override;
private:

    QLabel* _heightLabel;
    QSpinBox* _heightSpinBox;

    QLabel* _widthLabel;
    QSpinBox* _widthSpinBox;


    QLabel* _diameterLabel;
    QSpinBox* _diameterSpinBox;


    QLabel* _colorLable;
    QComboBox* _colorComboBox;


};

#endif // WALLSETTING_H
