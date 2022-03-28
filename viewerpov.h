#ifndef VIEWERPOV_H
#define VIEWERPOV_H

#include <QMainWindow>
#include <QMessageBox>
#include "formaboutpov.h"

struct Image{
    QImage image;
    bool hasImage = false;
    Image* prev;
    Image* next;
};

QT_BEGIN_NAMESPACE
namespace Ui { class ViewerPOV; }
QT_END_NAMESPACE

class ViewerPOV : public QMainWindow
{
    Q_OBJECT

public:
    ViewerPOV(QWidget *parent = nullptr);
    bool addImage(Image **pTail, QString filePath);
    void freeList(Image **pHead);
    ~ViewerPOV();

private slots:
    void on_actionOpen_triggered();

    void on_ButtonPrev_clicked();

    void on_ButtonNext_clicked();

    void on_action_Exit_triggered();

    void on_actionSave_as_triggered();

    void on_actionAbout_triggered();

private:
    Ui::ViewerPOV *ui;
    
    Image* head = new Image();
    Image* tail = new Image();
    Image* current;
    FormAboutPOV forma;
    QString filename = "";
};
#endif // VIEWERPOV_H
