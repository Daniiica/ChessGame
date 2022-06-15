#ifndef TABLE_H
#define TABLE_H

#include "field.h"
#include "figureset.h"

class Table
{
private:
    Field** _fields;
    FigureSet _playerFigures;
public:
    Table();
    void createIndexOfTable(Field** fields);
    Field** getFields();
    Field getField(int row, int col);
    Field getField(std::string index);
    Figure* getFigureOnField(Field* position);
    void setFigureOnField(Figure* figure, Field* position);
};

#endif // TABLE_H
