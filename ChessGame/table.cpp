#include "table.h"

Table::Table()
{
    _fields = new Field *[8];
    for(int i = 0; i <8; i++)
        _fields[i] = new Field[8];

    int index = 0;
        for (int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
            Field field{i,j,""};
            _fields[i][j] = field;
            index++;
            }
        }
    createIndexOfTable(_fields);
    initializeFigures();
}

void Table::initializeFigures()
{
    Player firstPlayer{"white"};
    Player secondPlayer{"black"};

    figureName figures[16] = {rook,knight,bishop,king,queen,bishop,knight,rook,pawn,pawn,pawn,pawn,pawn,pawn,pawn,pawn};

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Figure figureW{figures[i * 8 + j],true,&_fields[i][j],&firstPlayer};
            _figures[i * 8 + j] = figureW;
            Figure figureB{figures[i * 8 + j],true,&_fields[7-i][j],&secondPlayer};
            _figures[i * 8 + j + 2 * 8] = figureB;
        }
    }

}

void Table::createIndexOfTable(Field** field)
{
    int i = 0;
    int j = 0;
    std::string value;
    std::string letters[] = {"a","b","c","d","e","f","g","h"};
    std::string numbers[] = {"1","2","3","4","5","6","7","8"};
    for(auto num : numbers)
    {
        for(auto let : letters)
        {
            value = let + num;
            field[i][j].setValue(value);
            j++;
        }
        j = 0;
        i++;
    }
}

Field** Table::getFields()
{
    return _fields;
}

Field Table::getField(int row, int col)
{
    return _fields[row][col];
}

Field Table::getField(std::string index)
{
    for(int i = 0 ; i < 8; i++)
    {
        for(int j = 0 ; j < 8; j++)
            if(_fields[i][j].getValue() == index)
                return _fields[i][j];
    }
}

Figure* Table::getFigureOnField(Field* position)
{
    Figure* figure = nullptr;
    for(auto item:_figures)
    {
        if(((*item.getPosition()).getCol() == (*position).getCol()) && (*item.getPosition()).getRow() == (*position).getRow())
        {
            figure = &item;
            return figure;
        }
    }
    return figure;
}
void Table::setFigureOnField(Figure* figure, Field* position)
{
    figure->setPosition(position);
}
