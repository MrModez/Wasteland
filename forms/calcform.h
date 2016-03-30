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

    void setupWindow(QMdiSubWindow *window);

private:
    Ui::CalcForm *ui;
};

#endif // CALCFORM_H
