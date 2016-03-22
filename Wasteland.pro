#-------------------------------------------------
#
# Project created by QtCreator 2016-03-22T20:30:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wasteland
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainselectform.cpp \
    tableaform.cpp

HEADERS  += mainwindow.h \
    mainselectform.h \
    tableaform.h

FORMS    += mainwindow.ui \
    mainselectform.ui \
    tableaform.ui

QMAKE_CXXFLAGS += -std=gnu++14
