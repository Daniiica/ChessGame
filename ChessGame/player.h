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

};
#endif // PLAYER_H


