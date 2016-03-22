#include "submanager.h"
#include "shareddefs.h"
#include "qmdisubwindow.h"
#include "mainselectform.h"
#include "tableaform.h"

const char *SubWindowFlags[SUB_COUNT] =
{
    "MainSelectionOpened",
    "ATableWindowOpened"
};

SubManager::SubManager(QMdiArea *MdiSubArea, QObject *parent) : QObject(parent)
{
    mdiArea = MdiSubArea;
    SubWindows.resize(SUB_COUNT);
}

SubWindow *SubManager::GetSubWindow(int ID)
{
    return SubWindows[ID];
}

void SubManager::loadSubWindow(QWidget* widget)
{
    QMdiSubWindow* window = mdiArea->addSubWindow(widget);
    window->setWindowTitle("TestWindow");
    window->setWindowIcon(widget->windowIcon());
    window->show();
    if (window->widget() == GetSubWindow(SUB_MAIN))
        window->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
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
        if (ID == SUB_MAIN)
        {
            connect(dynamic_cast<MainSelectForm*>(SubForm), &MainSelectForm::button_selected, this, &SubManager::onButtonSelected);
        }
    }
}

void SubManager::onButtonSelected(int ID)
{
    createSubWindow((SubWindowID)ID);
}

void SubManager::onSubWindowDestroyed(int ID)
{
    QSettings Settings("myapp.ini", QSettings::IniFormat);

    qDebug() << "YES " << ID;
    Settings.beginGroup("MainWindow");
    Settings.setValue(SubWindowFlags[ID], 0);
    Settings.endGroup();
}

SubWindow *SubManager::WindowFactrory(int ID)
{
    if (ID == SUB_MAIN)
    {
        MainSelectForm* SubForm = new MainSelectForm(ID, (QWidget*)parent());
        return SubForm;
    }
    else if (ID == SUB_ATABLE)
    {
        TableAForm* SubForm = new TableAForm(ID, (QWidget*)parent());
        return SubForm;
    }
    return NULL;
}
