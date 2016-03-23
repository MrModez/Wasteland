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

    void initWithSettings(QSettings *Settings);
    void setupWindow(QMdiSubWindow *window);

signals:
    void items_selected(QVector<bool> Rows);

private slots:
    void on_confirmButton_clicked();

private:
    Ui::TableAForm *ui;
};

#endif // TABLEAFORM_H
