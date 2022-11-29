#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T21:27:26
#
#-------------------------------------------------

QT       += core gui
RC_ICONS += cpu.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Y86_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ALU.cpp \
    Assembler.cpp \
    Memory.cpp \
    OpStage.cpp \
    RegFile.cpp \
    RegStage.cpp \
    PipeControlLogic.cpp \
    PipeDiagram.cpp

HEADERS  += mainwindow.h \
    ALU.h \
    Assembler.h \
    Memory.h \
    OpStage.h \
    RegFile.h \
    RegStage.h \
    PipeControlLogic.h \
    PipeDiagram.h

FORMS    += mainwindow.ui

RESOURCES += \
    background.qrc


