#include "field.h"

Field::Field()
{

}

Field::Field(int row, int col)
    :_row{row}, _col{col}
{

}

Field::Field(int row, int col, std::string value)
    :_row{row}, _col{col} , _position{value}
{

}

void Field::setPosition(std::string value)
{
    _position = value;
}

int Field::getCol()
{
    return _col;
}

int Field::getRow()
{
    return _row;
}

std::string Field::getPosition()
{
    return _position;
}

bool Field::operator==(const Field &rhs) const
{
    if(rhs._col == _col && rhs._row == _row)
        return true;
    else
        return false;
}

void Field::setRow(int row)
{
    _row = row;
}

void Field::setCol(int col)
{
    _col = col;
}

InputResultValue Field::invalidField(Field* currentFieldPtr)
{
    if(currentFieldPtr == nullptr)
    {
        TextLogger::logWarning("Please enter valid positions.");
        return InputResultValue::notValidInput;
    }
    return InputResultValue::validInput;
}

