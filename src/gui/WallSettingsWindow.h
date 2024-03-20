#ifndef WALLSETTINGSWINDOW_H
#define WALLSETTINGSWINDOW_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include <iostream>
class WallSettingsWindow : public QWidget
{
    Q_OBJECT
public:

    WallSettingsWindow();
    ~WallSettingsWindow();
    QPushButton* setPushButton;
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

private slots:
};

#endif // WALLSETTINGSWINDOW_H
