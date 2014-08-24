CONFIG += c++11

QT       += core
QT       += network
QT       -= gui

TARGET = test

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += ../relay
LIBS    += -L../relay -lrelay
