#include "setcastlingexamplefactory.h"

SetCastlingExampleFactory::SetCastlingExampleFactory()
{

}

Table* SetCastlingExampleFactory::createTable()
{
    Table* table = new Table();
    Field* field;
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    field = table->getField(7,4);
    KingFigure* kingB = new KingFigure(FigureColor::Black, field);
    blackFigureSet.addFigure(kingB);

    field = table->getField(0,4);
    KingFigure* king = new KingFigure(FigureColor::White, field);
    whiteFigureSet.addFigure(king);

    field = table->getField(0,0);
    RookFigure* rook2 = new RookFigure(FigureColor::White, field);
    whiteFigureSet.addFigure(rook2);

    field = table->getField(0,7);
    RookFigure* rook = new RookFigure(FigureColor::White, field);
    whiteFigureSet.addFigure(rook);

    table->setFigureSet(blackFigureSet,0);
    table->setFigureSet(whiteFigureSet,1);

    return table;

}
