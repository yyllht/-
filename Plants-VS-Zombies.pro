#-------------------------------------------------
#
# Project created by QtCreator 2016-08-28T16:55:19
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Plants-VS-Zombies
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    globalmanager.cpp \
    welcomewidget.cpp \
    advencewidget.cpp \
    sun.cpp \
    label.cpp \
    sunmanager.cpp \
    plantcard.cpp \
    cardmanager.cpp \
    abstractplant.cpp \
    sunflower.cpp \
    warmanager.cpp \
    managermanager.cpp \
    wallnut.cpp \
    peashooter.cpp \
    pea.cpp \
    abstractzombie.cpp \
    normalzombie.cpp \
    bucketheadzombie.cpp \
    polevaultingzombie.cpp \
    winwidget.cpp \
    failwidget.cpp \
    repeater.cpp \
    roadblockzombie.cpp

HEADERS  += mainwindow.h \
    globalmanager.h \
    abstractwidget.h \
    welcomewidget.h \
    advencewidget.h \
    sun.h \
    label.h \
    sunmanager.h \
    plantcard.h \
    cardmanager.h \
    abstractplant.h \
    sunflower.h \
    warmanager.h \
    enumlist.h \
    managermanager.h \
    wallnut.h \
    peashooter.h \
    pea.h \
    abstractzombie.h \
    normalzombie.h \
    bucketheadzombie.h \
    polevaultingzombie.h \
    winwidget.h \
    failwidget.h \
    repeater.h \
    roadblockzombie.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc \
    audio.qrc

