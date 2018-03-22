#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T19:28:40
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tpQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    view/aboutwindow.cpp \
    view/addclientwindow.cpp \
    view/addemployeewindow.cpp \
    view/identificationdialog.cpp \
    view/searchclient.cpp \
    db/initbdd.cpp \
    model/ressource.cpp \
    model/client.cpp \
    model/type.cpp \
    model/compte.cpp \
    model/appointment.cpp \
    controller/toolbox.cpp

HEADERS += \
    mainwindow.h \
    view/aboutwindow.h \
    view/addclientwindow.h \
    view/addemployeewindow.h \
    view/identificationdialog.h \
    view/searchclient.h \
    db/initbdd.h \
    model/ressource.h \
    model/client.h \
    model/type.h \
    model/compte.h \
    model/appointment.h \
    controller/toolbox.h

FORMS += \
    mainwindow.ui \
    identificationdialog.ui \
    addclientwindow.ui \
    addemployeewindow.ui \
    aboutwindow.ui \
    searchclient.ui

RESOURCES += \
    tpqt.qrc

DISTFILES += \
    icon/exit.png \
    icon/checked.png \
    icon/cancel.png
