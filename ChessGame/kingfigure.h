#ifndef KINGFIGURE_H
#define KINGFIGURE_H

#include "figure.h"

class KingFigure : public Figure
{
public:
    KingFigure();
    KingFigure(FigureColor color);
    KingFigure(FigureColor color, Field currentPosition) : Figure(color, FigureName::king, currentPosition, true) {};
    bool isValidFigureMove(Field nextPosition) override;
    std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) override;
};

#endif // KINGFIGURE_H
