#include "rookfigure.h"

RookFigure::RookFigure()
{
    _type = FigureName::rook;
    _state = true;
}

RookFigure::RookFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::rook;
    _state = true;
}

bool RookFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
   return isValidRookMove(startPosition,nextPosition);
}

bool RookFigure::isValidRookMove(Field startPosition, Field nextPosition)
{
    return (startPosition.getCol() == nextPosition.getCol() ||
            startPosition.getRow() == nextPosition.getRow());
}

std::vector<std::pair<int,int>> RookFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{
    return allPositionsBetweenRookAndNextPosition(_currentPosition,nextPosition);
}

void RookFigure::fillAllowedMoves(std::vector<Figure*> figuresOnTable,
                                  FigureColor color,
                                  std::vector<std::pair<int,int>>* allowedMoves,
                                  int& initialPositionRow, int& initialPositionCol,
                                  int isUpOrDown, int isLeftOrRight)
{
    while((initialPositionRow + isUpOrDown >= 0) &&
          (initialPositionCol + isLeftOrRight >= 0) &&
          (initialPositionRow + isUpOrDown <= 7) &&
          (initialPositionCol + isLeftOrRight <= 7))
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

std::vector<std::pair<int,int>> RookFigure::allAllowedMoves(
        std::vector<Figure*> figuresOnTable)
{
    return allAllowedRookMoves(_currentPosition,figuresOnTable,_color);
}

std::vector<std::pair<int,int>> RookFigure::allAllowedRookMoves(
        Field* currentPosition, std::vector<Figure*> figuresOnTable, FigureColor color)
{
    std::vector<std::pair<int,int>> allowedMoves;

    int initialRowValue;
    int initialColValue;
    setInitialValues(currentPosition,initialRowValue,initialColValue);

    fillAllowedMoves(figuresOnTable,color,&allowedMoves,initialRowValue,initialColValue,1,0);

    setInitialValues(currentPosition,initialRowValue,initialColValue);

    fillAllowedMoves(figuresOnTable,color,&allowedMoves,initialRowValue,initialColValue,-1,0);

    setInitialValues(currentPosition,initialRowValue,initialColValue);

    fillAllowedMoves(figuresOnTable,color,&allowedMoves,initialRowValue,initialColValue,0,1);
    setInitialValues(currentPosition,initialRowValue,initialColValue);

    fillAllowedMoves(figuresOnTable,color,&allowedMoves,initialRowValue,initialColValue,0,-1);

    return allowedMoves;
}

std::vector<std::pair<int,int>> RookFigure::allPositionsBetweenRookAndNextPosition(
        Field *currentPosition, Field nextPosition)
{
    std::vector<std::pair<int,int>> indexOfFields;
    auto currentPositionRow = currentPosition->getRow();
    auto currentPositionCol = currentPosition->getCol();
    auto nextPositionRow = nextPosition.getRow();
    auto nextPositionCol = nextPosition.getCol();

    if(currentPositionCol == nextPositionCol)
    {
        int topPosition = currentPositionRow > nextPositionRow ?
                    currentPositionRow : nextPositionRow;
        int bottomPosition = topPosition == currentPositionRow ?
                    nextPositionRow : currentPositionRow;
        for(int i = bottomPosition + 1 ; i < topPosition ; i++)
        {
            indexOfFields.emplace_back(i,currentPositionCol);
        }
    }
    if(currentPositionRow == nextPositionRow)
    {
        int leftPosition = currentPositionCol > nextPositionCol ?
                    nextPositionCol : currentPositionCol;
        int rightPosition = leftPosition == currentPositionCol ?
                    nextPositionCol : currentPositionCol;
        for(int i = leftPosition +1 ; i < rightPosition ; i++)
        {
            indexOfFields.emplace_back(currentPositionRow,i);
        }
    }
    return indexOfFields;
}
