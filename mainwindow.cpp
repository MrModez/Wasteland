#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmdisubwindow.h"
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

    WindowManager = new SubManager(ui->mdiArea);

    QSettings Settings("myapp.ini", QSettings::IniFormat);

    Settings.beginGroup("MainWindow");
    Settings.setValue("MainSelectionOpened", 0);
    Settings.setValue("ATableWindowOpened", 0);
    Settings.endGroup();
/*
    Settings.beginGroup("ATable");
    Settings.beginWriteArray("ATable");
    QVector<int> test;
    test = {1, 2};
    for(unsigned int i = 0; i < test.size(); i++)
    {
        Settings.setArrayIndex(i);
        Settings.setValue("selected", 1);
    }
    Settings.endArray();
    Settings.endGroup();
*/
    Settings.sync();

    WindowManager->createSubWindow(SUB_MAIN);
}

MainWindow::~MainWindow()
{
    //delete Settings;
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

}
