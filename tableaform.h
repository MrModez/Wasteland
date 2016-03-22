#ifndef TABLEAFORM_H
#define TABLEAFORM_H

#include <QDialog>

namespace Ui {
class TableAForm;
}

class TableAForm : public QDialog
{
    Q_OBJECT

public:
    explicit TableAForm(QWidget *parent = 0);
    ~TableAForm();

private:
    Ui::TableAForm *ui;
};

#endif // TABLEAFORM_H
