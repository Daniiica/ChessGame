#ifndef BISHOPFIGURE_H
#define BISHOPFIGURE_H

#include "figure.h"


class BishopFigure : public Figure
{
public:
    BishopFigure();
    BishopFigure(FigureColor color);
    BishopFigure(FigureColor color, Field* currentPosition) :
        Figure(color, FigureName::bishop,currentPosition) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
    std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) override;
    static void fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                 FigureColor color,
                                 std::vector<std::pair<int,int>>* allowedMoves,
                                 int& initialPositionRow, int& initialPositionCol,
                                 int isUpOrDown,int isLeftOrRight);
    static bool isValidBishopMove(Field startPosition,Field nextPosition);
    static std::vector<std::pair<int,int>> allPositionsBetweenBishopAndNextPosition(
            Field* currentPosition,Field nextPosition);
    static std::vector<std::pair<int,int>> allAllowedBishopMoves(
            Field* currentPositions, std::vector<Figure*> figuresOnTable, FigureColor color);
};
#endif // BISHOPFIGURE_H
