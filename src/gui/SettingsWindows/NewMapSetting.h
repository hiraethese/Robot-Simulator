#ifndef NEWMAPSETTING_H
#define NEWMAPSETTING_H

#include <QDialog>
#include <QWidget>
#include <string>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include "../style.h"

class NewMapSetting : public QDialog
{
    Q_OBJECT

public:

    NewMapSetting(QWidget* parent);
    std::string GetNewMapPath();

private:

    QGridLayout* _newMapGridLayot;

    QLabel* _newMapLabel;
    QLineEdit* _newMapLine;

    QPushButton* _downloadButton;

signals:

    void downloadSig();

};

#endif // NEWMAPSETTING_H
