#include "bishopfigure.h"

BishopFigure::BishopFigure()
{
    _type = FigureName::bishop;
}
bool BishopFigure::isValidFigureMove(Field nextPosition)
{
    if(abs(_currentPosition.getCol() - nextPosition.getCol()) == abs(_currentPosition.getRow() - nextPosition.getRow()))
            return true;
        return false;
}
