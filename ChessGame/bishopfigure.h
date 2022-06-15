#ifndef BISHOPFIGURE_H
#define BISHOPFIGURE_H

#include "figure.h"

class BishopFigure : public Figure
{
public:
    BishopFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // BISHOPFIGURE_H
