#include "move.h"

Move::Move(Field startPosition, Field endPosition, Figure* figure, Figure* eatenFigure)
    :_startPosition{ startPosition }, _endPosition{ endPosition },
      _figure{ figure }, _eatenFigure{ eatenFigure }
{
}

Move::~Move()
{
    _figure = nullptr;
    _eatenFigure = nullptr;

}
Figure* Move::getEndFigure()
{
    return _eatenFigure;
}

Figure* Move::getCurrentFigure()
{
    return _figure;
}

Field* Move::getStartPosition()
{
    return &_startPosition;
}


Field* Move::getEndPosition()
{
    return &_endPosition;
}

void Move::setEndFigure(Figure* figurePtr)
{
    _eatenFigure = figurePtr;
}

Figure* Move::getKingFigureInMove()
{
    return _figure->getType() == FigureName::king ? _figure : _eatenFigure;
}

Figure* Move::getRookFigureInMove()
{
    return _figure->getType() == FigureName::rook ? _figure : _eatenFigure;
}

bool Move::isCastlingAllowed()
{
    FigureName firstFigureType = _figure->getType();
    FigureName secondFigureType = _eatenFigure->getType();

    if ((firstFigureType != FigureName::king && firstFigureType != FigureName::rook) ||
            (secondFigureType != FigureName::king && secondFigureType != FigureName::rook))
    {
        return false;
    }
    if (_figure->getColor() != _eatenFigure->getColor())
    {
        return false;
    }
    return true;
}

MoveResultValue Move::invalidMove()
{
    TextLogger::logWarning("Move is not valid.");
    return MoveResultValue::notValidMove;
}

bool Move::isCastling()
{
    if(getEndFigure() != nullptr && isCastlingAllowed())
        return true;
    return false;
}
