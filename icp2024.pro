# the file is automatically generated by QtCreator
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

OBJECTS_DIR += ../obj
MOC_DIR += ../moc
DESTDIR += ../bin
CONFIG += c++17
RESOURCES += res/icons.qrc
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#gui/

SOURCES += \
    src/core/entities/Robot.cpp \
    src/core/entities/SimObject.cpp \
    src/core/entities/Wall.cpp \
    src/core/properties/Movement.cpp \
    src/core/properties/MyTransform.cpp \
    src/core/Core.cpp \
    src/core/SimFactory.cpp \
    src/core/SimMap.cpp \
    src/gui/AObjectGUI.cpp \
    src/gui/InfoNotification.cpp \
    src/gui/MainWindow.cpp \
    src/gui/SettingsWindow.cpp \
    src/gui/SimulationWindow.cpp \
    src/main.cpp

HEADERS += \
    src/core/entities/Robot.h \
    src/core/entities/SimObject.h \
    src/core/entities/Wall.h \
    src/core/properties/Movement.h \
    src/core/properties/MyTransform.h \
    src/core/Core.h \
    src/core/icplib.h \
    src/core/SimFactory.h \
    src/core/SimMap.h \
    src/gui/AObjectGUI.h \
    src/gui/InfoNotification.h \
    src/gui/MainWindow.h \
    src/gui/SettingsWindow.h \
    src/gui/SimulationWindow.h

FORMS += \
    src/gui/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
