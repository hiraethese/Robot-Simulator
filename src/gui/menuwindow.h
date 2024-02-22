#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();
    QPushButton* startButton;

private:

    void initMenuWindowButtons();
    void deleteMenuWindowButtons();
    QHBoxLayout* menuBoxForButton;
    QPushButton* settingsButton;
    QPushButton* setPlaceButton;
    //QPushButton* helpButton;
signals:
};

#endif // MENUWINDOW_H
