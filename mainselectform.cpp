#include "mainselectform.h"
#include "ui_mainselectform.h"
#include "QCloseEvent"

MainSelectForm::MainSelectForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainSelectForm)
{
    ui->setupUi(this);
}

MainSelectForm::~MainSelectForm()
{
    delete ui;
}

void MainSelectForm::closeEvent(QCloseEvent *event)
{
    emit sub_closed(0);
    event->accept();
}

void MainSelectForm::on_pushButton_1_clicked()
{
    emit button_selected(1);
}
