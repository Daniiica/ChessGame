#include "boardvisualizer.h"

BoardVisualizer::BoardVisualizer()
{

}

void BoardVisualizer::printTable(Table& table)
{
    std::string index;
    std::string name;
    Field* positionPtr;
    FigureColor color;
    std::cout << std::endl;

    for(auto j = '9'; j >= '1' ; j--)
    {
        if(j != '9'){
            std::cout << j << " |";
        }
        else
        {
            std::cout << " " << " |";
        }
        for(char i = 'a'; i <= 'h' ; i++)
        {
            if(j == '9'){
                std::cout <<  std::setw(2) << std::right << i << "  |";
            }
            else
            {
                index = i;
                index += j;
                name = table.getFigureNameOnPosition(index) == "" ?
                            "" : table.getFigureNameOnPosition(index);

                if(name == "")
                {
                    std::cout << std::setfill('_') << std::setw(5) << "|";
                }
                else
                {
                    positionPtr = table.getField(index);
                    color = table.getFigureOnField(*positionPtr)->getColor();
                    TextLogger::logFigureName(name,color);
                    std::cout << "|";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
