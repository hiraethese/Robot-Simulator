#include "gui/mainwindow.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*a.setApplicationName("ICP2024");  // set name of application
    w.setWindowTitle("ICP2024");    // set name of based window
    //w.show();

    // play with button
    QPushButton button1 ("test");
    QPushButton button2 ("other", &button1);

    button1.show();
    */
    w.show();
    return a.exec();
}
