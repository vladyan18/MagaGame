#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T16:10:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network

TARGET = MagaGame_v1
TEMPLATE = app



SOURCES += main.cpp\
       mainwindow.cpp \
    ministrys/kgb.cpp \
    ministrys/mid.cpp \
    ministrys/mincom.cpp \
    ministrys/mindef.cpp \
    ministrys/minfin.cpp \
    ministrys/minhel.cpp \
    ministrys/minust.cpp \
    ministrys/mvd.cpp \
    ministrys/president.cpp \
    ministrys/secretary.cpp \
    dialogs/approved.cpp \
    dialogs/connectdial.cpp \
    dialogs/helpdialog.cpp \
    dialogs/pickthemin.cpp \
    dialogs/report.cpp \
    dialogs/statistic.cpp \
    tools/nettransmitter.cpp \
    getnumdialog.cpp \
    dialogs/reconreport.cpp

HEADERS  +=   \
    mainwindow.h \
    ministrys/kgb.h \
    ministrys/mid.h \
    ministrys/mincom.h \
    ministrys/mindef.h \
    ministrys/minfin.h \
    ministrys/minhel.h \
    ministrys/minust.h \
    ministrys/mvd.h \
    ministrys/president.h \
    ministrys/secretary.h \
    dialogs/approved.h \
    dialogs/connectdial.h \
    dialogs/helpdialog.h \
    dialogs/pickthemin.h \
    dialogs/report.h \
    dialogs/statistic.h \
    tools/nettransmitter.h \
    Command.h \
    getnumdialog.h \
    ministrys/iminister.h \
    dialogs/reconreport.h


FORMS    += mainwindow.ui \
    ministrys/kgb.ui \
    ministrys/mid.ui \
    ministrys/mincom.ui \
    ministrys/mindef.ui \
    ministrys/minfin.ui \
    ministrys/minhel.ui \
    ministrys/minust.ui \
    ministrys/mvd.ui \
    ministrys/president.ui \
    ministrys/secretary.ui \
    dialogs/approved.ui \
    dialogs/connectdial.ui \
    dialogs/helpdialog.ui \
    dialogs/pickthemin.ui \
    dialogs/report.ui \
    dialogs/statistic.ui \
    getnumdialog.ui \
    dialogs/reconreport.ui

RESOURCES += \
    resources.qrc

RC_FILE = icon.rc

