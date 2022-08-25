#include "setchessexamplefactory.h"

SetChessExampleFactory::SetChessExampleFactory()
{

}

Table* SetChessExampleFactory::createTable()
{
    Table* tablePtr = new Table();
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);
    Field* fieldPtr;

    fieldPtr = tablePtr->getField(3,6);
    KingFigure* kingPtr = new KingFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(kingPtr);

    fieldPtr = tablePtr->getField(2,5);
    PawnFigure* pawn1Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn1Ptr);

    fieldPtr = tablePtr->getField(2,6);
    PawnFigure* pawn2Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn2Ptr);

    fieldPtr = tablePtr->getField(2,7);
    PawnFigure* pawn3Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn3Ptr);

    fieldPtr = tablePtr->getField(3,7);
    PawnFigure* pawn5Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn5Ptr);

    fieldPtr = tablePtr->getField(4,6);
    PawnFigure* pawn7Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn7Ptr);

    fieldPtr = tablePtr->getField(4,7);
    PawnFigure* pawn8Ptr = new PawnFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(pawn8Ptr);

    fieldPtr = tablePtr->getField(4,4);
    RookFigure* rook2Ptr = new RookFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(rook2Ptr);

    fieldPtr = tablePtr->getField(3,4);
    RookFigure* rookPtr = new RookFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(rookPtr);

    fieldPtr = tablePtr->getField(0,0);
    KingFigure* kingWPtr = new KingFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(kingWPtr);

    fieldPtr = tablePtr->getField(2,4);
    PawnFigure* pawnW1Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawnW1Ptr);

    fieldPtr = tablePtr->getField(1,1);
    PawnFigure* pawnWPtr = new PawnFigure(FigureColor::White, fieldPtr);
    blackFigureSet.addFigure(pawnWPtr);

    tablePtr->setFigureSet(blackFigureSet,0);
    tablePtr->setFigureSet(whiteFigureSet,1);
    return tablePtr;
}
