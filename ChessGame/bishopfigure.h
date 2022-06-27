#ifndef BISHOPFIGURE_H
#define BISHOPFIGURE_H

#include "figure.h"

class BishopFigure : public Figure
{
public:
    BishopFigure();
    BishopFigure(FigureColor color);
    BishopFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::bishop, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) override;
    BishopFigure(FigureColor color, FigureName type, Field currentPosition, bool state) : Figure(color, type, currentPosition, state) {};
};

#endif // BISHOPFIGURE_H
