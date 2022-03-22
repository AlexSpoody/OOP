#include "mainwindowpov.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowPOV w;
    w.show();
    return a.exec();
}
