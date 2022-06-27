#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>
#include "move.h"
#include "figurecolor.h"
//#include "table.h"

class Player
{
private:
    FigureColor _color;
    std::vector<Move> _allMoves;
public:
   Player() = default;
   Player(FigureColor color);
   bool addNewMove(Field* firstPosition, Field* secondPosition, Table table);
   std::vector<Move> getMovesFromPlayer();
};
#endif // PLAYER_H


