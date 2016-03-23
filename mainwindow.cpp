#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include <QFileDialog>
#include "shareddefs.h"
#include "submanager.h"
#include "mainselectform.h"
#include "tableaform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    setFileName("");
    WindowManager = new SubManager(ui->mdiArea);
    WindowManager->createSubWindow(SUB_SELECT_MAIN);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    QSettings Settings("Wasteland");
    Settings.clear();
    WindowManager->updateWindows();
    WindowManager->createSubWindow(SUB_SELECT_MAIN);
}

void MainWindow::on_actionOpen_triggered()
{
    QSettings Settings("Wasteland");
    QString fileName = QFileDialog::getOpenFileName(this, "Wasteland settings","",
             "Settings (*.ini)");
    if(QFile(fileName).exists())
    {
        QSettings settings(fileName, QSettings::IniFormat);
        copySettings(Settings, settings);
        Settings.sync();
        setFileName(fileName);
        WindowManager->updateWindows();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (Filename == "")
    {
        on_actionSaveAs_triggered();
        return;
    }

    QSettings Settings("Wasteland");
    QSettings SettingsINI(Filename, QSettings::IniFormat);
    copySettings(SettingsINI, Settings);
    SettingsINI.sync();
}

void MainWindow::on_actionSaveAs_triggered()
{
    QSettings Settings("Wasteland");
    QString fileName = QFileDialog::getSaveFileName(this, "Wasteland settings","",
             "Settings (*.ini)");
    if (!fileName.isEmpty())
    {
        QSettings settings(fileName, QSettings::IniFormat);
        copySettings(settings, Settings);
        settings.sync();
        setFileName(fileName);
    }
}

void MainWindow::setFileName( QString name )
{
    Filename = name;
}

void MainWindow::copySettings( QSettings &dst, QSettings &src )
{
    QStringList keys = src.allKeys();
    for( QStringList::iterator i = keys.begin(); i != keys.end(); i++ )
    {
        dst.setValue( *i, src.value( *i ) );
    }
}
