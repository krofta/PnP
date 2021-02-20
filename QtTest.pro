#-------------------------------------------------
#
# Project created by QtCreator 2019-09-18T14:06:41
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest
TEMPLATE = app


SOURCES += main.cpp\
    customtablewidgetitem.cpp \
        mainwindow.cpp \
    libdxfrw/src/intern/drw_textcodec.cpp \
    libdxfrw/src/intern/dxfreader.cpp \
    libdxfrw/src/intern/dxfwriter.cpp \
    libdxfrw/src/drw_entities.cpp \
    libdxfrw/src/drw_objects.cpp \
    libdxfrw/src/libdxfrw.cpp \
    src/dxfinterface.cpp \
    src/dxfsceneview.cpp \
    src/mtexttohtml.cpp \
    src/spline.cpp \
    csv_parser.cpp \
    pcb_part.cpp \
    customitem.cpp \
    ColorPickerActionWidget.cpp \
    ColorPickerToolButton.cpp

HEADERS  += mainwindow.h \
    customtablewidgetitem.h \
    libdxfrw/src/intern/drw_cptable932.h \
    libdxfrw/src/intern/drw_cptable936.h \
    libdxfrw/src/intern/drw_cptable949.h \
    libdxfrw/src/intern/drw_cptable950.h \
    libdxfrw/src/intern/drw_cptables.h \
    libdxfrw/src/intern/drw_textcodec.h \
    libdxfrw/src/intern/dxfreader.h \
    libdxfrw/src/intern/dxfwriter.h \
    libdxfrw/src/drw_base.h \
    libdxfrw/src/drw_entities.h \
    libdxfrw/src/drw_interface.h \
    libdxfrw/src/drw_objects.h \
    libdxfrw/src/libdxfrw.h \
    src/dxfinterface.h \
    src/dxfsceneview.h \
    src/mtexttohtml.h \
    src/scene_items.h \
    src/spline.h \
    csv_parser.h \
    pcb_part.h \
    customitem.h \
    ColorPickerActionWidget.h \
    ColorPickerToolButton.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
