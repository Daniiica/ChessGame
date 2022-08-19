#ifndef TEXTLOGGER_H
#define TEXTLOGGER_H

#include <string>
#include <iostream>
#include "figurecolor.h"
#include <iomanip>

class TextLogger
{
public:
    TextLogger();
    static void logWarning(std::string text);
    static void logFigureName(std::string text, FigureColor color);
    static void logTitle(std::string text);
};

#endif // TEXTLOGGER_H
