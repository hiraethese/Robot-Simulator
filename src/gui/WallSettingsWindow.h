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
#include <iostream>
class WallSettingsWindow : public QWidget
{
    Q_OBJECT
public:

    WallSettingsWindow();
    ~WallSettingsWindow();
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

#endif // WALLSETTINGSWINDOW_H
