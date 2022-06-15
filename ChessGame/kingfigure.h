#ifndef KINGFIGURE_H
#define KINGFIGURE_H

#include "figure.h"

class KingFigure : public Figure
{
public:
    KingFigure();
    figureName getName() override;
    void setName(figureName name) override;
};

#endif // KINGFIGURE_H
