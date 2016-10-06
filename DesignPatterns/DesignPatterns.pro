QT += core
QT -= gui

CONFIG += c++11

TARGET = DesignPatterns
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    abstractionoccurence.cpp \
    adapter.cpp \
    bridge.cpp \
    builder.cpp \
    chainofresponsibility.cpp \
    facade.cpp \
    command.cpp

HEADERS += \
    abstractionoccurence.h \
    adapter.h \
    bridge.h \
    builder.h \
    chainofresponsibility.h \
    facade.h \
    command.h

DISTFILES +=

RESOURCES +=
