#include "aboutformpov.h"
#include "ui_aboutformpov.h"

AboutFormPOV::AboutFormPOV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AboutFormPOV)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
}

AboutFormPOV::~AboutFormPOV()
{
    delete ui;
}
