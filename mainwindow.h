#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

class SubManager;
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

private:
    Ui::MainWindow *ui;
    SubManager      *WindowManager;
    MainSelectForm  *SelectForm;
    TableAForm      *AForm;
};

#endif // MAINWINDOW_H
