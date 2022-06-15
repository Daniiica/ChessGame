TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bishopfigure.cpp \
        field.cpp \
        figure.cpp \
        figureset.cpp \
        game.cpp \
        kingfigure.cpp \
        knightfigure.cpp \
        main.cpp \
        move.cpp \
        pawnfigure.cpp \
        player.cpp \
        queenfigure.cpp \
        rookfigure.cpp \
        table.cpp

HEADERS += \
    bishopfigure.h \
    field.h \
    figure.h \
    figurecolor.h \
    figurename.h \
    figureset.h \
    game.h \
    kingfigure.h \
    knightfigure.h \
    move.h \
    pawnfigure.h \
    player.h \
    queenfigure.h \
    rookfigure.h \
    table.h
