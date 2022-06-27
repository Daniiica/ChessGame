#include "queenfigure.h"

QueenFigure::QueenFigure()
{
    _type = FigureName::queen;
    _state = true;
}
QueenFigure::QueenFigure(FigureColor color) : Figure(color)
{
    _type = FigureName::queen;
    _state = true;
}
bool QueenFigure::isValidFigureMove(Field nextPosition)
{
    BishopFigure bishop;
    RookFigure rook;
    if(bishop.isValidFigureMove(nextPosition))
        return rook.isValidFigureMove(nextPosition);
    return bishop.isValidFigureMove(nextPosition);
}
std::map<int,int> QueenFigure::allPositionsBetweenCurrentAndNextPosition(Field nextPosition)
{
    std::map<int,int> indexOfFields;
    RookFigure rook;
    rook.setCurrentPosition(_currentPosition);
    if(rook.isValidFigureMove(nextPosition))
    {
        auto rookMap = rook.allPositionsBetweenCurrentAndNextPosition(nextPosition);
        indexOfFields.insert(rookMap.begin(),rookMap.end());
    }
    BishopFigure bishop;
    bishop.setCurrentPosition(_currentPosition);
    if(bishop.isValidFigureMove(nextPosition))
    {
        auto bishopMap = bishop.allPositionsBetweenCurrentAndNextPosition(nextPosition);
        indexOfFields.insert(bishopMap.begin(),bishopMap.end());
    }
    return indexOfFields;
}
