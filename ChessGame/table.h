#ifndef TABLE_H
#define TABLE_H

#include "field.h"
#include "figureset.h"
#include <array>

class Table
{
private:
    Field** _fields;
    std::array<FigureSet,2> _figuresOnTable;
public:
    Table();
    Table(std::vector<Figure*> figures);
    void createIndexOfTable(Field** fields);
    Field** getFields();
    Field getField(int row, int col);
    Field* getField(std::string index);
    Figure* getFigureOnField(Field position);
    bool isLeapSomeFigures(std::map<int,int> indexOfPositions);

    FigureSet* getFigureSet(FigureColor color);
    void setFigureOnField(Figure* figure, Field* position);
};

#endif // TABLE_H
