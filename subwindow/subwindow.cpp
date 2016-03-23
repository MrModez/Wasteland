#include "subwindow.h"
#include "QCloseEvent"
#include "qmdisubwindow.h"

SubWindow::SubWindow(int ID, QWidget *parent) : QWidget(parent)
{
    FormID = ID;
}

void SubWindow::closeEvent(QCloseEvent *event)
{
    emit sub_closed(FormID);
    event->accept();
}

void SubWindow::setupWindow(QMdiSubWindow *window)
{
    window->setWindowTitle("TestWindow");
    //window->setWindowIcon(windowIcon());
}
