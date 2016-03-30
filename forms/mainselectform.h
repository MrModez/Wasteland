#ifndef MAINSELECTFORM_H
#define MAINSELECTFORM_H

#include "subwindow.h"
#include <QtCore>

namespace Ui {
class MainSelectForm;
}

class MainSelectForm : public SubWindow
{
    Q_OBJECT

public:
    explicit MainSelectForm(int ID, QWidget *parent = 0);
    ~MainSelectForm();

    void setupWindow(QMdiSubWindow *window);

signals:
    void button_selected(int ID);

private slots:
    void on_pushButtonA_clicked();
    void on_pushButtonSubmit_clicked();

private:
    Ui::MainSelectForm *ui;
};

#endif // MAINSELECTFORM_H
