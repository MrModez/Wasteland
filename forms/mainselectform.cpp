#include "mainselectform.h"
#include "ui_mainselectform.h"
#include "shareddefs.h"
#include <QMdiSubWindow>

MainSelectForm::MainSelectForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::MainSelectForm)
{
    ui->setupUi(this);
}

MainSelectForm::~MainSelectForm()
{
    delete ui;
}

void MainSelectForm::setupWindow(QMdiSubWindow *window, QVariant args)
{
    window->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
}

void MainSelectForm::on_pushButtonA_clicked()
{
    emit button_selected(SUB_TABLE_A);
}

void MainSelectForm::on_pushButtonSubmit_clicked()
{
    emit button_selected(SUB_CALC);
}
