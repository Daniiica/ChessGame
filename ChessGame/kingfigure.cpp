#include "kingfigure.h"

KingFigure::KingFigure()
{
    _type = FigureName::king;
    _state = true;
}

KingFigure::KingFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::king;
    _state = true;
}

bool KingFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
    return ((nextPosition.getCol() == startPosition.getCol() ||
            (abs(nextPosition.getCol() - startPosition.getCol()) == 1)) &&
            (nextPosition.getRow() == startPosition.getRow() ||
             (abs(nextPosition.getRow() - startPosition.getRow()) == 1)));
}

std::vector<std::pair<int,int>> KingFigure::allPositionsBetweenCurrentAndNextPosition(
        Field nextPosition)
{
    std::vector<std::pair<int,int>> allPosition;
    return allPosition;
}

void KingFigure::fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                  FigureColor color,
                                  std::vector<std::pair<int,int>>& allowedMoves,
                                  int initialPositionRow, int initialPositionCol)
{
    std::pair<int,int> position;
    if(initialPositionRow >= 0 && initialPositionCol >=0 &&
            initialPositionRow <= 7 && initialPositionCol <= 7){
        position.first = initialPositionRow;
        position.second = initialPositionCol;

        for(auto figure : figuresOnTable)
        {
            if(figure->getCurrentPositionPair() == position)
            {
                if(figure->getColor() != color)
                {
                    allowedMoves.emplace_back(initialPositionRow, initialPositionCol);
                }
                return;
            }
        }
        allowedMoves.emplace_back(initialPositionRow, initialPositionCol);
    }
}

std::vector<std::pair<int,int>> KingFigure::allAllowedMoves(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allowedMoves;
    int initialPositionRow = getCurrentPosition()->getRow();
    int initialPositionCol = getCurrentPosition()->getCol();

    for(int i = -1 ; i <= 1 ; i++)
    {
        for(int j = -1 ; j <= 1 ; j++)
        {
            if(!(i == 0 && j == 0))
                fillAllowedMoves(figuresOnTable, _color, allowedMoves,
                                 initialPositionRow + i, initialPositionCol + j);
        }
    }
    return allowedMoves;
}


