QT       += opengl

CONFIG += designer \
    plugin \
    debug_and_release
TARGET = $$qtLibraryTarget(glwidgetplugin)

TEMPLATE = lib

HEADERS = glwidgetplugin.h
SOURCES = glwidgetplugin.cpp
RESOURCES = icons.qrc
LIBS += -L/usr/local/lib -lGLU

target.path = ~/.designer/plugins/designer
INSTALLS += target
include(glwidget.pri)
