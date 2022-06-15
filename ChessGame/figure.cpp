#include "figure.h"

//Figure::Figure(std::string name, std::vector<std::string> allowedMoves, std::string currentMove, std::string nextMove, Player* player)
//    : _name{name}, _currentMove{currentMove}, _nextMove{nextMove}, _allowedMoves(0, 0), _player{player} {}

Figure::Figure(figureName name, bool state, Field* currentPosition, Player* player)
    : _name{name} , _state{state}, _currentPosition{currentPosition}, _player{player} {}

figureName Figure::getName()
{
    return _name;
}
void Figure::setName(figureName name)
{
    _name = name;
}
Field* Figure::getPosition()
{
    return _currentPosition;
}
Player* Figure::getPlayer()
{
    return _player;
}
void Figure::setPosition(Field* position)
{
    _currentPosition = position;
}
