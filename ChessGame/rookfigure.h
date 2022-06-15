#ifndef ROOKFIGURE_H
#define ROOKFIGURE_H

#include "figure.h"

class RookFigure : public Figure
{
public:
    RookFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // ROOKFIGURE_H
