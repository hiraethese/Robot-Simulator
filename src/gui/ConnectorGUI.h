#ifndef CONECTORGUI_H
#define CONECTORGUI_H

#include <QObject>

class ConnectorGUI : public QObject
{
    Q_OBJECT
public:
    explicit ConnectorGUI(QObject *parent = nullptr);

signals:
    void connectSig(int data);
};

#endif // CONECTORGUI_H
