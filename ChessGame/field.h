#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <iostream>

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
    Field(int row, int col);
    void setValue(std::string value);
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
    std::string getValue();
    bool outOfRange();
    bool operator==(const Field &rhs) const;
};

#endif // FIELD_H
