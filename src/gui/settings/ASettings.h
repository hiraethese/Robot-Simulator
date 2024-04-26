#ifndef ASETTINGS_H
#define ASETTINGS_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

#include "../../core/icplib.h"
#include "../style.h"
class ASettings : public QDialog
{
    Q_OBJECT
public:
    virtual void DownloadDataFromView(SimObjView view, int orderIndex) = 0;
    void SetUnsetDeleteButton(bool flag);
    void SetIndex(int orderIndex);  // after deleted; order index moved to view
    int GetOrderIndex();
    bool GetType();
protected:
    ASettings(QWidget* parent, QString title);
    bool _isRobot;
    int _orderIndex; // after deleted; order index moved to view
    QPushButton* _setPushButton;
    QPushButton* _deletePushButton;

    QGridLayout* _settingGridLayot;

    QLabel* _colorLable;
    QComboBox* _colorComboBox;

    void _CreateColorsSettings(int row);
    void _CreateButtonsSettings(int row);

signals:
    void SetSig(int orderIndex, bool isRobot);
    void DeleteSig(int orderIndex, bool isRobot);

};

#endif // ASETTINGS_H
