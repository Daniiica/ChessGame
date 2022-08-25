#ifndef SETCHESSEXAMPLEFACTORY_H
#define SETCHESSEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetChessExampleFactory : public ChessTableFactory
{
public:
    SetChessExampleFactory();
    Table* createTable() override;
    virtual ~SetChessExampleFactory()  {std::cout << "Destructor in SetChessExampleFactory" << std::endl; };
};

#endif // SETCHESSEXAMPLEFACTORY_H
