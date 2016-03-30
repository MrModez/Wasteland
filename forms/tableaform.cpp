#include "tableaform.h"
#include "ui_tableaform.h"
#include <QMdiSubWindow>
#include <QStandardItemModel>

TableAForm::TableAForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::TableAForm)
{
    ui->setupUi(this);
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

QList<QStringList> TableAForm::readCSV(QString filename)
{
    // Open csv-file
    QFile file(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    // Read data from file
    QTextStream stream(&file);
    QList<QStringList> data;
    QString separator(",");
    while (stream.atEnd() == false)
    {
        QString line = stream.readLine();
        data << line.split(separator);
    }

    file.close();
    return data;
}

void TableAForm::addStrings(const QStringList &strlist)
{
    QAbstractItemModel *model = ui->tableView->model();
    int row = model->rowCount();
    model->insertRow(model->rowCount());
    int col = 0;
    for (auto &str : strlist)
    {
        QVariant varstr(str);
        model->setData(model->index(row, col), varstr, Qt::EditRole);
        col++;
    }
}

void TableAForm::addHeader(const QStringList &strlist)
{
    QStandardItemModel *itemmodel = new QStandardItemModel(0, strlist.size(), this);
    int col = 0;
    for (auto &str : strlist)
    {
        itemmodel->setHorizontalHeaderItem(col, new QStandardItem(str));
        col++;
    }
    ui->tableView->setModel(itemmodel);
}

void TableAForm::setupWindow(QMdiSubWindow *window)
{
    QList<QStringList> list = readCSV("resource01.csv");
    if (list.empty())
        return;

    addHeader(list[0]);
    for (int i = 1; i < list.size(); i++)
    {
        addStrings(list[i]);
    }
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
