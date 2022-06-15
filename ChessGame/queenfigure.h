#ifndef QUEENFIGURE_H
#define QUEENFIGURE_H

#include "figure.h"
#include "rookfigure.h"
#include "bishopfigure.h"

class QueenFigure : public Figure
{
public:
    QueenFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // QUEENFIGURE_H
