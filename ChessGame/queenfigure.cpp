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

bool QueenFigure::isValidFigureMove(Field startPosition,Field nextPosition)
{
    if(!BishopFigure::isValidBishopMove(startPosition,nextPosition))
        return RookFigure::isValidRookMove(startPosition,nextPosition);
    return BishopFigure::isValidBishopMove(startPosition,nextPosition);
}

std::vector<std::pair<int,int>> QueenFigure::allPositionsBetweenCurrentAndNextPosition(
        Field nextPosition)
{
    std::vector<std::pair<int,int>> indexOfFields;

    if(RookFigure::isValidRookMove(*_currentPosition,nextPosition))
    {
        auto rookPath = RookFigure::allPositionsBetweenRookAndNextPosition(
                    _currentPosition,nextPosition);
        indexOfFields.insert(indexOfFields.begin(),rookPath.begin(),rookPath.end());
    }
    if(BishopFigure::isValidBishopMove(*_currentPosition,nextPosition))
    {
        auto bishopPath = BishopFigure::allPositionsBetweenBishopAndNextPosition(
                    _currentPosition,nextPosition);
        indexOfFields.insert(indexOfFields.end(),bishopPath.begin(),bishopPath.end());
    }
    return indexOfFields;
}

std::vector<std::pair<int,int>> QueenFigure::allAllowedMoves(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allowedMoves;

    allowedMoves = BishopFigure::allAllowedBishopMoves(_currentPosition,figuresOnTable,_color);

    auto rookAllowedMoves = RookFigure::allAllowedRookMoves(_currentPosition,figuresOnTable,_color);
    allowedMoves.insert(allowedMoves.end(),rookAllowedMoves.begin(),rookAllowedMoves.end());

    return allowedMoves;
}
