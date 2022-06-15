#ifndef PAWNFIGURE_H
#define PAWNFIGURE_H

#include "figure.h"

class PawnFigure : public Figure
{
public:
    PawnFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // PAWNFIGURE_H
