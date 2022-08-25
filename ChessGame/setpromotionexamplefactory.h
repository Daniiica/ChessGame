#ifndef SETPROMOTIONEXAMPLEFACTORY_H
#define SETPROMOTIONEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetPromotionExampleFactory : public ChessTableFactory
{
public:
    SetPromotionExampleFactory();
    Table* createTable() override;
    virtual ~SetPromotionExampleFactory()  {std::cout << "Destructor in SetPromotionExampleFactory" << std::endl; };
};
#endif // SETPROMOTIONEXAMPLEFACTORY_H
