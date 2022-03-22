#ifndef CLOSEFILTERPOV_H
#define CLOSEFILTERPOV_H
#include <QObject>


class CloseFilterPOV : public QObject
{
Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // CLOSEFILTERPOV_H
