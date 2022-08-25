#include "setcastlingexamplefactory.h"

SetCastlingExampleFactory::SetCastlingExampleFactory()
{

}

Table* SetCastlingExampleFactory::createTable()
{
    Table* tablePtr = new Table();
    Field* fieldPtr;
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    fieldPtr = tablePtr->getField(7,4);
    KingFigure* kingBPtr = new KingFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(kingBPtr);

    fieldPtr = tablePtr->getField(7,2);
    RookFigure* rookBPtr = new RookFigure(FigureColor::Black, fieldPtr);
    blackFigureSet.addFigure(rookBPtr);

    fieldPtr = tablePtr->getField(0,4);
    KingFigure* kingPtr = new KingFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(kingPtr);

    fieldPtr = tablePtr->getField(0,0);
    RookFigure* rook2Ptr = new RookFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(rook2Ptr);

    fieldPtr = tablePtr->getField(0,7);
    RookFigure* rookPtr = new RookFigure(FigureColor::White, fieldPtr);
    whiteFigureSet.addFigure(rookPtr);

    tablePtr->setFigureSet(blackFigureSet,0);
    tablePtr->setFigureSet(whiteFigureSet,1);

    return tablePtr;
}
