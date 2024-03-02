#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <iostream>
class settingsWindow : public QWidget
{
    Q_OBJECT
public:

    settingsWindow();
    ~settingsWindow();
    QPushButton* setPushButton;


    bool isSetMapValue();
    QString getMapValue();
    void setMapValue(QString map);

    bool isSetSpeedValue();
    int getSpeedValue();
    void setSpeedValue(int speed);

    bool isSetCornerValue();
    int getCornerValue();
    void setCornerValue(int corner);
private:
    QGridLayout* settingGridLayot;

    QLabel* newMapLabel;
    QLineEdit* newMapLine;
    QLabel mapValue;
    QCheckBox* newMapCheckBox;

    QLabel* speedLabel;
    QSpinBox* speedSpinBox;
    QCheckBox* speedCheckBox;
    int speedValue;

    QLabel* cornerLabel;
    QSpinBox* cornerSpinBox;
    QCheckBox* cornerCheckBox;
    int cornerValue;

private slots:
};

#endif // SETTINGSWINDOW_H
