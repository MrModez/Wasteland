#ifndef MAINSELECTFORM_H
#define MAINSELECTFORM_H

#include <QWidget>

namespace Ui {
class MainSelectForm;
}

class MainSelectForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainSelectForm(QWidget *parent = 0);
    ~MainSelectForm();

signals:
    void button_selected(int ID);

private slots:
    void on_pushButton_1_clicked();

private:
    Ui::MainSelectForm *ui;
};

#endif // MAINSELECTFORM_H
