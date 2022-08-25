#ifndef STARTGAMEINITIALIZETABLEFACTORY_H
#define STARTGAMEINITIALIZETABLEFACTORY_H

#include "chesstablefactory.h"

class StartGameInitializeTableFactory : public ChessTableFactory
{
public:
    StartGameInitializeTableFactory();
    Table* createTable() override;
    std::vector<Figure*> createFigures(FigureColor color);
    virtual ~StartGameInitializeTableFactory()  {std::cout << "Destructor in StartGameInitializeTableFactory" << std::endl;};
};

#endif // STARTGAMEINITIALIZETABLEFACTORY_H
