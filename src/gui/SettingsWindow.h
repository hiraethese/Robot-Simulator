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
class SettingsWindow : public QWidget
{
    Q_OBJECT
public:

    SettingsWindow();
    ~SettingsWindow();
    QPushButton* setPushButton;


    bool IsSetMapValue();
    QString GetMapValue();
    void SetMapValue(QString map);

    bool IsSetSpeedValue();
    int GetSpeedValue();
    void SetSpeedValue(int speed);

    bool IsSetAngleValue();
    int GetAngleValue();
    void SetAngleValue(int angle);
private:
    QGridLayout* _settingGridLayot;

    QLabel* _newMapLabel;
    QLineEdit* _newMapLine;
    QCheckBox* _newMapCheckBox;

    QLabel* _speedLabel;
    QSpinBox* _speedSpinBox;
    QCheckBox* _speedCheckBox;

    QLabel* _angleLabel;
    QSpinBox* _angleSpinBox;
    QCheckBox* _angleCheckBox;

private slots:
    void _BlockNewMapLineSlot();
    void _BlockSpeedSpinBoxSlot();
    void _BlockAngleSpinBoxSlot();
};

#endif // SETTINGSWINDOW_H
