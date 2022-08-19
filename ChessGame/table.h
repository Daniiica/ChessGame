#ifndef TABLE_H
#define TABLE_H

#include "field.h"
#include "figureset.h"
#include "move.h"
#include <array>
#include <string.h>
#include <utility>
#include "textlogger.h"
#include "moveresultvalue.h"

class Table
{
private:
    Field** _fields;
    std::array<FigureSet,2> _figuresOnTable;
public:
    Table();
    void createIndexOfTable(Field** fields);
    Field** getFields();
    Field* getField(int row, int col);
    Field* getField(std::string index);
    std::array<FigureSet,2> getFiguresOnTable();
    std::string getFigureNameOnPosition(std::string position);
    std::vector<Figure*> getAllFiguresOnTable();
    static std::vector<Figure*> getFiguresInColor(
            std::vector<Figure*> allFigures, FigureColor color);
    void setFigureSet(FigureSet figures, int index);
    Figure* getFigureOnField(Field position);
    Figure* getFigure(FigureColor color, FigureName name);
    bool isOtherFigureBetweenCurrentAndNextPosition(
            std::vector<std::pair<int,int>> indexOfPositions);
    std::vector<Field*> convertIndexesInFields(
            std::vector<std::pair<int,int>> indexOfPositions);
    std::vector<std::pair<int,int>> convertFieldsToIndexesWithoutKing(
            Figure* king);
    static std::vector<std::pair<int,int>> convertFiguresPositionsToIndexes(
            std::vector<Figure*> allFigures, FigureColor color);
    FigureSet* getFigureSet(FigureColor color);
    std::vector<Figure*> getAllFiguresOnTableWithoutKing(Figure* king);
    bool isFigureBetweenKingAndRook(Figure* king, Figure* rook);
    MoveResultValue isValidMove(Move& move);
    void undoMove(Field& startPosition, Figure* currentFigure, Figure* eatenFigure);
    void moveFigure(Move& move, Field* endPosition);
    MoveResultValue getResult(Move& move);
    MoveResultValue checkChess(FigureColor kingColor,
                                     FigureColor currentFigureColor);
    bool checkIsPositionAttack(std::pair<int, int> position,
                                     std::vector<Figure*> allFigures,
                                     FigureColor attackersColor,
                                     int& howMuchFiguresAttackKing, Figure** figureWhoAttackKing);
    MoveResultValue checkChessMat(Figure* king, int howMuchFiguresAttackKing,
                                        Figure* figureWhoAttackKing);
    bool canSomeFigureProtectKing(Figure* king, Figure* figureWhoAttackKing);
    void castling(Move& move);
    bool isValidCastling(Move& move, bool castlingLongStatus, bool castlingShortStatus);
    MoveResultValue isChessOrChessMat(Figure* currentFigure);
 //   void playMove(Move& move, Field* endPosition);
};

#endif // TABLE_H
