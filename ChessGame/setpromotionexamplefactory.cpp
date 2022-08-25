#include "setpromotionexamplefactory.h"

SetPromotionExampleFactory::SetPromotionExampleFactory()
{

}

Table* SetPromotionExampleFactory::createTable()
{
    Table* tablePtr = new Table();
    Field* fieldPtr;
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    fieldPtr = tablePtr->getField(6, 4);
    PawnFigure* pawnPtr = new PawnFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(pawnPtr);

    fieldPtr = tablePtr->getField(6, 6);
    RookFigure* rook2Ptr = new RookFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(rook2Ptr);

    fieldPtr = tablePtr->getField(7, 5);
    RookFigure* rookPtr = new RookFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(rookPtr);

    fieldPtr = tablePtr->getField(5, 4);
    KingFigure* kingBPtr = new KingFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(kingBPtr);

    fieldPtr = tablePtr->getField(6, 1);
    KingFigure* kingWPtr = new KingFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(kingWPtr);


    tablePtr->setFigureSet(blackFigureSet, 0);
    tablePtr->setFigureSet(whiteFigureSet, 1);

    return tablePtr;

}
