#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "figurecolor.h"
#include "figurename.h"
#include "field.h"
#include <map>
#include "whiteblackzone.h"

class Figure
{
protected:
    FigureColor _color;
    FigureName _type;
    Field _currentPosition;
    bool _state = true;
public:
    Figure() = default;
    Figure(FigureColor color);
    Figure(FigureColor color, FigureName type, Field currentPosition, bool state);
    virtual bool isValidFigureMove(Field nextPosition) = 0;
    virtual std::map<int,int> allPositionsBetweenCurrentAndNextPosition(Field nextPosition) = 0;
    Field getCurrentPosition();
    FigureName getType();
    FigureColor getColor();
    void setActiveState();
    void setEatenState();
    void setCurrentPosition(Field position);
    bool operator==(const Figure &rhs) const;
    virtual ~Figure() = default;
};


#endif // FIGURE_H
