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

void CalcForm::setupWindow(QMdiSubWindow *window, QVariant args)
{
    QCustomPlot *customPlot = ui->widget;

    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(fossil);
    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    fossil->setName("Fossil fuels");
    pen.setColor(QColor(255, 131, 0));
    fossil->setPen(pen);
    fossil->setBrush(QColor(255, 131, 0, 50));

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 8);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 12.1);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> fossilData;
    fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    fossil->setData(ticks, fossilData);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
