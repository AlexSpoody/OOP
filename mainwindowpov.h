#ifndef MAINWINDOWPOV_H
#define MAINWINDOWPOV_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "saveformpov.h"
#include "aboutformpov.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowPOV; }
QT_END_NAMESPACE

class MainWindowPOV : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowPOV(QWidget *parent = nullptr);

    ~MainWindowPOV();
    friend class SaveFormPOV;

public slots:
    void on_actionSave_triggered();

private slots:
    void ShowContextMenu(const QPoint &);

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_Alt_F4_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_FieldPOV_textChanged();

    void on_actionAbout_triggered();

private:
    Ui::MainWindowPOV *ui;
    AboutFormPOV formochkaAbout;
    QString CurrentFile = "";
};
#endif // MAINWINDOWPOV_H
