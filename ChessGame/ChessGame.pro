TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bishopfigure.cpp \
        boardvisualizer.cpp \
        chesstablefactory.cpp \
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
        setcastlingexamplefactory.cpp \
        setchessexamplefactory.cpp \
        setchessmatexamplefactory.cpp \
        setpromotionexamplefactory.cpp \
        startgameinitializetablefactory.cpp \
        table.cpp \
        textlogger.cpp

HEADERS += \
    bishopfigure.h \
    boardvisualizer.h \
    chesstablefactory.h \
    field.h \
    figure.h \
    figurecolor.h \
    figurename.h \
    figureset.h \
    game.h \
    inputResultValue.h \
    kingfigure.h \
    knightfigure.h \
    move.h \
    moveresultvalue.h \
    pawnfigure.h \
    player.h \
    queenfigure.h \
    rookfigure.h \
    setcastlingexamplefactory.h \
    setchessexamplefactory.h \
    setchessmatexamplefactory.h \
    setpromotionexamplefactory.h \
    startgameinitializetablefactory.h \
    table.h \
    textlogger.h \
    whiteblackzone.h
