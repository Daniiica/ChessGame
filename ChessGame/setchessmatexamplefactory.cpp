#include "setchessmatexamplefactory.h"

SetChessMatExampleFactory::SetChessMatExampleFactory()
{

}

Table* SetChessMatExampleFactory::createTable()
{
    Table* tablePtr = new Table();
    Field* fieldPtr{};
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    fieldPtr = tablePtr->getField(0,3);
    KingFigure* kingPtr = new KingFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(kingPtr);

    fieldPtr = tablePtr->getField(1,0);
    PawnFigure* pawn2Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawn2Ptr);

    fieldPtr = tablePtr->getField(1,1);
    PawnFigure* pawn3Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawn3Ptr);

    fieldPtr = tablePtr->getField(1,2);
    PawnFigure* pawn5Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawn5Ptr);

    fieldPtr = tablePtr->getField(1,3);
    PawnFigure* pawn7Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawn7Ptr);

    fieldPtr = tablePtr->getField(1,4);
    PawnFigure* pawn8Ptr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawn8Ptr);

    fieldPtr = tablePtr->getField(0,0);
    RookFigure* rook1Ptr = new RookFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(rook1Ptr);

    fieldPtr = tablePtr->getField(1,6);
    RookFigure* rook2Ptr = new RookFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(rook2Ptr);

    fieldPtr = tablePtr->getField(7,3);
    KingFigure* king2Ptr = new KingFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(king2Ptr);

    tablePtr->setFigureSet(blackFigureSet,0);
    tablePtr->setFigureSet(whiteFigureSet,1);

    return tablePtr;
}
