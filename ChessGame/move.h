#ifndef MOVE_H
#define MOVE_H

#include "field.h"
#include "figure.h"
#include "table.h"

class Move
{
private:
    Field _startPosition;
    Field _endPosition;
    Figure* _figure;
    Figure* _eatenFigure;
public:
    Move();
    Move(Field startPosition, Field endPosition, Figure* figure, Figure* eatenFigure);
    bool isValidMove(Table table);
};

#endif // MOVE_H

