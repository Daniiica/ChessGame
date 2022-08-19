#ifndef SETPROMOTIONEXAMPLEFACTORY_H
#define SETPROMOTIONEXAMPLEFACTORY_H

#include "chesstablefactory.h"

class SetPromotionExampleFactory : public ChessTableFactory
{
public:
    SetPromotionExampleFactory();
    Table* createTable() override;
};
#endif // SETPROMOTIONEXAMPLEFACTORY_H
