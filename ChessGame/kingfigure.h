#ifndef KINGFIGURE_H
#define KINGFIGURE_H

#include "figure.h"

class KingFigure : public Figure
{
private:
    std::vector<std::pair<int,int>> allPositionsBetweenCurrentAndNextPosition(
            Field nextPosition) override;
public:
    KingFigure();
    KingFigure(FigureColor color);
    KingFigure(FigureColor color, Field* currentPosition) :
        Figure(color, FigureName::king, currentPosition) {};
    bool isValidFigureMove(Field startPosition,Field nextPosition) override;

    std::vector<std::pair<int,int>> allAllowedMoves(std::vector<Figure*> figuresOnTable) override;
    void fillAllowedMoves(std::vector<Figure*> figuresOnTable, FigureColor color,
                          std::vector<std::pair<int,int>>& allowedMoves,
                          int initialPositionRow, int initialPositionCol);

};

#endif // KINGFIGURE_H
