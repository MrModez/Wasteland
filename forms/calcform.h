#ifndef CALCFORM_H
#define CALCFORM_H

#include <QtCore>
#include "subwindow.h"
#include "qcustomplot.h"

namespace Ui {
class CalcForm;
}

class CalcForm : public SubWindow
{
    Q_OBJECT

public:
    explicit CalcForm(int ID, QWidget *parent = 0);
    ~CalcForm();

    void setupWindow(QMdiSubWindow *window, QVariant args);

private slots:
    void Recalculate();
    void CalculatePDK();

    void on_printButton_clicked();

private:
    Ui::CalcForm *ui;
    QCPBars *distrib;
    QList<QVariant>strings;
    QList<QVariant>PDK;
    int selectedID;
    QTextEdit *textEdit;
};

#endif // CALCFORM_H
