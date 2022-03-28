#ifndef FORMABOUTPOV_H
#define FORMABOUTPOV_H

#include <QWidget>

namespace Ui {
class FormAboutPOV;
}

class FormAboutPOV : public QWidget
{
    Q_OBJECT

public:
    explicit FormAboutPOV(QWidget *parent = nullptr);
    ~FormAboutPOV();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormAboutPOV *ui;
};

#endif // FORMABOUTPOV_H
