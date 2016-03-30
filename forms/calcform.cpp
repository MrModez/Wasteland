#include "calcform.h"
#include "ui_calcform.h"

CalcForm::CalcForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::CalcForm)
{
    ui->setupUi(this);
}

CalcForm::~CalcForm()
{
    delete ui;
}

void CalcForm::setupWindow(QMdiSubWindow *window)
{

}
