#include "setpromotionexamplefactory.h"

SetPromotionExampleFactory::SetPromotionExampleFactory()
{

}

Table* SetPromotionExampleFactory::createTable()
{
    Table* table = new Table();
    FigureSet blackFigureSet;
    blackFigureSet.setColor(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.setColor(FigureColor::White);

    PawnFigure* pawn = new PawnFigure(FigureColor::White, table->getField(6, 4));
    whiteFigureSet.addFigure(pawn);

 /*   RookFigure* rook2 = new RookFigure(FigureColor::White, table->getField(0, 0));
    whiteFigureSet.addFigure(rook2);
    RookFigure* rook = new RookFigure(FigureColor::White, table->getField(0, 7));
    whiteFigureSet.addFigure(rook);
*/
    KingFigure* kingB = new KingFigure(FigureColor::Black, table->getField(5, 4));
    blackFigureSet.addFigure(kingB);

    KingFigure* kingW = new KingFigure(FigureColor::White, table->getField(5, 1));
    whiteFigureSet.addFigure(kingW);


    table->setFigureSet(blackFigureSet, 0);
    table->setFigureSet(whiteFigureSet, 1);

    return table;

}
