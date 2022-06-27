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
bool KnightFigure::isValidFigureMove(Field nextPosition)
{
    int currentPositionCol = _currentPosition.getCol();
    int currentPositionRow = _currentPosition.getRow();
    int nextPositionCol = nextPosition.getCol();
    int nextPositionRow = nextPosition.getRow();

    if(((abs(currentPositionCol - nextPositionCol) == 2) && (abs(currentPositionRow - nextPositionRow) == 1)) ||
            ((abs(currentPositionCol - nextPositionCol) == 1) && (abs(currentPositionRow - nextPositionRow) == 2)))
        return true;
    return false;
}
std::map<int,int> KnightFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{

}
