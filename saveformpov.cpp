#include "saveformpov.h"
#include "ui_saveformpov.h"
#include "mainwindowpov.h"

SaveFormPOV::SaveFormPOV(MainWindowPOV* win, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveFormPOV)
{
    ui->setupUi(this);
    this->m_win = win;
    this->setFixedSize(this->width(), this->height());
    setWindowTitle("Зберегти зміни?");
    setWindowIcon(QIcon(":/images/unsaved.png"));
}

SaveFormPOV::~SaveFormPOV()
{
    delete ui;
}

void SaveFormPOV::on_SaveButtonPOV_clicked()
{
    m_win->on_actionSave_triggered();
    this->close();
}


void SaveFormPOV::on_NoSaveButtonPOV_clicked()
{
    QApplication::quit();
}


void SaveFormPOV::on_CancelButtonPOV_clicked()
{
    this->close();
}

