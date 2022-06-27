#include "pawnfigure.h"

PawnFigure::PawnFigure()
{
    _type = FigureName::pawn;
    _state = true;
}

PawnFigure::PawnFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::pawn;
    _state = true;
}

bool PawnFigure::eatOrNotEatFigure(Field nextPosition)
{
    if(this->_color == FigureColor::White &&
            nextPosition.getRow() == _currentPosition.getRow() + 1 &&
            abs(nextPosition.getCol() - _currentPosition.getCol()) == 1)
    {
        return true;
    }
    if(this->_color == FigureColor::Black &&
            _currentPosition.getRow() == nextPosition.getRow() + 1 &&
            abs(nextPosition.getCol() - _currentPosition.getCol()) == 1)
    {
        return true;
    }
    return false;
}

bool PawnFigure::isValidFigureMove(Field nextPosition)
{
    if(this->_color == FigureColor::White && nextPosition.getRow() > _currentPosition.getRow())
    {
        if(nextPosition.getRow() <= static_cast<int>(WhiteBlackZone::whiteZoneEndRow) && nextPosition.getRow() - _currentPosition.getRow() <= 2)
        {
            return true;
        }
        if(nextPosition.getRow() > static_cast<int>(WhiteBlackZone::blackZoneStartRow) && nextPosition.getRow() - _currentPosition.getRow() == 1)
        {
            return true;
        }
    }
    if(this->_color == FigureColor::Black && nextPosition.getRow() < _currentPosition.getRow())
    {
        if(nextPosition.getRow() >= static_cast<int>(WhiteBlackZone::blackZoneEndRow) && _currentPosition.getRow() - nextPosition.getRow() <= 2)
        {
            return true;
        }
        if(nextPosition.getRow() < static_cast<int>(WhiteBlackZone::blackZoneStartRow) && _currentPosition.getRow() - nextPosition.getRow() == 1)
        {
            return true;
        }
    }
    eatOrNotEatFigure(nextPosition);
    return false;
}

std::map<int,int> PawnFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{
    std::map<int,int> indexOfFields;
    int minRow = _currentPosition.getRow();
    int diff = abs(_currentPosition.getRow() - nextPosition.getRow());
    for(int i = 0; i < diff ; i++)
    {
        if(this->getColor() == FigureColor::White)
        indexOfFields[minRow++] = _currentPosition.getCol();
        else
            indexOfFields[minRow--] = _currentPosition.getCol();
    }
    return indexOfFields;
}
