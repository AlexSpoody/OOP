#include "closefilterpov.h"
#include <QEvent>
#include "mainwindowpov.h"
#include "saveformpov.h"
bool isWarned = false;
bool CloseFilterPOV::eventFilter(QObject *obj, QEvent *event) {
    MainWindowPOV* sender = (MainWindowPOV*) obj;
    if(event->type() == QEvent::Close && sender->windowTitle().contains('*') && !isWarned){
        isWarned = true;
        SaveFormPOV* formochkaSave = new SaveFormPOV(sender);
        formochkaSave->show();
        event->ignore();
        return true;
    }
    return false;
}

