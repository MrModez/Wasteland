#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QtCore>

class QMdiSubWindow;

class SubWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SubWindow(int ID, QWidget *parent = 0);

    virtual void closeEvent(QCloseEvent *event);
    virtual void setupWindow(QMdiSubWindow *window, QVariant args);

signals:
    void sub_closed(int ID);

public slots:

protected:
    int FormID;
};

#endif // SUBWINDOW_H
