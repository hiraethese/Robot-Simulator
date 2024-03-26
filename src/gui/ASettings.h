#ifndef ASETTINGS_H
#define ASETTINGS_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include "../core/icplib.h"
class ASettings : public QDialog
{
    Q_OBJECT
public:
    ASettings(QWidget* parent);
    QPushButton* setPushButton;
    QPushButton* deletePushButton;
    virtual void DownloadDataFromView(SimObjView view) = 0;
protected:
    QGridLayout* _settingGridLayot;
};

#endif // ASETTINGS_H
