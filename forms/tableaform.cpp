#include "tableaform.h"
#include "ui_tableaform.h"
#include <QMdiSubWindow>
#include <QStandardItemModel>

TableAForm::TableAForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::TableAForm)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(5, 3, this); //2 Rows and 3 Columns
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Column1 Header")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("Column2 Header")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Column3 Header")));

    ui->tableView->setModel(model);
}

TableAForm::~TableAForm()
{
    delete ui;
}

void TableAForm::on_confirmButton_clicked()
{
    QVector<bool> Rows;
    int size = ui->tableView->model()->rowCount();
    auto SelIndexes = ui->tableView->selectionModel()->selectedRows();
    //TODO: fix this shitcode
    for (int i = 0; i < size; i++)
    {
        bool found = false;
        for (int r = 0; r < SelIndexes.size(); r++)
            if (i == SelIndexes[r].row())
            {
                found = true;
                break;
            }
        Rows.push_back(found);
    }
   emit items_selected(Rows);
}

void TableAForm::setupWindow(QMdiSubWindow *window)
{
    ui->tableView->clearSelection();
    ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);

    QSettings Settings("Wasteland");
    Settings.beginGroup("TableA");
    int size = Settings.beginReadArray("Rows");
    for (int i = 0; i < size; i++)
    {
        Settings.setArrayIndex(i);
        bool val = Settings.value("selected", false).toBool();
        if (val)
            ui->tableView->selectRow(i);
    }
    Settings.endArray();
    Settings.endGroup();
}
