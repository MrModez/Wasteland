#ifndef SUBMANAGER_H
#define SUBMANAGER_H

#include <QObject>
#include <QtCore>
#include <QMdiArea>

class SubWindow;
class DataImporter;

class SubManager : public QObject
{
    Q_OBJECT
public:
    explicit SubManager(QMdiArea *MdiSubArea, DataImporter *Imp, QObject *parent = 0);
    void loadSubWindow(SubWindow *widget, int ID);
    void createSubWindow(int ID, bool forced = false);
    SubWindow *GetSubWindow(int ID);
    SubWindow *WindowFactrory(int ID);
    void updateWindows();

signals:

public slots:
    void onButtonSelected(int ID);
    void onSubWindowDestroyed(int ID);
    void onItemsSelected(QVector<bool> Rows);

private:
    std::vector<SubWindow*>SubWindows;
    QMdiArea   *mdiArea;
    DataImporter    *Importer;
};

#endif // SUBMANAGER_H
