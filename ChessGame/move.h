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
    Figure* _figure {};
    Figure* _eatenFigure {};
public:
    Move() = default;
    Move(Field startPosition, Field endPosition, Figure* figure, Figure* eatenFigure);
    //MoveResultValue isValidMove(Table& table);
    static void setFigure(Figure* figure);
    bool isCastling();
    Figure* getKingFigureInMove();
    Figure* getRookFigureInMove();
    Figure* getEndFigure();
    Figure* getCurrentFigure();
    Field* getStartPosition();
    Field* getEndPosition();
    void undoMove(Field& startPosition,  Figure* currentFigure, Figure* eatenFigure);
    bool checkIsPositionAttack(std::pair<int,int> position,
                               std::vector<Figure*> allFigures,
                               FigureColor color,
                               int& howMuchFiguresAttackKing,
                               Figure** figureWhoAttackKing);
    bool isCastlingAllowed();
    static MoveResultValue invalidMove();
    void setEndFigure(Figure* figurePtr);
    ~Move();
};
#endif // MOVE_H

