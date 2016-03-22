#include "mainselectform.h"
#include "ui_mainselectform.h"

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

void MainSelectForm::on_pushButton_1_clicked()
{
    emit button_selected(0);
}
