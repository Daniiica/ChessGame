#include "knightfigure.h"

KnightFigure::KnightFigure()
{
    _type = FigureName::knight;
    _state = true;
}

KnightFigure::KnightFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::knight;
    _state = true;
}

bool KnightFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
    int currentPositionCol = startPosition.getCol();
    int currentPositionRow = startPosition.getRow();
    int nextPositionCol = nextPosition.getCol();
    int nextPositionRow = nextPosition.getRow();

    return (((abs(currentPositionCol - nextPositionCol) == 2) &&
             (abs(currentPositionRow - nextPositionRow) == 1)) ||
            ((abs(currentPositionCol - nextPositionCol) == 1) &&
             (abs(currentPositionRow - nextPositionRow) == 2)));
}

std::vector<std::pair<int,int>> KnightFigure::allPositionsBetweenCurrentAndNextPosition(
        Field nextPosition)
{
    std::vector<std::pair<int,int>> allPositions(0);
    return allPositions;
}

void KnightFigure::fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                    FigureColor color,
                                    std::vector<std::pair<int,int>>& allowedMoves,
                                    int initialRowValue, int initialColValue)
{
    std::pair<int,int> position;
    position.first = initialRowValue;
    position.second = initialColValue;
    for(auto figure : figuresOnTable)
    {
        if(figure->getCurrentPositionPair() == position)
        {
            if(figure->getColor() != color)
            {
                allowedMoves.emplace_back(initialRowValue, initialColValue);
            }
            return;
        }
    }
    allowedMoves.emplace_back(initialRowValue, initialColValue);
}

std::vector<std::pair<int,int>> KnightFigure::allAllowedMoves(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allowedMoves;

    int initialRowValue;
    int initialColValue;
    setInitialValues(_currentPosition,initialRowValue,initialColValue);

    for(int i = 1 ; i < 3 ; i++)
    {
        for(int j = 1 ; j < 3 ; j++)
        {
            if(i != j)
            {
                if(initialRowValue + i < 8)
                {
                    if(initialColValue + j < 8)
                    {
                        fillAllowedMoves(figuresOnTable, _color, allowedMoves,
                                         initialRowValue + i,initialColValue + j);
                    }
                    if(initialColValue - j >= 0)
                    {
                        fillAllowedMoves(figuresOnTable, _color, allowedMoves,
                                         initialRowValue + i,initialColValue - j);
                    }
                }
                if(initialRowValue - i >= 0)
                {
                    if(initialColValue + j < 8)
                    {
                        fillAllowedMoves(figuresOnTable,_color, allowedMoves,
                                         initialRowValue - i,initialColValue + j);
                    }
                    if(initialColValue - j >= 0)
                    {
                        fillAllowedMoves(figuresOnTable, _color, allowedMoves,
                                         initialRowValue - i,initialColValue - j);
                    }
                }
            }
        }
    }
    return allowedMoves;
}
