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
#include "move.h"

class FigureSet
{
private:
    std::vector<Figure*> _setfigures;
    FigureColor _setColor;
public:
    FigureSet() = default;
    Figure* figureOnPosition(Field position);
    void setColor(FigureColor color);
    FigureColor getColor();
    void setFigures(std::vector<Figure*> allFigures);
    std::vector<Figure*> getFiguresWithoutKing();
    std::vector<Figure*> getAllFigures();
    void addFigure(Figure* newFigurePtr);
    void initializeFiguresOnStart(std::vector<Figure*> allFigures);
    std::vector<std::pair<int,int>> allAllowedMovesForOneFigureSet(std::vector<Figure*> figuresOnTable);
    void changePawnWithOtherFigure(Move& move);
    void replaceFigure(Figure& pawnFigurePtr, Figure* newFigurePtr);
    void deleteFigure(Figure* figureOnEndPositionPtr);
    Figure* createFigure(std::string replaceFigureName, FigureColor color, Field* positionPtr);
    void deleteFigures();
};

#endif // FIGURESET_H
