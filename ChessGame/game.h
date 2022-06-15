#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <array>

class Game
{
private:
    std::array<Player,2> _players;
public:
    Game();
};

#endif // GAME_H
