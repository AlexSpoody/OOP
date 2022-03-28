#include "viewerpov.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ViewerPOV w;
    w.show();
    return a.exec();
}
