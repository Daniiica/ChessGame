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
    //initializeFigures();
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

