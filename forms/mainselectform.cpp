#include "mainselectform.h"
#include "ui_mainselectform.h"
#include <QMdiSubWindow>

MainSelectForm::MainSelectForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::MainSelectForm)
{
    ui->setupUi(this);
}

MainSelectForm::~MainSelectForm()
{
    delete ui;
}

void MainSelectForm::on_pushButton_1_clicked()
{
    emit button_selected(1);
}

void MainSelectForm::setupWindow(QMdiSubWindow *window)
{
    window->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
}
