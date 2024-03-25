#ifndef WALLSETTING_H
#define WALLSETTING_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

class WallSetting : public QDialog
{
    Q_OBJECT

public:

    WallSetting(QWidget* parent);
    QPushButton* setPushButton;
    QPushButton* deletePushButton;

private:

    QGridLayout* _settingGridLayot;


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
