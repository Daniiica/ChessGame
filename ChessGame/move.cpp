#include "move.h"
Move::Move()
{
   // _eatenFigure
}
bool Move::isValidMove()
{
    _figure.isValidFigureMove(_endPosition);
}
