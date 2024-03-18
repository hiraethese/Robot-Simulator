#ifndef NEWMAPWINDOW_H
#define NEWMAPWINDOW_H

#include <QObject>
#include <QWidget>


#include <QScrollArea>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <iostream>
#include <string>
class NewMapWindow : public QWidget
{
    Q_OBJECT
public:
    explicit NewMapWindow(QWidget *parent = nullptr);
    ~NewMapWindow();
    std::string GetNewMapPath();

    QPushButton* downloadButton;
private:
    QGridLayout* _newMapGridLayot;

    QLabel* _newMapLabel;
    QLineEdit* _newMapLine;

signals:
};

#endif // NEWMAPWINDOW_H
