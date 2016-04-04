#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T20:30:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Wasteland
TEMPLATE = app

INCLUDEPATH += forms \
               subwindow    \
               shared       \
               libs

SOURCES += main.cpp\
        mainwindow.cpp \
    forms/mainselectform.cpp \
    forms/tableaform.cpp \
    subwindow/submanager.cpp \
    subwindow/subwindow.cpp \
    forms/calcform.cpp \
    libs/qcustomplot.cpp \
    dataimporter.cpp

HEADERS  += mainwindow.h \
    forms/mainselectform.h \
    forms/tableaform.h \
    shared/shareddefs.h \
    subwindow/submanager.h \
    subwindow/subwindow.h \
    forms/calcform.h \
    libs/qcustomplot.h \
    dataimporter.h

FORMS    += mainwindow.ui \
    forms/mainselectform.ui \
    forms/tableaform.ui \
    forms/calcform.ui

QMAKE_CXXFLAGS += -std=gnu++14
