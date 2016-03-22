#include "tableaform.h"
#include "ui_tableaform.h"
#include "QStandardItemModel.h"

TableAForm::TableAForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::TableAForm)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(2, 3, this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    ui->tableView->setModel(model);
}

TableAForm::~TableAForm()
{
    delete ui;
}