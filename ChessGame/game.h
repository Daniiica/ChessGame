#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <array>
#include "table.h"
#include "move.h"
#include <string>

class Game
{
private:
    std::array<Player,2> _players;
    Table _table;
public:
    Game();
    FigureColor getColorName(std::string fc);
    bool newMove(std::string color, std::string firstPosition, std::string secondPosition);
};

#endif // GAME_H
