#ifndef ROOKFIGURE_H
#define ROOKFIGURE_H

#include "figure.h"
#include <algorithm>
#include <vector>
//#include "queenfigure.h"

class RookFigure : public Figure
{
 //   friend class QueenFigure;
public:
    RookFigure();
    RookFigure(FigureColor color);
    RookFigure(FigureColor color, Field* currentPositionPtr) :
        Figure(color, FigureName::rook, currentPositionPtr) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
    std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) override;
    static bool isValidRookMove(Field startPosition, Field nextPosition);
    static void fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                 FigureColor color,
                          std::vector<std::pair<int,int>>* allowedMovesPtr,
                          int& initialPositionRow, int& initialPositionCol,
                          int isUpOrDown,int isLeftOrRight);
    static std::vector<std::pair<int,int>> allPositionsBetweenRookAndNextPosition(
            Field* currentPositionPtr, Field nextPosition);
    static std::vector<std::pair<int,int>> allAllowedRookMoves(
            Field* currentPositionsPtr, std::vector<Figure*> figuresOnTable, FigureColor color);
};

#endif // ROOKFIGURE_H
