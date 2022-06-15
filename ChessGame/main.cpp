#include "figure.h"
#include "player.h"
#include "field.h"
#include "table.h"
#include <iostream>
#include "move.h"

int main()
{
    Table table;
    Table* tablePtr = &table;
    Field field = table.getField("c1");
    Field fieldNext = table.getField("f4");
    Figure* figure = table.getFigureOnField(&field);
    Move move{figure,&fieldNext,&table};
    bool l = move.makeMove();
    return 0;
}
