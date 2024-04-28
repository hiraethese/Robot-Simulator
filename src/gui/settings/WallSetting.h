#ifndef WALLSETTING_H
#define WALLSETTING_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QString>
#include "../../core/icplib.h"
#include "../style.h"
#include "ASettings.h"


class WallSetting : public ASettings
{

public:

    WallSetting(QWidget* parent, QString title);
    void DownloadDataFromView(SimObjView view, int orderIndex) override;
    SimObjView GetSimObjView();
private:

    QLabel* _heightLabel;
    QSpinBox* _heightSpinBox;

    QLabel* _widthLabel;
    QSpinBox* _widthSpinBox;

};

#endif // WALLSETTING_H
