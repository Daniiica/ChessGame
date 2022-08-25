#ifndef MOVE_H
#define MOVE_H

#include "field.h"
#include "figure.h"
#include "moveresultvalue.h"
#include "textlogger.h"

class Move
{
private:
    Field _startPosition {};
    Field _endPosition {};
    Figure* _figurePtr {};
    Figure* _eatenFigurePtr {};
public:
    Move() = default;
    Move(Field startPosition, Field endPosition, Figure* figurePtr, Figure* eatenFigurePtr);
    bool isCastling();
    Figure* getKingFigureInMove();
    Figure* getRookFigureInMove();
    Figure* getEndFigure();
    Figure* getCurrentFigure();
    Field* getStartPosition();
    Field* getEndPosition();
    bool isCastlingAllowed();
    static MoveResultValue invalidMove();
    void setEndFigure(Figure* figurePtr);
    ~Move();
};
#endif // MOVE_H

