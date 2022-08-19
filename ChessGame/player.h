#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>
#include "move.h"
#include "figurecolor.h"
#include "textlogger.h"
#include "moveresultvalue.h"
#include "table.h"

class Player
{
private:
    FigureColor _color;
    std::vector<Move> _allMoves;
    bool _castlingLongStatus = true;
    bool _castlingShortStatus = true;
public:
   Player() = default;
   Player(FigureColor color);
   std::string getName();
   FigureColor getColor();
   MoveResultValue resultOfMove(Move& move, Table& table);
   std::vector<Move> getMovesFromPlayer();
   bool getCastlingLongStatus();
   bool getCastlingShortStatus();
   void disableCastlingStatus();
   void changeCastlingStatus(Figure* currentFigure, Field* firstPosition);
   bool isValidCastling(Move& move, Table& table);
   bool isCastling(Move& move, Table& table);
};
#endif // PLAYER_H


