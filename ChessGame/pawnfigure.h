#ifndef PAWNFIGURE_H
#define PAWNFIGURE_H

#include "figure.h"

class PawnFigure : public Figure
{
public:
    PawnFigure();
    PawnFigure(FigureColor color);
    PawnFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::pawn, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) override;
    bool eatOrNotEatFigure(Field nextPosition);
};

#endif // PAWNFIGURE_H
