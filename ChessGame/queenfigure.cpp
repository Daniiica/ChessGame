#include "queenfigure.h"

QueenFigure::QueenFigure()
{
    _type = FigureName::queen;
}
bool QueenFigure::isValidFigureMove(Field nextPosition)
{
    BishopFigure bishop;
    RookFigure rook;
    if(bishop.isValidFigureMove(nextPosition))
        return rook.isValidFigureMove(nextPosition);
    return bishop.isValidFigureMove(nextPosition);
}
