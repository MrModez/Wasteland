#include "calcform.h"
#include "ui_calcform.h"
#include "qcpdocumentobject.h"

CalcForm::CalcForm(int ID, QWidget *parent) : SubWindow(ID, parent), ui(new Ui::CalcForm)
{
    ui->setupUi(this);
    selectedID = -1;

    textEdit = new QTextEdit(this);
    QCPDocumentObject *plotObjectHandler = new QCPDocumentObject(this);
    textEdit->document()->documentLayout()->registerHandler(QCPDocumentObject::PlotTextFormat, plotObjectHandler);
    textEdit->setVisible(false);
}

CalcForm::~CalcForm()
{
    delete ui;
}

void CalcForm::setupWindow(QMdiSubWindow *window, QVariant args)
{
    strings = args.toList();
    if (strings.empty())
        return;
    int i = 0;
    for (auto &str : strings[0].toStringList())
    {
        if (++i < 3)
            continue;
        QRadioButton *button = new QRadioButton(this);
        ui->horizontalLayout->addWidget(button);
        button->setText(str);
        connect(button, &QRadioButton::released, this, &CalcForm::Recalculate);
    }

    QCustomPlot *customPlot = ui->widget;

    distrib = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(distrib);
    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    distrib->setName("Distribution");
    pen.setColor(QColor(255, 131, 0));
    distrib->setPen(pen);
    distrib->setBrush(QColor(255, 131, 0, 50));


}

void CalcForm::Recalculate()
{
    int ID = -1;
    for (int i = 0; i < ui->horizontalLayout->count(); ++i)
    {
        QRadioButton *button =
                dynamic_cast<QRadioButton*>(ui->horizontalLayout->itemAt(i)->widget());
        if (button->isChecked())
        {
            ID = i;
        }
    }
    if (ID == -1)
        return;
    selectedID = ID;

    QString str = strings[0].toStringList()[ID + 2];
    QVector<float> data;
    int max = 0;
    int min = INT_MAX;

    QSettings Settings("Wasteland");
    Settings.beginGroup("TableA");
    Settings.beginReadArray("Rows");
    for (int i = 1; i < strings.count(); i++)
    {
        Settings.setArrayIndex(i);
        bool selected = Settings.value("selected", false).toBool();
        if (!selected)
            continue;

        int val = strings[i].toStringList()[ID + 2].toInt();
        data << val;
        if (val > max)
            max = val;
        if (val < min)
            min = val;
    }
    Settings.endArray();
    Settings.endGroup();

    int N = data.count();
    int count = 1 + (log10(N) * 3.322);
    float section = (float)(min + max) / (float)count;

    QCustomPlot *customPlot = ui->widget;
    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    for (int i = 0; i < count; i++)
    {
        ticks << i + 1;
        labels << QString::number(section * (float)i) + "-" + QString::number(section * (float)(i + 1) - 1);
    }
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(0);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, count + 1);

    // prepare y axis:
    customPlot->yAxis->setRange(0, N);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setTickStep(1);
    customPlot->yAxis->setLabel(str);
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> distribData;
    for (int i = 0; i < count; i++)
    {
        int val = 0;
        for (int j = 0; j < N; j++)
        {
            if (data[j] >= section * i && data[j] < section * (i + 1))
                val++;
        }
        distribData << val;
    }
    distrib->setData(ticks, distribData);
    //customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    customPlot->replot();
}

void CalcForm::on_printButton_clicked()
{
    QTextCursor cursor = textEdit->textCursor();

    double width = 600;
    double height = 400;
    cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(ui->widget, width, height));
    textEdit->setTextCursor(cursor);


    QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "PDF file (*.pdf)");
    if (!fileName.isEmpty())
    {
      QPrinter printer;
      printer.setFullPage(true);
      printer.setPaperSize(QPrinter::A4);
      printer.setOrientation(QPrinter::Portrait);
      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName(fileName);
      textEdit->document()->print(&printer);
    }

}
