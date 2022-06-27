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
    QueenFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::queen, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPositions) override;
};

#endif // QUEENFIGURE_H
