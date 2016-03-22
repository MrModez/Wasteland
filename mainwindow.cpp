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
    showMaximized();

    Settings = new QSettings("myapp.ini", QSettings::IniFormat);

    Settings->beginGroup("MainWindow");
    Settings->setValue("MainSelectionOpened", 0);
    Settings->setValue("ATableWindowOpened", 0);
    Settings->endGroup();

    Settings->beginGroup("ATable");
    Settings->beginWriteArray("ATable");
    QVector<int> test;
    test = {1, 2};
    for(unsigned int i = 0; i < test.size(); i++)
    {
        Settings->setArrayIndex(i);
        Settings->setValue("selected", 1);
    }
    Settings->endArray();
    Settings->endGroup();

    Settings->sync();

    createSubWindow(SUB_MAIN);
}

MainWindow::~MainWindow()
{
    delete Settings;
    delete ui;
}

void MainWindow::onButtonSelected(int ID)
{
    createSubWindow((SubWindow)ID);
}

void MainWindow::loadSubWindow(QWidget* widget)
{
    QMdiSubWindow* window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle("TestWindow");
    window->setWindowIcon(widget->windowIcon());
    //window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
    if (window->widget() == SelectForm)
        window->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    //connect(window, &QMdiSubWindow::destroyed, this, &MainWindow::onSubWindowDestroyed);
}

void MainWindow::createSubWindow(SubWindow ID)
{
    if (ID == SUB_MAIN)
    {
        Settings->beginGroup("MainWindow");
        bool opened = Settings->value("MainSelectionOpened").toBool();
        Settings->endGroup();
        if (opened)
            return;

        SelectForm = new MainSelectForm(this);
        loadSubWindow(SelectForm);

        if (SelectForm)
        {
            connect(SelectForm, &MainSelectForm::button_selected, this, &MainWindow::onButtonSelected);
            connect(SelectForm, &MainSelectForm::sub_closed, this, &MainWindow::onSubWindowDestroyed);
            Settings->beginGroup("MainWindow");
            Settings->setValue("MainSelectionOpened", 1);
            Settings->endGroup();
        }
    }
    else if (ID == SUB_ATABLE)
    {
        Settings->beginGroup("MainWindow");
        bool opened = Settings->value("ATableWindowOpened").toBool();
        Settings->endGroup();
        if (opened)
            return;

        AForm = new TableAForm(this);
        loadSubWindow(AForm);

        if (AForm)
        {
            Settings->beginGroup("MainWindow");
            Settings->setValue("ATableWindowOpened", 1);
            Settings->endGroup();
        }
    }
}

void MainWindow::onSubWindowDestroyed(int ID)
{
    qDebug() << "YES " << ID;
    Settings->beginGroup("MainWindow");
    if ((SubWindow)ID == SUB_MAIN)
    {
        Settings->setValue("MainSelectionOpened", 0);
    }
    if ((SubWindow)ID == SUB_ATABLE)
    {
        Settings->setValue("ATableWindowOpened", 0);
    }
    Settings->endGroup();
}

void MainWindow::on_actionNew_triggered()
{

}
