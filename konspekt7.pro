#-------------------------------------------------
#
# Project created by QtCreator 2021-03-30T20:08:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = konspekt7
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    tochka.cpp \
    color.cpp \
    pixel.cpp \
    m_widget.cpp \
    line.cpp \
    rect.cpp \
    my_pen.cpp \
    my_brush.cpp \
    okno.cpp \
    dialog_m.cpp \
    ellipse.cpp \
    arc.cpp \
    polyline.cpp \
    polygon.cpp

HEADERS += \
        mainwindow.h \
    tochka.h \
    color.h \
    pixel.h \
    m_widget.h \
    line.h \
    rect.h \
    my_pen.h \
    my_brush.h \
    okno.h \
    dialog_m.h \
    ellipse.h \
    arc.h \
    polyline.h \
    polygon.h

FORMS += \
        mainwindow.ui \
    okno.ui \
    dialog_m.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target