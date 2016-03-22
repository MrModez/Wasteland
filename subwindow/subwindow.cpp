#include "subwindow.h"
#include "QCloseEvent"

SubWindow::SubWindow(int ID, QWidget *parent) : QWidget(parent)
{
    FormID = ID;
}

void SubWindow::closeEvent(QCloseEvent *event)
{
    emit sub_closed(FormID);
    event->accept();
}
