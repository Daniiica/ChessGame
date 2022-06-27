#include "field.h"

Field::Field()
{

}

Field::Field(int row, int col)
    :_row{row}, _col{col}
{

}

Field::Field(int row, int col, std::string value)
    :_row{row}, _col{col} , _value{value}
{

}

void Field::setValue(std::string value)
{
    _value = value;
}

int Field::getCol()
{
    return _col;
}

int Field::getRow()
{
    return _row;
}
std::string Field::getValue()
{
    return _value;
}
bool Field::outOfRange()
{
    if(_row > 7 || _col > 7)
        return true;
    return false;
}

bool Field::operator==(const Field &rhs) const {
    if(rhs._col == this->_col && rhs._row == this->_row)
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
