/**
 * @file ConnectorGUI.h
 * @author Baturov Illia (xbatur00@stud.fit.vutbr.cz)
 * @author Kukhta Myron (xkukht01@stud.fit.vutbr.cz)
 * @brief Header of class which provide signals/slot system to simulations object display
 */
#ifndef CONNECTORGUI_H
#define CONNECTORGUI_H

#include <QObject>

/**
 * @brief Class which provide signal/slot for simulations object display
 * 
 */
class ConnectorGUI : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new Connector G U I object
     */
    explicit ConnectorGUI(): QObject{nullptr}
    {}

signals:
    /**
     * @brief Signal for information about smth action with simualtions objects display
     * 
     * @param orderIndex index of simulations objects display with which exist smth action
     * @param isRobot discriminator (robot/wall)
     */
    void connectSig(int orderIndex, bool isRobot);
};

#endif // CONNECTORGUI_H
