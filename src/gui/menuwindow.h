#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPushButton>

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

signals:
};

#endif // MENUWINDOW_H
