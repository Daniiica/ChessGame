#include "rookfigure.h"

RookFigure::RookFigure()
{
    _type = FigureName::rook;
    _state = true;
}
RookFigure::RookFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::rook;
    _state = true;
}
bool RookFigure::isValidFigureMove(Field nextPosition)
{
    if(_currentPosition.getCol() == nextPosition.getCol() ||
            _currentPosition.getRow() == nextPosition.getRow())
        return true;
    return false;
}
std::map<int,int> RookFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{
    std::map<int,int> indexOfFields;
    if(_currentPosition.getCol() == nextPosition.getCol())
    {
        int topPosition = _currentPosition.getRow() > nextPosition.getRow() ? _currentPosition.getRow() : nextPosition.getRow();
        int bottomPosition = topPosition == _currentPosition.getRow() ? nextPosition.getRow() : _currentPosition.getRow();
        for(int i = bottomPosition + 1 ; i < topPosition ; i++)
        {
            indexOfFields[i] = _currentPosition.getCol();
        }
    }
    if(_currentPosition.getRow() == nextPosition.getRow())
    {
        int leftPosition = _currentPosition.getCol() > nextPosition.getCol() ? nextPosition.getCol() : _currentPosition.getCol();
        int rightPosition = leftPosition == _currentPosition.getCol() ? nextPosition.getCol() : _currentPosition.getCol();
        for(int i = leftPosition +1 ; i < rightPosition ; i++)
        {
            indexOfFields[_currentPosition.getRow()] = i;
        }
    }
    return indexOfFields;
}
