#ifndef STARTGAMEINITIALIZETABLEFACTORY_H
#define STARTGAMEINITIALIZETABLEFACTORY_H

#include "chesstablefactory.h"

class StartGameInitializeTableFactory : public ChessTableFactory
{
public:
    StartGameInitializeTableFactory();
    Table* createTable() override;
    std::vector<Figure*> createFigures(FigureColor color);
};

#endif // STARTGAMEINITIALIZETABLEFACTORY_H
