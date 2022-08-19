#ifndef CHESSTABLEFACTORY_H
#define CHESSTABLEFACTORY_H

#include "table.h"

class ChessTableFactory
{
public:
    ChessTableFactory();
    virtual Table* createTable() = 0;
};

#endif // CHESSTABLEFACTORY_H
