#include "setchessexamplefactory.h"

SetChessExampleFactory::SetChessExampleFactory()
{

}

Table* SetChessExampleFactory::createTable()
{
    Table* table = new Table();
    //Field* field;
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    KingFigure* king = new KingFigure(FigureColor::Black,table->getField(3,6));
    blackFigureSet.addFigure(king);
    PawnFigure* pawn1 = new PawnFigure(FigureColor::Black,table->getField(2,5));
    blackFigureSet.addFigure(pawn1);
    PawnFigure* pawn2 = new PawnFigure(FigureColor::Black,table->getField(2,6));
    blackFigureSet.addFigure(pawn2);
    PawnFigure* pawn3 = new PawnFigure(FigureColor::Black,table->getField(2,7));
    blackFigureSet.addFigure(pawn3);

    PawnFigure* pawn5 = new PawnFigure(FigureColor::Black,table->getField(3,7));
    blackFigureSet.addFigure(pawn5);
    //  PawnFigure* pawn6 = new PawnFigure(FigureColor::Black,_fields[4][5]);
    //  blackFigureSet.addFigure(pawn6);
    PawnFigure* pawn7 = new PawnFigure(FigureColor::Black,table->getField(4,6));
    blackFigureSet.addFigure(pawn7);
    PawnFigure* pawn8 = new PawnFigure(FigureColor::Black,table->getField(4,7));
    blackFigureSet.addFigure(pawn8);
    RookFigure* rook2 = new RookFigure(FigureColor::Black,table->getField(4,4));
    blackFigureSet.addFigure(rook2);
    RookFigure* rook = new RookFigure(FigureColor::White,table->getField(3,4));
    whiteFigureSet.addFigure(rook);
    KingFigure* kingW = new KingFigure(FigureColor::White,table->getField(0,0));
    whiteFigureSet.addFigure(kingW);
    PawnFigure* pawnW = new PawnFigure(FigureColor::White,table->getField(1,1));
    blackFigureSet.addFigure(pawnW);

    table->setFigureSet(blackFigureSet,0);
    table->setFigureSet(whiteFigureSet,1);

    return table;
}
