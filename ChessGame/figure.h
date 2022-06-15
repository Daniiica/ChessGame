#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "figurecolor.h"
#include "figurename.h"
#include "field.h"


class Figure
{
protected:
    FigureColor _color;
    FigureName _type;
    Field _currentPosition;
    bool _state;
public:
    Figure() = default;
    virtual bool isValidFigureMove(Field nextPosition);
    Figure getFigure();
};


#endif // FIGURE_H
