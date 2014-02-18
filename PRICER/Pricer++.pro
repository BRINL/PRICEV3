#-------------------------------------------------
#
# Project created by QtCreator 2013-07-25T20:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PRICER++
TEMPLATE = app

INCLUDEPATH += $$QT_PROJECT_DIR/PRICER/


SOURCES += main.cpp\
    PayOff.cpp \
    Genealeatoire.cpp \
    Mainwindow.cpp \
    MC.cpp \
    Option.cpp \
    StatGatherer.cpp \
    Greeks.cpp \
    qcustomplot.cpp

HEADERS  += \
    Genealeatoire.h \
    Mainwindow.h \
    MC.h \
    PayOff.h \
    Option.h \
    StatGatherer.h \
    Greeks.h \
    qcustomplot.h \
    Deriv.h \
    FunVect.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    RESSOURCE.qrc
