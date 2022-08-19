#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <iostream>
#include "moveresultvalue.h"
#include "inputResultValue.h"
#include "textlogger.h"

class Field
{
private:
   int _row;
   int _col;
   std::string _position;

public:
    Field();
    Field(int row, int col, std::string value);
    Field(int row, int col);
    void setPosition(std::string value);
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
    std::string getPosition();
    bool operator==(const Field &rhs) const;
    static InputResultValue invalidField(Field* startField,Field* endField);
};

#endif // FIELD_H
