#include "rookfigure.h"

RookFigure::RookFigure()
{
    _type = FigureName::rook;
}
bool RookFigure::isValidFigureMove(Field nextPosition)
{
    if(_currentPosition.getCol() == nextPosition.getCol() ||
           _currentPosition.getRow() == nextPosition.getRow())
            return true;
        return false;
}
