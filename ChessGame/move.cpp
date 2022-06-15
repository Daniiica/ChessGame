#include "move.h"
Move::Move(Figure* figure, Field* nextMove, Table* table)
    :_figure{figure}, _nextMove{nextMove}, _table{table}
{
}
bool Move::checkMove()
{
    Field* currentPosition = _figure->getPosition();
    int currentPositionCol = currentPosition->getCol();
    int currentPositionRow = currentPosition->getRow();
    int nextPositionCol = _nextMove->getCol();
    int nextPositionRow = _nextMove->getRow();

    if(_nextMove->outOfRange() || _nextMove == currentPosition) // ako se unese potez van table ili ako se unese isti potez kao sto je trenutni
        return false;

    if(_figure->getName() == king)
    {
        return checkMoveKing(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
    }
    if(_figure->getName() == rook)
    {
       return checkMoveRook(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
    }
    if(_figure->getName() == bishop)
    {
       return checkMoveBishop(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
    }
    if(_figure->getName() == queen)
    {
       return checkMoveQueen(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
    }
    if(_figure->getName() == knight)
    {
       return checkMoveKnight(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
    }
    return checkMovePawn(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow);
}

bool Move::checkMoveKing(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow)
{
    if((nextPositionCol == currentPositionCol ||
      (abs(nextPositionCol) - abs(currentPositionCol) == 1)) &&
      (nextPositionRow == currentPositionRow ||
      (abs(nextPositionRow) - abs(currentPositionRow) == 1)))
        return true;
    return false;
}
bool Move::checkMoveRook(int currentPositionCol,int currentPositionRow,int nextPositionCol,int nextPositionRow)
{
    if(currentPositionCol == nextPositionCol ||
       currentPositionRow == nextPositionRow)
        return true;
    return false;
}
bool Move::checkMoveBishop(int currentPositionCol, int currentPositionRow, int nextPositionCol, int nextPositionRow)
{
    if(abs(currentPositionCol - nextPositionCol) == abs(currentPositionRow - nextPositionRow))
        return true;
    return false;
}
bool Move::checkMoveQueen(int currentPositionCol, int currentPositionRow, int nextPositionCol, int nextPositionRow)
{
    if(checkMoveBishop(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow) && checkMoveRook(currentPositionCol,currentPositionRow,nextPositionCol,nextPositionRow))
        return true;
    return false;
}
bool Move::checkMoveKnight(int currentPositionCol, int currentPositionRow, int nextPositionCol, int nextPositionRow)
{
    if(((abs(currentPositionCol - nextPositionCol) == 2) && (abs(currentPositionRow - nextPositionRow) == 1)) ||
        ((abs(currentPositionCol - nextPositionCol) == 1) && (abs(currentPositionRow - nextPositionRow) == 2)))
        return true;
    return false;
}
bool Move::checkMovePawn(int currentPositionCol, int currentPositionRow, int nextPositionCol, int nextPositionRow)
{
    if(currentPositionCol != nextPositionCol)
    {
        return false;
    }
    if(_figure->getPlayer()->getState()){ // ako je prvi igrac
        if((nextPositionRow < 4 && (nextPositionRow - currentPositionRow <= 2) && (nextPositionRow - currentPositionRow > 0)) ||
            (nextPositionRow >= 4 && (nextPositionRow - currentPositionRow == 1)))
        {
            return true;
        }
        return false;
    }
    else
    {
        if((nextPositionRow >= 4 && (currentPositionRow - nextPositionRow <= 2) && (currentPositionRow - nextPositionRow > 0)) ||
            (nextPositionRow < 4 && (currentPositionRow - nextPositionRow == 1)))
        {
            return true;
        }
        return false;
    }
    return false;
}
bool Move::makeMove()
{
   bool validMove = checkMove();
   Figure* figureOnNextMove = _table->getFigureOnField(_nextMove);
   if(validMove)
   {
       if(figureOnNextMove != nullptr && (figureOnNextMove->getPlayer() != _figure->getPlayer()))
       {
           return true;
       }
       return false;
   }
   return false;
}
void Move::changePositionsOnTable()
{
    if(makeMove())
    {
        _table->setFigureOnField(_figure,_nextMove);
    }
    else
    {
        std::cout << "Please enter valid position" << std::endl;
    }
}
