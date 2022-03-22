#include "mainwindowpov.h"
#include "ui_mainwindowpov.h"
#include "closefilterpov.h"

MainWindowPOV::MainWindowPOV(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowPOV)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->FieldPOV);
    setWindowIcon(QIcon(":/images/notepad_icon.png"));
    setWindowTitle("Новий документ.txt");
    ui->FieldPOV->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->FieldPOV, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(ShowContextMenu(const QPoint &)));
    CloseFilterPOV* EventFilter1 = new CloseFilterPOV();
    this->installEventFilter(EventFilter1);
    ui->actionNew->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    ui->actionOpen->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_O));
    ui->actionSave->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    ui->actionPrint->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_P));

    ui->actionCopy->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    ui->actionCut->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_X));
    ui->actionPaste->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_V));
    ui->actionUndo->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z));
    ui->actionRedo->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y));
}

void MainWindowPOV::ShowContextMenu(const QPoint &point)
{
    QMenu contextMenu(tr("Context menu"), this);
    contextMenu.addAction(ui->actionUndo);
    contextMenu.addAction(ui->actionRedo);
    contextMenu.addAction(ui->actionCopy);
    contextMenu.addAction(ui->actionPaste);
    contextMenu.addAction(ui->actionCut);
    contextMenu.addAction(ui->actionAbout);

    contextMenu.exec(mapToGlobal(point));

}

MainWindowPOV::~MainWindowPOV()
{

    delete ui;
}



void MainWindowPOV::on_actionNew_triggered()
{
    if(windowTitle().contains('*')){
        on_actionSave_triggered();
    }
    else{
        setWindowTitle("Новий документ.txt");
        CurrentFile.clear();
        ui->FieldPOV->setText(QString());
    }
}


void MainWindowPOV::on_actionOpen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile File(FileName);
    CurrentFile = FileName;
    if(!File.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Cannot open " + FileName + ": " + File.errorString());
        return;
    }
    setWindowTitle(FileName);
    QTextStream in(&File);
    QString Text = in.readAll();
    ui->FieldPOV->setText(Text);
    File.close();
}



void MainWindowPOV::on_actionSave_triggered()
{
    QString FileName = QFileDialog::getSaveFileName(this, "Save");
    QFile File(FileName);
    if(!File.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Cannot save " + FileName + ": " + File.errorString());
        return;
    }
    CurrentFile = FileName;
    setWindowTitle(FileName);
    QTextStream out(&File);
    QString Text = ui->FieldPOV->toPlainText();
    out << Text;
    if(windowTitle().contains("*")){
        QString title = windowTitle();
        title.remove(title.length(), 1);
    }
    File.close();
}


void MainWindowPOV::on_actionExit_Alt_F4_triggered()
{
    if(windowTitle().contains('*')){
        SaveFormPOV* formochkaSave = new SaveFormPOV(this);
        formochkaSave->show();
    }
    else{
        QApplication::quit();
    }
}


void MainWindowPOV::on_actionCopy_triggered()
{
    ui->FieldPOV->copy();
}


void MainWindowPOV::on_actionPaste_triggered()
{
    ui->FieldPOV->paste();
}


void MainWindowPOV::on_actionCut_triggered()
{
    ui->FieldPOV->cut();
}


void MainWindowPOV::on_actionUndo_triggered()
{
    ui->FieldPOV->undo();
}


void MainWindowPOV::on_actionRedo_triggered()
{
    ui->FieldPOV->redo();
}


void MainWindowPOV::on_FieldPOV_textChanged()
{
    if(windowTitle().contains("*")) return;
    setWindowTitle(windowTitle()+"*");
}


void MainWindowPOV::on_actionAbout_triggered()
{
    formochkaAbout.show();
}






