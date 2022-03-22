#ifndef ABOUTFORMPOV_H
#define ABOUTFORMPOV_H

#include <QWidget>

namespace Ui {
class AboutFormPOV;
}

class AboutFormPOV : public QWidget
{
    Q_OBJECT

public:
    explicit AboutFormPOV(QWidget *parent = nullptr);
    ~AboutFormPOV();

private:
    Ui::AboutFormPOV *ui;
};

#endif // ABOUTFORMPOV_H
