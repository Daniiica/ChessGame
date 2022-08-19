#include "textlogger.h"

TextLogger::TextLogger()
{

}

void TextLogger::logFigureName(std::string text, FigureColor color)
{
    if(color == FigureColor::Black)
    {
        std::cout << std::setfill('_') << "\e[1;33m" << std::setw(4) << text << "\e[1;0m";
    }
    else
        std::cout << std::setfill('_') << std::setw(4) << text;
}
void TextLogger::logTitle(std::string text)
{
    std::cout << "\e[1;36m" << text << "\e[0m" << std::endl;
}

void TextLogger::logWarning(std::string text)
{
    std::cout << "\e[1;31m" << text << "\e[0m" << std::endl;
}
