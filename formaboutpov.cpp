#include "formaboutpov.h"
#include "ui_formaboutpov.h"

FormAboutPOV::FormAboutPOV(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormAboutPOV)
{
    ui->setupUi(this);
}

FormAboutPOV::~FormAboutPOV()
{
    delete ui;
}

void FormAboutPOV::on_pushButton_clicked()
{
    this->close();
}

