#include "bishopfigure.h"

BishopFigure::BishopFigure()
{
    _type = FigureName::bishop;
    _state = true;
}
BishopFigure::BishopFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::bishop;
    _state = true;
}
bool BishopFigure::isValidFigureMove(Field nextPosition)
{
    if(abs(_currentPosition.getCol() - nextPosition.getCol()) == abs(_currentPosition.getRow() - nextPosition.getRow()))
        return true;
    return false;
}
std::map<int,int> BishopFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{
    std::map<int,int> indexOfFields;
    Field downPosition = nextPosition;
    Field topPosition = _currentPosition;
    Field leftPosition = nextPosition;
    Field rightPosition = _currentPosition;
    if(_currentPosition.getRow() < nextPosition.getRow())
    {
        downPosition = _currentPosition;
        topPosition = nextPosition;
    }
    if(_currentPosition.getCol() < nextPosition.getCol())
    {
        leftPosition = _currentPosition;
        rightPosition = nextPosition;
    }

    int downPositionRow = downPosition.getRow() + 1;
    int leftPositionCol = leftPosition.getCol() + 1;
    int rightPositionCol = rightPosition.getCol() - 1;
    while(downPositionRow < topPosition.getRow())
    {
        if(rightPosition == topPosition)
        {
            indexOfFields[downPositionRow++] = leftPositionCol++;
        }
        else
        {
            indexOfFields[downPositionRow++] = rightPositionCol--;
        }
    }
    return indexOfFields;
}
