#include "mainselectform.h"
#include "ui_mainselectform.h"

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
