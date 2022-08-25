#include "player.h"

Player::Player(FigureColor color)
    :_color{color},_allMoves(0)
{
}

std::string Player::getName()
{
    return _color == FigureColor::White ? "White" : "Black";
}

FigureColor Player::getColor()
{
    return _color;
}

bool Player::getCastlingLongStatus()
{
    return _castlingLongStatus;
}

bool Player::getCastlingShortStatus()
{
    return _castlingShortStatus;
}

void Player::disableCastlingStatus()
{
    _castlingLongStatus = false;
    _castlingShortStatus = false;
}

std::vector<Move> Player::getMovesFromPlayer()
{
    return _allMoves;
}

void Player::changeCastlingStatus(Figure* currentFigurePtr, Field* firstPositionPtr)
{
    if(currentFigurePtr->getType() == FigureName::king)
    {
        _castlingLongStatus = false;
        _castlingShortStatus = false;
    }
    if(currentFigurePtr->getType() == FigureName::rook)
    {
        if(firstPositionPtr->getCol() == 0)
            _castlingLongStatus = false;
        if(firstPositionPtr->getCol() == 7)
            _castlingShortStatus = false;
    }
}


