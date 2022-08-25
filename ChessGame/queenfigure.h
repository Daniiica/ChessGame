#ifndef QUEENFIGURE_H
#define QUEENFIGURE_H

#include "figure.h"
#include "rookfigure.h"
#include "bishopfigure.h"

class QueenFigure : public Figure
{
public:
    QueenFigure();
    QueenFigure(FigureColor color);
    QueenFigure(FigureColor color, Field* currentPositionPtr) :
        Figure(color, FigureName::queen, currentPositionPtr) {};
    bool isValidFigureMove(Field startPosition, Field nextPosition) override;
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPositions) override;
    std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) override;
};

#endif // QUEENFIGURE_H
