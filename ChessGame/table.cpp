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
    FigureSet blackFigureSet;
    blackFigureSet.initializeFiguresOnStart(FigureColor::Black);
    FigureSet whiteFigureSet;
    whiteFigureSet.initializeFiguresOnStart(FigureColor::White);
    auto blackFigures = blackFigureSet.getFigures();
    auto whiteFigures = whiteFigureSet.getFigures();
    auto blackFiguresIt = blackFigures.begin();
    auto whiteFiguresIt = whiteFigures.begin();
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 0; j < 8 ; j++)
        {
            (*whiteFiguresIt)->setCurrentPosition(_fields[i][j]);
            (*blackFiguresIt)->setCurrentPosition(_fields[7-i][j]);
            whiteFiguresIt++;
            blackFiguresIt++;
        }
    }

    _figuresOnTable[0] = blackFigureSet;
    _figuresOnTable[1] = whiteFigureSet;
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

Field* Table::getField(std::string index)
{
    for(int i = 0 ; i < 8; i++)
    {
        for(int j = 0 ; j < 8; j++)
            if(_fields[i][j].getValue() == index)
                return &_fields[i][j];
    }
}
FigureSet* Table::getFigureSet(FigureColor color)
{
    if(color == FigureColor::Black)
    {
        return &_figuresOnTable[0];
    }
    else
        return &_figuresOnTable[1];
}
bool Table::isLeapSomeFigures(std::map<int,int> indexOfPositions)
{
    for(auto field : indexOfPositions)
    {
        for(auto figureSet : _figuresOnTable)
        {
            for(auto figure : figureSet.getFigures())
            {
                if(figure->getCurrentPosition() == _fields[field.first][field.second])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
Figure* Table::getFigureOnField(Field position)
{
    for(auto figureSet : _figuresOnTable)
    {
        for(auto figure : figureSet.getFigures())
        {
            if(figure->getCurrentPosition() == position)
            {
                return figure;
            }
        }
    }
    return nullptr;
}

void Table::setFigureOnField(Figure* figure, Field* position)
{

}
