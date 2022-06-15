#include "kingfigure.h"

KingFigure::KingFigure()
{
    _type = FigureName::king;
}
bool KingFigure::isValidFigureMove(Field nextPosition)
{
    if((nextPosition.getCol() == _currentPosition.getCol() ||
          (abs(nextPosition.getCol()) - abs(_currentPosition.getCol()) == 1)) &&
          (nextPosition.getRow() == _currentPosition.getRow() ||
          (abs(nextPosition.getRow()) - abs(_currentPosition.getRow()) == 1)))
            return true;
        return false;
}
