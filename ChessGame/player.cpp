#include "player.h"

Player::Player(FigureColor color)
    :_color{color},_allMoves(0)
{
}

bool Player::addNewMove(Field* firstPosition, Field* secondPosition,Table table)
{
    Move move(*firstPosition,*secondPosition,table.getFigureOnField(*firstPosition),table.getFigureOnField(*secondPosition));
    if(move.isValidMove(table)){
        _allMoves.push_back(move);
        return true;
    }
    else
    {
        std::cout << "Move is not valid." << std::endl;
        return false;
    }
}

std::vector<Move> Player::getMovesFromPlayer()
{
    return _allMoves;
}
