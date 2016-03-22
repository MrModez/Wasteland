#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainSelectForm;
class TableAForm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

public slots:
    void onButtonSelected(int ID);

private:
    Ui::MainWindow *ui;
    void loadSubWindow(QWidget *widget);

    MainSelectForm *SelectForm;
    TableAForm *AForm;
};

#endif // MAINWINDOW_H
