#ifndef FIELD_H
#define FIELD_H

#include <string>
#include "player.h"

class Field
{
private:
   int _row;
   int _col;
   std::string _value;
   //Player* player; //pokazuje na igraca cija figura se nalazi na tom polju
public:
    Field();
    Field(int row, int col, std::string value);
    void setValue(std::string value);
    int getRow();
    int getCol();
    std::string getValue();
    bool outOfRange();
};

#endif // FIELD_H
