#include "viewerpov.h"
#include "ui_viewerpov.h"
#include <QFileDialog>

ViewerPOV::ViewerPOV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewerPOV)
{
    ui->setupUi(this);
    ui->ButtonNext->hide();
    ui->ButtonPrev->hide();
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
    //setLayout(ui->horizontalLayout);
    setWindowIcon(QIcon(":/images/graphic_redactor_icon.png"));
    ui->ButtonNext->show();
    ui->ButtonPrev->show();
    ui->ButtonNext->setIcon(QIcon(":/images/button_left_inactive.png"));
    ui->ButtonPrev->setIcon(QIcon(":/images/button_right_inactive.png"));
}


bool ViewerPOV::addImage(Image **pTail, QString filePath)
{
    Image* NewNode = new Image();
    if(!NewNode->image.load(filePath)) return false;
    NewNode->hasImage = true;
    NewNode->prev = *pTail;
    NewNode->next = nullptr;
    (*pTail)->next = NewNode;
    *pTail = NewNode;
    return true;
}

void ViewerPOV::freeList(Image **pHead)
{
    Image* curr = nullptr;
    while(*pHead){
        curr = *pHead;
        (*pHead) = (*pHead)->next;
        delete curr;
    }
}


ViewerPOV::~ViewerPOV()
{
    freeList(&head);
    delete ui;
}


void ViewerPOV::on_actionOpen_triggered()
{
    filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.tif)"));
    if(!addImage(&tail, filename)){ ui->kartinka->setText("Error: something went wrong. Try again."); return; }
    current = tail;
    ui->kartinka->setPixmap(QPixmap::fromImage(current->image.scaled(ui->kartinka->width(), ui->kartinka->height())));
    if(current->prev->hasImage){
        ui->ButtonPrev->setIcon(QIcon(":/images/button_left.png"));
       }
}

void ViewerPOV::on_ButtonPrev_clicked()
{

    if(current->prev != nullptr && current->prev->prev->prev != nullptr){
        current = current->prev;
        ui->ButtonNext->setIcon(QIcon(":/images/button_right.png"));
        ui->kartinka->setPixmap(QPixmap::fromImage(current->image));
    }
    if(current->prev->prev->prev == nullptr) ui->ButtonPrev->setIcon(QIcon(":/images/button_right_inactive.png"));
}


void ViewerPOV::on_ButtonNext_clicked()
{

    if(current->next != nullptr){
        current = current->next;
        ui->ButtonPrev->setIcon(QIcon(":/images/button_left.png"));
        ui->kartinka->setPixmap(QPixmap::fromImage(current->image));
    }
    if(current->next == nullptr) ui->ButtonNext->setIcon(QIcon(":/images/button_left_inactive.png"));
}


void ViewerPOV::on_action_Exit_triggered()
{
    QApplication::quit();
}


void ViewerPOV::on_actionSave_as_triggered()
{

    QString imgSavePath = QFileDialog::getSaveFileName(this, tr("Save image"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.tif)"));
    ui->kartinka->pixmap().save(imgSavePath);
}


void ViewerPOV::on_actionAbout_triggered()
{
    forma.show();
}

