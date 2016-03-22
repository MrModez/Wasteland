#ifndef TABLEAFORM_H
#define TABLEAFORM_H

#include <QtCore>
#include "subwindow.h"

namespace Ui {
class TableAForm;
}

class QSettings;

class TableAForm : public SubWindow
{
    Q_OBJECT

public:
    explicit TableAForm(int ID, QWidget *parent = 0);
    ~TableAForm();

    void InitWithSettings(QSettings *Settings);

private:
    Ui::TableAForm *ui;
};

#endif // TABLEAFORM_H
