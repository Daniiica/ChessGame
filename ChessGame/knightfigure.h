#ifndef KNIGHTFIGURE_H
#define KNIGHTFIGURE_H

#include "figure.h"

class KnightFigure : public Figure
{

public:
    KnightFigure();
    KnightFigure(FigureColor color);
    KnightFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::knight, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) override;
};

#endif // KNIGHTFIGURE_H
