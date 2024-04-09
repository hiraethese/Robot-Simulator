#ifndef CONNECTORGUI_H
#define CONNECTORGUI_H

#include <QObject>

class ConnectorGUI : public QObject
{
    Q_OBJECT
public:
    explicit ConnectorGUI(): QObject{nullptr}
    {}

signals:
    void connectSig(int orderIndex, bool isRobot);
};

#endif // CONNECTORGUI_H
