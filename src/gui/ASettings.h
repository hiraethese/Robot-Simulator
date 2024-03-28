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

#include "../core/icplib.h"
#include "style.h"
class ASettings : public QDialog
{
    Q_OBJECT
public:
    ASettings(QWidget* parent, QString title);
    virtual void DownloadDataFromView(SimObjView view) = 0;
    void SetUnsetDeleteButton(bool flag);

protected:
    QPushButton* _setPushButton;
    QPushButton* _deletePushButton;

    QGridLayout* _settingGridLayot;

    QLabel* _colorLable;
    QComboBox* _colorComboBox;

    void _CreateColorsSettings(int row);
    void _CreateButtonsSettings(int row);

signals:
    void setSig();
    void deleteSig();
};

#endif // ASETTINGS_H
