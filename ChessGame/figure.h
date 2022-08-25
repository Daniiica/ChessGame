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
#include <algorithm>
#include "moveresultvalue.h"
#include "textlogger.h"
#include "inputResultValue.h"

class Figure
{
protected:
    FigureColor _color;
    FigureName _type;
    Field* _currentPositionPtr;
    bool _state = true;
public:
    Figure() = default;
    Figure(FigureColor color);
    Figure(FigureColor color, FigureName type, Field* currentPositionPtr);
    Field* getCurrentPosition();
    FigureName getType();
    std::string getTypeString();
    FigureColor getColor();
    FigureColor getOtherColor();
    bool getState();
    std::string getName();
    void setActiveState();
    void setEatenState();
    void setCurrentPosition(Field* positionPtr);
    int countPositionBetweenCurrentAndNextPosition(Field nextPosition);
    static MoveResultValue invalidStartFigure(Field* startFieldPtr,
                                              Figure* figureOnFieldPtr, FigureColor color);
    static MoveResultValue invalidEndFigure(Figure* startFigurePtr, Figure* endFigurePtr);
    bool isFigureOnEndTable(Field nextPosition);
    static void setInitialValues(Field* currentPositionPtr,
                                 int& rowInitialValue, int& colInitialValue);
    std::pair<int,int> getCurrentPositionPair();
    virtual bool isValidFigureMove(Field startPosition,Field nextPosition) = 0;
    virtual std::vector<std::pair<int,int>>
                allPositionsBetweenCurrentAndNextPosition(Field nextPosition) = 0;
    virtual std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) = 0;
    bool operator==(const Figure &rhs) const;
    virtual ~Figure();
    void deleteCurrentPositionPtr();
};


#endif // FIGURE_H
