#ifndef KNIGHTFIGURE_H
#define KNIGHTFIGURE_H

#include "figure.h"

class KnightFigure : public Figure
{
private:
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
public:
    KnightFigure();
    KnightFigure(FigureColor color);
    KnightFigure(FigureColor color, Field* currentPosition) :
        Figure(color, FigureName::knight, currentPosition) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;

    std::vector<std::pair<int,int>> allAllowedMoves(std::vector<Figure*> figuresOnTable) override;
    void fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                          FigureColor color,
                          std::vector<std::pair<int,int>>& allowedMoves,
                          int initialPositionRow, int initialPositionCol);
};

#endif // KNIGHTFIGURE_H
