#ifndef KNIGHTFIGURE_H
#define KNIGHTFIGURE_H

#include "figure.h"

class KnightFigure : public Figure
{

public:
    KnightFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // KNIGHTFIGURE_H
