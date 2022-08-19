#ifndef SETCHESSEXAMPLEFACTORY_H
#define SETCHESSEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetChessExampleFactory : public ChessTableFactory
{
public:
    SetChessExampleFactory();
    Table* createTable() override;
};

#endif // SETCHESSEXAMPLEFACTORY_H
