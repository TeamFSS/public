#-------------------------------------------------
#
# Project created by QtCreator 2013-11-30T12:37:10
#
#-------------------------------------------------

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = communect
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    userhome.cpp \
    processes.cpp

HEADERS  += mainwindow.h \
    userhome.h \
    processes.h

FORMS    += mainwindow.ui \
    userhome.ui

OTHER_FILES +=

RESOURCES += \
    imgresource.qrc

CONFIG += console

INCLUDEPATH += "/home/fss/public/communect/cryptopp"

LIBS += -L"/home/fss/public/communect/cryptopp" -lcrypto++

DESTDIR += $$PWD
