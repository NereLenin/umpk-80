TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    hex.cpp \
    command_list.cpp \
    emulator.cpp \
    msg_error.cpp

HEADERS += \
    hex.h \
    command_list.h \
    emulator.h \
    msg_error.h
