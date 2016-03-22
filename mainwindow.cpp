#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmdisubwindow.h"
#include "mainselectform.h"
#include "tableaform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonSelected(int ID)
{
    AForm = new TableAForm(this);
    loadSubWindow(AForm);
}

void MainWindow::loadSubWindow(QWidget* widget)
{
    QMdiSubWindow* window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle("TestWindow"); //widget->windowTitle()
    window->setWindowIcon(widget->windowIcon());
    window->show();
}

void MainWindow::on_actionNew_triggered()
{
    SelectForm = new MainSelectForm(this);
    loadSubWindow(SelectForm);

    if (SelectForm)
    {
        connect(SelectForm, &MainSelectForm::button_selected, this, &MainWindow::onButtonSelected);
    }
}
