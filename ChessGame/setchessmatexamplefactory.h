#ifndef SETCHESSMATEXAMPLEFACTORY_H
#define SETCHESSMATEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetChessMatExampleFactory : public ChessTableFactory
{
public:
    SetChessMatExampleFactory();
    Table* createTable() override;
};

#endif // SETCHESSMATEXAMPLEFACTORY_H

