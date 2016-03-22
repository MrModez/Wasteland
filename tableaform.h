#ifndef TABLEAFORM_H
#define TABLEAFORM_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class TableAForm;
}

class QSettings;

class TableAForm : public QDialog
{
    Q_OBJECT

public:
    explicit TableAForm(QWidget *parent = 0);
    ~TableAForm();

    void closeEvent(QCloseEvent *event);
    void InitWithSettings(QSettings *Settings);

signals:
    void sub_closed(int ID);

private:
    Ui::TableAForm *ui;
};

#endif // TABLEAFORM_H
