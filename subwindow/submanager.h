#ifndef SUBMANAGER_H
#define SUBMANAGER_H

#include <QObject>
#include <QtCore>
#include <QMdiArea>

class SubWindow;

class SubManager : public QObject
{
    Q_OBJECT
public:
    explicit SubManager(QMdiArea *MdiSubArea, QObject *parent = 0);
    void loadSubWindow(QWidget *widget);
    void createSubWindow(int ID);
    SubWindow *GetSubWindow(int ID);
    SubWindow *WindowFactrory(int ID);

signals:

public slots:
    void onButtonSelected(int ID);
    void onSubWindowDestroyed(int ID);

private:
    std::vector<SubWindow*>SubWindows;
    QMdiArea   *mdiArea;
};

#endif // SUBMANAGER_H
