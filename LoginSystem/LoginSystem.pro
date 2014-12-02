#-------------------------------------------------
#
# Project created by QtCreator 2013-11-27T21:25:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    avltree.cpp \
    student.cpp \
    register.cpp \
    change_pw.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    avltree.h \
    student.h \
    register.h \
    change_pw.h

FORMS    += mainwindow.ui \
    dialog.ui \
    register.ui \
    change_pw.ui
