#include "bishopfigure.h"

BishopFigure::BishopFigure()
{
    _type = FigureName::bishop;
    _state = true;
}

BishopFigure::BishopFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::bishop;
    _state = true;
}

bool BishopFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
    return isValidBishopMove(startPosition,nextPosition);
}

bool BishopFigure::isValidBishopMove(Field startPosition, Field nextPosition)
{
    return abs(startPosition.getCol() - nextPosition.getCol()) ==
            abs(startPosition.getRow() - nextPosition.getRow());
}

std::vector<std::pair<int,int>> BishopFigure::allPositionsBetweenCurrentAndNextPosition(
        Field nextPosition)
{
    return allPositionsBetweenBishopAndNextPosition(_currentPosition,nextPosition);
}

std::vector<std::pair<int,int>> BishopFigure::allPositionsBetweenBishopAndNextPosition(
        Field* currentPosition,Field nextPosition)
{
    std::vector<std::pair<int,int>> indexOfFields;
    Field downPosition = nextPosition;
    Field topPosition = *currentPosition;
    Field leftPosition = nextPosition;
    Field rightPosition = *currentPosition;
    if(currentPosition->getRow() < nextPosition.getRow())
    {
        downPosition = *currentPosition;
        topPosition = nextPosition;
    }
    if(currentPosition->getCol() < nextPosition.getCol())
    {
        leftPosition = *currentPosition;
        rightPosition = nextPosition;
    }

    int downPositionRow = downPosition.getRow() + 1;
    int leftPositionCol = leftPosition.getCol() + 1;
    int rightPositionCol = rightPosition.getCol() - 1;
    while(downPositionRow < topPosition.getRow())
    {
        if(rightPosition == topPosition)
        {
            indexOfFields.emplace_back(downPositionRow++,leftPositionCol++);
        }
        else
        {
            indexOfFields.emplace_back(downPositionRow++,rightPositionCol--);
        }
    }
    return indexOfFields;
}
void BishopFigure::fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                    FigureColor color,
                                    std::vector<std::pair<int,int>>* allowedMoves,
                                    int& initialPositionRow, int& initialPositionCol, // da ova 2 budu kao 1 pair
                                    int isUpOrDown, int isLeftOrRight) // i ova 2 kao jedan pair
{
    while((initialPositionRow + isUpOrDown >= 0) && (initialPositionCol + isLeftOrRight >= 0) &&
          (initialPositionRow + isUpOrDown <= 7) && (initialPositionCol + isLeftOrRight <= 7))
    {
        std::pair<int,int> pairRowCol(initialPositionRow + isUpOrDown,
                                      initialPositionCol + isLeftOrRight);
        for(auto figure : figuresOnTable)
        {
            if(figure->getCurrentPositionPair() == pairRowCol)
            {
                if(figure->getColor() != color)
                {
                    allowedMoves->emplace_back(pairRowCol);
                }
                return;
            }
        }
        allowedMoves->emplace_back(initialPositionRow + isUpOrDown,
                                   initialPositionCol + isLeftOrRight);
        initialPositionRow += isUpOrDown;
        initialPositionCol += isLeftOrRight;
    }
}

std::vector<std::pair<int,int>> BishopFigure::allAllowedMoves(std::vector<Figure*>
                                                              figuresOnTable)
{
    return allAllowedBishopMoves(_currentPosition,figuresOnTable, _color);
}

std::vector<std::pair<int,int>> BishopFigure::allAllowedBishopMoves(
        Field* currentPosition,std::vector<Figure*> figuresOnTable, FigureColor color)
{
    std::vector<std::pair<int,int>> allowedMoves;

    int initialPositionRow;
    int initialPositionCol;

    for(int i = -1 ; i <= 1 ; i = i + 2)
    {
        for(int j = -1 ; j <= 1 ; j = j + 2)
        {
            setInitialValues(currentPosition,initialPositionRow,initialPositionCol);

            fillAllowedMoves(figuresOnTable, color, &allowedMoves,
                             initialPositionRow,initialPositionCol,i,j);
        }
    }
    return allowedMoves;
}
