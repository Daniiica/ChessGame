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
            nextPosition.getRow() == _currentPosition->getRow() + 1 &&
            abs(nextPosition.getCol() - _currentPosition->getCol()) == 1)
    {
        return true;
    }
    if(this->_color == FigureColor::Black &&
            _currentPosition->getRow() == nextPosition.getRow() + 1 &&
            abs(nextPosition.getCol() - _currentPosition->getCol()) == 1)
    {
        return true;
    }
    return false;
}

bool PawnFigure::checkPawnMove(Field* startPosition, Field* endPosition, Figure* figureOnEndPosition, FigureColor color)
{
    if (abs(startPosition->getCol() - endPosition->getCol()) == 1)
    {
        if (figureOnEndPosition == nullptr ||
                (figureOnEndPosition->getColor() == color))
            return false;
    }
    else
    {
        if (figureOnEndPosition != nullptr)
        {
            return false;
        }
    }
    return true;
}

bool PawnFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
    if(this->_color == FigureColor::White && nextPosition.getRow() > startPosition.getRow())
    {
        if((nextPosition.getRow() <= static_cast<int>(WhiteBlackZone::whiteZoneEndRow) &&
                nextPosition.getRow() - startPosition.getRow() <= 2) ||
                (nextPosition.getRow() > static_cast<int>(WhiteBlackZone::whiteZoneEndRow) &&
                                nextPosition.getRow() - startPosition.getRow() == 1))
        {
            return true;
        }
    }
    if(this->_color == FigureColor::Black && nextPosition.getRow() < startPosition.getRow())
    {
        if((nextPosition.getRow() >= static_cast<int>(WhiteBlackZone::blackZoneEndRow) &&
                startPosition.getRow() - nextPosition.getRow() <= 2) ||
                (nextPosition.getRow() < static_cast<int>(WhiteBlackZone::blackZoneStartRow) &&
                                startPosition.getRow() - nextPosition.getRow() == 1))
        {
            return true;
        }
    }
    return eatOrNotEatFigure(nextPosition);
}

std::vector<std::pair<int,int>> PawnFigure::allPositionsBetweenCurrentAndNextPosition(
        Field nextPosition)
{
    std::vector<std::pair<int,int>> indexOfFields;
    int minRow = _currentPosition->getRow();
    int diff = abs(_currentPosition->getRow() - nextPosition.getRow());
    for(int i = 1; i < diff ; i++)
    {
        if(this->getColor() == FigureColor::White)
            indexOfFields.emplace_back(++minRow,_currentPosition->getCol());
        else
            indexOfFields.emplace_back(--minRow,_currentPosition->getCol());
    }
    return indexOfFields;
}

std::vector<std::pair<int,int>> PawnFigure::allAllowedMoves(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allowedMoves(0);

    addAllowedPositionWhenNotEat(figuresOnTable,allowedMoves);
    addAllowedPositionWhenEat(figuresOnTable,allowedMoves);

    return allowedMoves;
}

void PawnFigure::addAllowedPositionWhenNotEat(std::vector<Figure*> figuresOnTable,
                                              std::vector<std::pair<int,int>>& allowedMoves)
{
    std::pair<int,int> nextMove;
    nextMove.first = _currentPosition->getRow();
    nextMove.second = _currentPosition->getCol();
    int index = _color == FigureColor::White ? 1 : -1;
    auto boundaryRow = _color == FigureColor::White ?
                static_cast<int>(WhiteBlackZone::whiteZoneStartRow) :
                static_cast<int>(WhiteBlackZone::blackZoneStartRow) ;

    for(int i = 1 ; i <= 2 ; i++)
    {
        nextMove.first += index;
        if(i == 2 && _currentPosition->getRow() != boundaryRow + index)
            return;
        for(auto figure : figuresOnTable)
        {
            if(figure->getCurrentPositionPair() == nextMove)
            {
                return;
            }
        }
        allowedMoves.push_back(nextMove);
    }
}

void PawnFigure::addAllowedPositionWhenEat(std::vector<Figure*> figuresOnTable,
                                           std::vector<std::pair<int,int>>& allowedMoves)
{
    std::pair<int,int> nextMove;
    int index = _color == FigureColor::White ? 1 : -1;
    nextMove.first = _currentPosition->getRow() + index;

    for(int i = -1 ; i <= 1 ; i = i + 2){

        nextMove.second = _currentPosition->getCol() + i;
        if(nextMove.second < 0 || nextMove.second > 7)
        {
            nextMove.second = _currentPosition->getCol();
            continue;
        }
        for(auto figure : figuresOnTable)
        {
            if(figure->getCurrentPositionPair() == nextMove)
            {
                if(figure->getColor() != _color)
                {
                    allowedMoves.push_back(nextMove);
                }
                break;
            }
        }
    }
}
