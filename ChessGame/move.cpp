#include "move.h"

Move::Move()
{
    // _eatenFigure
}

Move::Move(Field startPosition, Field endPosition, Figure* figure, Figure* eatenFigure)
    :_startPosition{startPosition},_endPosition{endPosition},_figure{figure},_eatenFigure{eatenFigure}
{

}

bool Move::isValidMove(Table table)
{
    FigureColor figureColor = (*_figure).getColor();
    FigureName figureType = (*_figure).getType();
    Figure* figureOnPosition = table.getFigureOnField(_endPosition);
    FigureSet* allFiguresPerColor = table.getFigureSet(figureColor);

    if((*_figure).isValidFigureMove(_endPosition))
    {
        if(figureType == FigureName::pawn)
        {
            if(abs((*_figure).getCurrentPosition().getCol() - _endPosition.getCol()) == 1){
                if(figureOnPosition == nullptr || (figureOnPosition->getColor() == figureColor))
                    return false;
                else
                    return true;
            }
        }
        if(figureType == FigureName::bishop ||
                figureType == FigureName::rook ||
                figureType == FigureName::queen)
        {
            if(table.isLeapSomeFigures((*_figure).allPositionsBetweenCurrentAndNextPosition(_endPosition)))
                return false;
        }
        if(allFiguresPerColor->figureOnPosition(_endPosition) == nullptr)
        {
            _eatenFigure = nullptr;
            _figure->setCurrentPosition(_endPosition);
            return true;
        }
        else
        {
            if(_eatenFigure->getColor() == figureColor){
                return false;
            }
            _eatenFigure = allFiguresPerColor->figureOnPosition(_endPosition);
            _eatenFigure->setEatenState();
            allFiguresPerColor->removeEatenFigure(_eatenFigure);
            _figure->setCurrentPosition(_endPosition);
            return true;
        }
    }
    return false;
}
