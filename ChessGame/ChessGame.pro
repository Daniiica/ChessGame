TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        field.cpp \
        figure.cpp \
        main.cpp \
        move.cpp \
        player.cpp \
        table.cpp

HEADERS += \
    field.h \
    figure.h \
    move.h \
    player.h \
    table.h
