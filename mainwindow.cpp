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
    WindowManager->createSubWindow(SUB_SELECT_MAIN);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{

}
