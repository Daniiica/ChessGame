#include "setchessmatexamplefactory.h"

SetChessMatExampleFactory::SetChessMatExampleFactory()
{

}

Table* SetChessMatExampleFactory::createTable()
{
    Table* table = new Table();
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    KingFigure* king = new KingFigure(FigureColor::White,table->getField(0,3));
    whiteFigureSet.addFigure(king);
    PawnFigure* pawn2 = new PawnFigure(FigureColor::White,table->getField(1,0));
    whiteFigureSet.addFigure(pawn2);
    PawnFigure* pawn3 = new PawnFigure(FigureColor::White,table->getField(1,1));
    whiteFigureSet.addFigure(pawn3);
    PawnFigure* pawn5 = new PawnFigure(FigureColor::White,table->getField(1,2));
    whiteFigureSet.addFigure(pawn5);
    PawnFigure* pawn7 = new PawnFigure(FigureColor::White,table->getField(1,3));
    whiteFigureSet.addFigure(pawn7);
    PawnFigure* pawn8 = new PawnFigure(FigureColor::White,table->getField(1,4));
    whiteFigureSet.addFigure(pawn8);
    RookFigure* rook1 = new RookFigure(FigureColor::White,table->getField(0,0));
    whiteFigureSet.addFigure(rook1);
    RookFigure* rook2 = new RookFigure(FigureColor::Black,table->getField(1,6));
    blackFigureSet.addFigure(rook2);
    KingFigure* king2 = new KingFigure(FigureColor::Black,table->getField(7,3));
    blackFigureSet.addFigure(king2);
//    RookFigure* rook3 = new RookFigure(FigureColor::Black,table->getField(2,0));
//    blackFigureSet.addFigure(rook3);
//    KingFigure* kingW = new KingFigure(FigureColor::Black,table->getField(0,0));
//    blackFigureSet.addFigure(kingW);

    table->setFigureSet(blackFigureSet,0);
    table->setFigureSet(whiteFigureSet,1);

    return table;
}
