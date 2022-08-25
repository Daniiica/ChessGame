#include "move.h"

Move::Move(Field startPosition, Field endPosition, Figure* figurePtr, Figure* eatenFigurePtr)
    :_startPosition{ startPosition }, _endPosition{ endPosition },
      _figurePtr{ figurePtr }, _eatenFigurePtr{ eatenFigurePtr }
{
}

Move::~Move()
{
    _figurePtr = nullptr;
    _eatenFigurePtr = nullptr;

}
Figure* Move::getEndFigure()
{
    return _eatenFigurePtr;
}

Figure* Move::getCurrentFigure()
{
    return _figurePtr;
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
    _eatenFigurePtr = figurePtr;
}

Figure* Move::getKingFigureInMove()
{
    return _figurePtr->getType() == FigureName::king ? _figurePtr : _eatenFigurePtr;
}

Figure* Move::getRookFigureInMove()
{
    return _figurePtr->getType() == FigureName::rook ? _figurePtr : _eatenFigurePtr;
}

bool Move::isCastlingAllowed()
{
    FigureName firstFigureType = _figurePtr->getType();
    FigureName secondFigureType = _eatenFigurePtr->getType();

    if ((firstFigureType != FigureName::king && firstFigureType != FigureName::rook) ||
            (secondFigureType != FigureName::king && secondFigureType != FigureName::rook))
    {
        return false;
    }
    if (_figurePtr->getColor() != _eatenFigurePtr->getColor())
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
    return (getEndFigure() != nullptr && isCastlingAllowed());
}
