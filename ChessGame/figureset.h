#ifndef FIGURESET_H
#define FIGURESET_H

#include "figurecolor.h"
#include "figure.h"
#include <vector>

class FigureSet
{
private:
    std::vector<Figure> _setfigures;
    FigureColor _setColor;
public:
    FigureSet();
};

#endif // FIGURESET_H
