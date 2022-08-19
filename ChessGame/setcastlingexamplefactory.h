#ifndef SETCASTLINGEXAMPLEFACTORY_H
#define SETCASTLINGEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetCastlingExampleFactory : public ChessTableFactory
{
public:
    SetCastlingExampleFactory();
    Table* createTable() override;
};

#endif // SETCASTLINGEXAMPLEFACTORY_H
