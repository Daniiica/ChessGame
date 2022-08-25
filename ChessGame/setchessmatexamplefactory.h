#ifndef SETCHESSMATEXAMPLEFACTORY_H
#define SETCHESSMATEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetChessMatExampleFactory : public ChessTableFactory
{
public:
    SetChessMatExampleFactory();
    Table* createTable() override;
    virtual ~SetChessMatExampleFactory()  { std::cout << "Destructor in SetChessMatExampleFactory" << std::endl; };
};

#endif // SETCHESSMATEXAMPLEFACTORY_H

