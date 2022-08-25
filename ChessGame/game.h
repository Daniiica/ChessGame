#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <array>
#include "table.h"
#include "move.h"
#include "chesstablefactory.h"
#include <string>
#include "boardvisualizer.h"
#include "inputResultValue.h"

class Game
{
private:
    std::array<Player,2> _players;
    Table* _tablePtr;
public:
    Table* getTable();
    Game(ChessTableFactory* tableFactoryPtr);
    bool startFigureValidation(Player& player, Field* startFieldPtr);
    MoveResultValue castlingResult(Player& player, Move& move);
    MoveResultValue getMoveResult(Player& player, Move& move);
    void start();
    void run();
    bool isEndGame(std::string secondPosition);
    void outputTitle(Player& player);
    InputResultValue getInputResult(std::string& userFirstInput,
                                          std::string& userSecondInput,
                                          Field** startPosition, Field** endPosition);
    void setInputPositions(std::string& userFirstInput, std::string& userSecondInput);
    void changePlayer(int& playersIndex);
    void playMove(Move& move);
    bool isChessMat(Figure* currentFigurePtr);
    bool isSelfChess(Figure* currentFigurePtr);
    void cancelMove(Field* startPositionPtr, Move& move);
    ~Game();
};

#endif // GAME_H
