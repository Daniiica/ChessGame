#include "player.h"

Player::Player(std::string name)
    : _name{name}
{
    if(_name == "white")
    {
        _first = true;
    }
    else
    {
        _first = false;
    }
}
bool Player::getState()
{
    return _first;
}
