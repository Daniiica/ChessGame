#ifndef SETCASTLINGEXAMPLEFACTORY_H
#define SETCASTLINGEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetCastlingExampleFactory : public ChessTableFactory
{
public:
    SetCastlingExampleFactory();
    Table* createTable() override;
    virtual ~SetCastlingExampleFactory()  { std::cout << "Destructor in SetCastling" << std::endl; };
};

#endif // SETCASTLINGEXAMPLEFACTORY_H
