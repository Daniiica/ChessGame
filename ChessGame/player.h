#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string.h>
#include <array>
//#include "table.h"

class Player
{
private:
    std::string _name;
    bool _first;
public:
   Player() = default;
   Player(std::string name);
   void setName(std::string name);
   std::string getName();
   bool getState();
};
#endif // PLAYER_H


