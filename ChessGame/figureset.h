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
#include <memory>
#include "textlogger.h"

class FigureSet
{
private:
    std::vector<Figure*> _setfigures;
    FigureColor _setColor;
public:
    FigureSet() = default;
    Figure* figureOnPosition(Field position);
    void setColor(FigureColor color);
    std::vector<Figure*> getFiguresWithoutKing();
    std::vector<Figure*> getAllFigures();
    void addFigure(Figure* newFigure);
    void initializeFiguresOnStart(std::vector<Figure*> allFigures);
    std::vector<std::pair<int,int>> allAllowedMovesForOneFigureSet(std::vector<Figure*> figuresOnTable);
    void changePawnWithOtherFigure(Figure** pawnFigure);
    void replaceFigure(Figure** pawnFigure, Figure* newFigure);
    void deleteFigure(Figure* figureOnEndPosition);
};

#endif // FIGURESET_H
