#ifndef CHESSTABLEFACTORY_H
#define CHESSTABLEFACTORY_H

#include "table.h"
#include <iostream>

class ChessTableFactory
{
public:
    ChessTableFactory();
    virtual Table* createTable() = 0;
    virtual ~ChessTableFactory();
};

#endif // CHESSTABLEFACTORY_H
