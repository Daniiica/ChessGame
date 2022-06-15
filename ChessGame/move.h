#ifndef MOVE_H
#define MOVE_H

#include "field.h"
#include "figure.h"
#include "table.h"

class Move
{
private:
    Figure* _figure;
    Field* _nextMove;
    Table* _table;
public:
    Move();
    Move(Figure* figure, Field* nextMove, Table* table);
    bool checkMove();
    bool checkMoveKing(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool checkMoveRook(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool checkMoveBishop(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool checkMoveQueen(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool checkMoveKnight(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool checkMovePawn(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow);
    bool makeMove();
    void changePositionsOnTable();
};

#endif // MOVE_H

