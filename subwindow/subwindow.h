#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QtCore>

class SubWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SubWindow(int ID, QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);

signals:
    void sub_closed(int ID);

public slots:

protected:
    int FormID;
};

#endif // SUBWINDOW_H
