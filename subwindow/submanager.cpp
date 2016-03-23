#include "submanager.h"
#include "shareddefs.h"
#include "qmdisubwindow.h"
#include "mainselectform.h"
#include "tableaform.h"

const char *SubWindowFlags[SUB_COUNT] =
{
    "MainSelectionOpened",
    "TableAWindowOpened"
};

SubManager::SubManager(QMdiArea *MdiSubArea, QObject *parent) : QObject(parent)
{
    mdiArea = MdiSubArea;
    SubWindows.resize(SUB_COUNT);

    QSettings Settings("myapp.ini", QSettings::IniFormat);
    Settings.beginGroup("MainWindow");
    for (auto c : SubWindowFlags)
        Settings.setValue(c, 0);
    Settings.endGroup();
    Settings.sync();
}

SubWindow *SubManager::GetSubWindow(int ID)
{
    return SubWindows[ID];
}

void SubManager::loadSubWindow(SubWindow *widget)
{
    QMdiSubWindow* window = mdiArea->addSubWindow(widget);
    widget->setupWindow(window);
    window->show();
}

void SubManager::createSubWindow(int ID)
{
    QSettings Settings("myapp.ini", QSettings::IniFormat);
    Settings.beginGroup("MainWindow");
    bool opened = Settings.value(SubWindowFlags[ID]).toBool();
    Settings.endGroup();

    if (opened)
        return;

    SubWindow *SubForm = WindowFactrory(ID);
    if (SubForm)
    {
        SubWindows[ID] = SubForm;
        loadSubWindow(SubForm);
        Settings.beginGroup("MainWindow");
        Settings.setValue(SubWindowFlags[ID], 1);
        Settings.endGroup();

        connect(SubForm, &SubWindow::sub_closed, this, &SubManager::onSubWindowDestroyed);
        if (ID == SUB_SELECT_MAIN)
            connect(dynamic_cast<MainSelectForm*>(SubForm), &MainSelectForm::button_selected, this, &SubManager::onButtonSelected);
        if (ID == SUB_TABLE_A)
            connect(dynamic_cast<TableAForm*>(SubForm), &TableAForm::items_selected, this, &SubManager::onItemsSelected);
    }
}

void SubManager::onButtonSelected(int ID)
{
    createSubWindow((SubWindowID)ID);
}

void SubManager::onSubWindowDestroyed(int ID)
{
    QSettings Settings("myapp.ini", QSettings::IniFormat);
    Settings.beginGroup("MainWindow");
    Settings.setValue(SubWindowFlags[ID], 0);
    Settings.endGroup();
}

void SubManager::onItemsSelected(QVector<bool> Rows)
{
    QSettings Settings("myapp.ini", QSettings::IniFormat);
    Settings.beginGroup("TableA");
    Settings.beginWriteArray("Rows");
    for (int i = 0; i < Rows.size(); i++)
    {
        Settings.setArrayIndex(i);
        Settings.setValue("selected", Rows[i]);
    }
    Settings.endArray();
    Settings.endGroup();
}

SubWindow *SubManager::WindowFactrory(int ID)
{
    if (ID == SUB_SELECT_MAIN)
    {
        MainSelectForm* SubForm = new MainSelectForm(ID, (QWidget*)parent());
        return SubForm;
    }
    else if (ID == SUB_TABLE_A)
    {
        TableAForm* SubForm = new TableAForm(ID, (QWidget*)parent());
        return SubForm;
    }
    return NULL;
}
