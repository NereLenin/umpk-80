TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    hex.cpp \
    interpreter.cpp \
    command_list.cpp

HEADERS += \
    hex.h \
    interpreter.h \
    command_list.h
