#ifndef FIGURESET_H
#define FIGURESET_H

#include "figurecolor.h"
#include "figure.h"
#include "kingfigure.h"
#include "queenfigure.h"
#include "bishopfigure.h"
#include "rookfigure.h"
#include "pawnfigure.h"
#include "knightfigure.h"
#include <vector>

class FigureSet
{
private:
    std::vector<Figure*> _setfigures;
    FigureColor _setColor;
public:
    FigureSet() = default;
    FigureSet(FigureColor color);
    FigureSet(std::vector<Figure*> figures);
    Figure* figureOnPosition(Field position);
    void removeEatenFigure(Figure* eatenFigure);
    void editFigure(Figure* figure);
    void setColor(FigureColor color);
    Figure* getFigureOnPosition(Field position);
    std::vector<Figure*> getFigures();
    void addFigure(Figure* newFigure);
    void initializeFiguresOnStart(FigureColor color);
};

#endif // FIGURESET_H
