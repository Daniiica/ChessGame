#ifndef PAWNFIGURE_H
#define PAWNFIGURE_H

#include "figure.h"

class PawnFigure : public Figure
{
public:
    PawnFigure();
    PawnFigure(FigureColor color);
    PawnFigure(FigureColor color, Field* currentPosition) :
        Figure(color, FigureName::pawn, currentPosition) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
    bool eatOrNotEatFigure(Field nextPosition);
    std::vector<std::pair<int,int>> allAllowedMoves(
            std::vector<Figure*> figuresOnTable) override;
    static bool checkPawnMove(Field* startPosition, Field* endPosition,
                              Figure* figureOnEndPosition, FigureColor color);
    void addAllowedPositionWhenNotEat(std::vector<Figure*> figuresOnTable,
                                 std::vector<std::pair<int,int>>& allowedMoves);
    void addAllowedPositionWhenEat(std::vector<Figure*> figuresOnTable,
                                 std::vector<std::pair<int,int>>& allowedMoves);
};

#endif // PAWNFIGURE_H
