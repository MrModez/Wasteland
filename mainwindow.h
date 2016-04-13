#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

class SubManager;
class DataImporter;

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void copySettings( QSettings &dst, QSettings &src );
    void setFileName( QString name );

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    SubManager      *WindowManager;
    DataImporter    *Importer;
    QString         Filename;
};

#endif // MAINWINDOW_H
