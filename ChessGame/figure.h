#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "field.h"
#include "player.h"

enum figureName
{
    king = 1,
    queen = 2,
    bishop = 3,
    knight = 4,
    rook = 5,
    pawn = 6
};

enum boundary
{
    noBoundary = 0,
    leftBoundary = 1,
    topBoundary = 2,
    rightBoundary = 3,
    bottomBoundary = 4,
    leftBottomCorner = 5,
    leftTopCorner = 6,
    rightTopCorner = 7,
    rightBottomCorner = 8
};

class Figure
{
private:
    figureName _name;
    bool _state;
    Field* _currentPosition;
    Player* _player;

public:
    Figure() = default;
    //Figure(std::string name, std::vector<std::string> allowedMoves, std::string currentMove, std::string nextMove, Player* player);
    Figure(figureName name,bool state,Field* currentPosition, Player* player);
    figureName getName();
    void setName(figureName name);
    Field* getPosition();
    Player* getPlayer();
    void setPosition(Field* position);
};


#endif // FIGURE_H
