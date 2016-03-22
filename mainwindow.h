#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

class MainSelectForm;
class TableAForm;

namespace Ui {
class MainWindow;
}

enum SubWindow
{
    SUB_MAIN = 0,
    SUB_ATABLE,
    ///
    SUB_COUNT
};

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
    void onSubWindowDestroyed(int ID);

private:
    Ui::MainWindow *ui;
    void loadSubWindow(QWidget *widget);
    void createSubWindow(SubWindow ID);

    MainSelectForm *SelectForm;
    TableAForm     *AForm;
    QSettings      *Settings;
};

#endif // MAINWINDOW_H
