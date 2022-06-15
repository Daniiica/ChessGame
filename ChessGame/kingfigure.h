#ifndef KINGFIGURE_H
#define KINGFIGURE_H

#include "figure.h"

class KingFigure : public Figure
{
public:
    KingFigure();
    bool isValidFigureMove(Field nextPosition) override;
};

#endif // KINGFIGURE_H
