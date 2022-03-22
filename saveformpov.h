#ifndef SAVEFORMPOV_H
#define SAVEFORMPOV_H

#include <QWidget>

namespace Ui {
class SaveFormPOV;
}

class SaveFormPOV : public QWidget
{
    Q_OBJECT
    friend class MainWindowPOV;

public:
    explicit SaveFormPOV(MainWindowPOV* Notepad = nullptr, QWidget *parent = nullptr);
    ~SaveFormPOV();
    MainWindowPOV* m_win;
public slots:

    void on_SaveButtonPOV_clicked();

private slots:
    void on_NoSaveButtonPOV_clicked();

    void on_CancelButtonPOV_clicked();

private:
    Ui::SaveFormPOV *ui;
};

#endif // SAVEFORMPOV_H
