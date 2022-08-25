#ifndef BISHOPFIGURE_H
#define BISHOPFIGURE_H

#include "figure.h"


class BishopFigure : public Figure
{
public:
    BishopFigure();
    BishopFigure(FigureColor color);
    BishopFigure(FigureColor color, Field* currentPositionPtr) :
        Figure(color, FigureName::bishop,currentPositionPtr) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
    std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) override;
    static void fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                 FigureColor color,
                                 std::vector<std::pair<int,int>>* allowedMovesPtr,
                                 int& initialPositionRow, int& initialPositionCol,
                                 int isUpOrDown,int isLeftOrRight);
    static bool isValidBishopMove(Field startPosition,Field nextPosition);
    static std::vector<std::pair<int,int>> allPositionsBetweenBishopAndNextPosition(
            Field* currentPositionPtr,Field nextPosition);
    static std::vector<std::pair<int,int>> allAllowedBishopMoves(
            Field* currentPositionsPtr, std::vector<Figure*> figuresOnTable, FigureColor color);
};
#endif // BISHOPFIGURE_H
