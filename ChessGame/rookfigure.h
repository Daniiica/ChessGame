#ifndef ROOKFIGURE_H
#define ROOKFIGURE_H

#include "figure.h"

class RookFigure : public Figure
{
public:
    RookFigure();
    RookFigure(FigureColor color);
    RookFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::rook, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) override;
};

#endif // ROOKFIGURE_H
