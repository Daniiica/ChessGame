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
    void setFigureSet(FigureSet& figureSet, int index);
    Figure* getFigureOnField(const Field& position) const;
    Figure* getFigure(FigureColor color, FigureName name);
    bool isOtherFigureBetweenCurrentAndNextPosition(
            std::vector<std::pair<int,int>> indexOfPositions);
    FigureSet* getFigureSet(FigureColor color);
    std::vector<Figure*> getAllFiguresOnTableWithoutKing(Figure* kingPtr);
    bool isFigureBetweenKingAndRook(Figure* kingPtr, Figure* rookPtr);
    MoveResultValue isValidMove(Move& move);
    void undoMove(Field& startPosition, Move& move);
    void moveFigure(Move& move);
    MoveResultValue checkChess(FigureColor kingColor,
                                     FigureColor currentFigureColor);
    bool checkIsPositionAttack(std::pair<int, int> position,
                                     std::vector<Figure*> allFigures,
                                     FigureColor attackersColor,
                                     int& howMuchFiguresAttackKing, Figure** figureWhoAttackKing);
    MoveResultValue checkChessMat(Figure* kingPtr, int howMuchFiguresAttackKing,
                                        Figure* figureWhoAttackKingPtr);
    bool canSomeFigureProtectKing(Figure* kingPtr, Figure* figureWhoAttackKingPtr);
    void castling(Move& move);
    bool isValidCastling(Move& move, bool castlingLongStatus, bool castlingShortStatus);
    MoveResultValue isChessOrChessMat(Figure* currentFigurePtr);
    void deleteEatenFigure(Figure* eatenFigurePtr);
    void undoCastling(Move& move);
    void pawnOnEndTable(Move& move);
    void deleteAllFields();
    void deleteAllFigures();
    ~Table();
};

#endif // TABLE_H
