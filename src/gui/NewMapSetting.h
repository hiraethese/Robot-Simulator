#ifndef NEWMAPSETTING_H
#define NEWMAPSETTING_H

#include <QDialog>
#include <QWidget>
#include <string>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>

class NewMapSetting : public QDialog
{
    Q_OBJECT
public:
    NewMapSetting(QWidget* parent);
    std::string GetNewMapPath();

    QPushButton* downloadButton;
private:
    QGridLayout* _newMapGridLayot;

    QLabel* _newMapLabel;
    QLineEdit* _newMapLine;

};

#endif // NEWMAPSETTING_H
