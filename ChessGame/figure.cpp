#include "figure.h"

Figure::Figure(FigureColor color, FigureName type, Field* currentPosition)
    :_color{color},_type{type},_currentPosition{currentPosition}
{
}

Figure::Figure(FigureColor color)
    :_color{color}
{
}

std::string Figure::getName()
{
    char firstLetter= ' ';
    char secondLetter = ' ';
    std::string name;

    if(_color == FigureColor::White)
    {
        firstLetter = 'W';
    }
    else
    {
        firstLetter = 'B';
    }
    if(_type == FigureName::bishop)
    {
        secondLetter = 'B';
    }
    if(_type == FigureName::rook)
    {
        secondLetter = 'R';
    }
    if(_type == FigureName::knight)
    {
        secondLetter = 'N';
    }
    if(_type == FigureName::king)
    {
        secondLetter = 'K';
    }
    if(_type == FigureName::queen)
    {
        secondLetter = 'Q';
    }
    if(_type == FigureName::pawn)
    {
        secondLetter = 'P';
    }
    name = firstLetter;
    name += secondLetter;
    return name;
}

Field* Figure::getCurrentPosition()
{
    return _currentPosition;
}

FigureName Figure::getType()
{
    return _type;
}

std::string Figure::getTypeString()
{
    if(_type == FigureName::rook)
        return "rook";
    if(_type == FigureName::knight)
        return "knight";
    if(_type == FigureName::bishop)
        return "bishop";
    if(_type == FigureName::king)
        return "king";
    if(_type == FigureName::queen)
        return "queen";
    if(_type == FigureName::pawn)
        return "pawn";
    return "";
}

FigureColor Figure::getColor()
{
    return _color;
}

FigureColor Figure::getOtherColor()
{
    if(_color == FigureColor::Black)
        return FigureColor::White;
    else
        return FigureColor::Black;
}

bool Figure::getState()
{
    return _state;
}

void Figure::setCurrentPosition(Field* position)
{
    _currentPosition = position;
}

std::pair<int,int> Figure::getCurrentPositionPair()
{
    std::pair<int,int> position;
    position.first = _currentPosition->getRow();
    position.second = _currentPosition->getCol();
    return position;
}

void Figure::setActiveState()
{
    _state = true;
}

void Figure::setEatenState()
{
    _state = false;
}

bool Figure::operator==(const Figure &rhs) const
{
    if(_color == rhs._color && _currentPosition == rhs._currentPosition
            && _type == rhs._type && _state == rhs._state)
    {
        return true;
    }
    return false;
}

void Figure::setInitialValues(Field* currentPosition, int& rowInitialValue, int& colInitialValue)
{
    rowInitialValue = currentPosition->getRow();
    colInitialValue = currentPosition->getCol();
}

bool Figure::isFigureOnEndTable(Field nextPosition)
{
    if (_color == FigureColor::White) {
        if (nextPosition.getRow() == static_cast<int>(WhiteBlackZone::blackZoneStartRow))
            return true;
    }
    else
    {
        if (nextPosition.getRow() == static_cast<int>(WhiteBlackZone::whiteZoneStartRow))
            return true;
    }
    return false;
}

int Figure::countPositionBetweenCurrentAndNextPosition(Field nextPosition)
{
    auto positions = this->allPositionsBetweenCurrentAndNextPosition(nextPosition);
    return positions.size();
}

MoveResultValue Figure::invalidStartFigure(Field* startField,
                                           Figure* figureOnField, FigureColor color)
{
    auto startPosition = startField->getPosition();
    if(figureOnField == nullptr)
    {
        TextLogger::logWarning("There is no figure on position " +
                               startPosition + ".");
        return MoveResultValue::notValidMove;
    }

    if(figureOnField->getColor() != color)
    {
        TextLogger::logWarning("The opponent's figure is on position " +
                               startPosition + ".");
        return MoveResultValue::notValidMove;
    }
    return MoveResultValue::validMove;
}

MoveResultValue Figure::invalidEndFigure(Figure* startFigure,
                                        Figure* endFigure)
{
    if (endFigure != nullptr && endFigure->getColor() == startFigure->getColor())
    {
        TextLogger::logWarning("Your figure is on end position.");
        return MoveResultValue::notValidMove;
    }
    return MoveResultValue::validMove;
}
