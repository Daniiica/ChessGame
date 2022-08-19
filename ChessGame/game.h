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
    Table* _table;
public:
    Table* getTable();
    Game(ChessTableFactory* tableFactory);
    bool startFigureValidation(Player& player, Field* startField);
    void doCastling(Player& player, Move& move);
    MoveResultValue castlingResult(Player& player, Move& move);
    MoveResultValue getMoveResult(Player& player, Move& move);
    void start();
    void run();
    bool isEndGame(std::string secondPosition);
    void inputMove(std::string player, std::string& firstPosition, std::string& secondPosition);
    void outputTitle(Player& player);
    MoveResultValue invalidField(Field* startField,Field* endField);
    MoveResultValue invalidFigure(Field* startField, FigureColor color);
    InputResultValue getInputResult(std::string& userFirstInput,
                                          std::string& userSecondInput,
                                          Field** startPosition, Field** endPosition);
    void setInputPositions(std::string& userFirstInput, std::string& userSecondInput);
    void changePlayer(int& playersIndex);
    void playMove(Move& move, Field* endPosition);
    bool isChessMat(Figure* currentFigure);
};

#endif // GAME_H
