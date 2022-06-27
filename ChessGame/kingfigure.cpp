#include "kingfigure.h"

KingFigure::KingFigure()
{
    _type = FigureName::king;
    _state = true;
}
KingFigure::KingFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::king;
    _state = true;
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
std::map<int,int> KingFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{

}
