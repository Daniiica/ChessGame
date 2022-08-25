#include "table.h"


Table::Table()
{
    _figuresOnTable[0].setColor(FigureColor::Black);
    _figuresOnTable[1].setColor(FigureColor::White);
    _fields = new Field*[8];
    for(int i = 0; i < 8; i++)
        _fields[i] = new Field[8];

    int index = 0;
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Field field{i,j,""};
            _fields[i][j] = field;
            index++;
        }
    }
    createIndexOfTable(_fields);
}

void Table::createIndexOfTable(Field** field)
{
    int i = 0;
    int j = 0;
    std::string value;
    for(auto num = '1' ; num <= '8' ; num++)
    {
        for(auto let = 'a'; let <= 'h' ; let++)
        {
            value = let;
            value += num;
            field[i][j].setPosition(value);
            j++;
        }
        j = 0;
        i++;
    }
}

std::string Table::getFigureNameOnPosition(std::string position)
{
    std::string name = "";
    for(auto figureSet : _figuresOnTable)
    {
        for(auto figures : figureSet.getAllFigures())
        {
            if(figures->getState() == true &&
                    figures->getCurrentPosition()->getPosition() == position)
            {
                name = figures->getName();
                return name;
            }
        }
    }
    return name;
}

Field** Table::getFields()
{
    return _fields;
}

Field* Table::getField(int row, int col)
{
    return &_fields[row][col];
}

Field* Table::getField(std::string index)
{
    for(int i = 0 ; i < 8; i++)
    {
        for(int j = 0 ; j < 8; j++)
            if(_fields[i][j].getPosition() == index)
                return &_fields[i][j];
    }
    return nullptr;
}

std::array<FigureSet,2> Table::getFiguresOnTable()
{
    return _figuresOnTable;
}

std::vector<Figure*> Table::getAllFiguresOnTable()
{
    std::vector<Figure*> allFiguresOnTable;
    for(auto figureSet : getFiguresOnTable())
    {
        for(auto figurePtr : figureSet.getAllFigures())
        {
            if(figurePtr->getState() == true && figurePtr->getCurrentPosition() != nullptr)
                allFiguresOnTable.emplace_back(figurePtr);
        }
    }
    return allFiguresOnTable;
}

std::vector<Figure*> Table::getAllFiguresOnTableWithoutKing(Figure* kingPtr)
{
    std::vector<Figure*> allFiguresOnTable;
    for(auto figureSet : getFiguresOnTable())
    {
        for(auto figurePtr : figureSet.getAllFigures())
        {
            if(figurePtr->getState() == true && figurePtr->getCurrentPosition() != nullptr
                    && figurePtr != kingPtr)
                allFiguresOnTable.emplace_back(figurePtr);
        }
    }
    return allFiguresOnTable;
}

std::vector<Figure*> Table::getFiguresInColor(std::vector<Figure*> allFigures, FigureColor color)
{
    std::vector<Figure*> figuresInSameColor;
    for(auto figuresPtr : allFigures)
    {
        if(figuresPtr->getColor() == color && figuresPtr->getType() != FigureName::king)
        {
            figuresInSameColor.emplace_back(figuresPtr);
        }
    }
    return figuresInSameColor;
}

void Table::setFigureSet(FigureSet& figureSet, int index)
{
    auto color = figureSet.getColor();
    _figuresOnTable[index].setColor(color);
    auto figures = figureSet.getAllFigures();
    _figuresOnTable[index].setFigures(figures);
}

Figure* Table::getFigure(FigureColor color, FigureName name)
{
    FigureSet* figureSetPtr = getFigureSet(color);
    for(auto figurePtr : figureSetPtr->getAllFigures())
    {
        if(figurePtr->getType() == name)
        {
            return figurePtr;
        }
    }
    return nullptr;
}

FigureSet* Table::getFigureSet(FigureColor color)
{
    return color == FigureColor::Black ? &_figuresOnTable[0] : &_figuresOnTable[1];
    }

    bool Table::isOtherFigureBetweenCurrentAndNextPosition(
    std::vector<std::pair<int,int>> indexOfPositions)
    {
    std::vector<Figure*> allFigures;
    for(auto field : indexOfPositions)
    {
        for(auto figureSet : _figuresOnTable)
        {
            allFigures = figureSet.getAllFigures();
            for(auto figurePtr : allFigures)
            {
                if(figurePtr->getState() == true &&
                        figurePtr->getCurrentPosition() != nullptr &&
                        *(figurePtr->getCurrentPosition()) == _fields[field.first][field.second])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Figure* Table::getFigureOnField(const Field& position) const
{
    for(auto figureSet : _figuresOnTable)
    {
        for(auto figurePtr : figureSet.getAllFigures())
        {
            if(figurePtr != nullptr && figurePtr->getState() == true &&
                    *(figurePtr->getCurrentPosition()) == position)
            {
                return figurePtr;
            }
        }
    }
    return nullptr;
}

bool Table::isFigureBetweenKingAndRook(Figure* kingPtr, Figure* rookPtr)
{
    auto kingPositionPtr = kingPtr->getCurrentPosition();
    auto path = rookPtr->allPositionsBetweenCurrentAndNextPosition(*kingPositionPtr);
    Field* positionInPathPtr;
    for (auto field : path)
    {
        positionInPathPtr = getField(field.first, field.second);
        if (getFigureOnField(*positionInPathPtr) != nullptr)
        {
            TextLogger::logWarning("There are figures between king and rook!");
            return false;
        }
    }
    return true;
}

void Table::deleteEatenFigure(Figure* eatenFigurePtr)
{
    FigureColor figureColor = eatenFigurePtr->getColor();
    FigureSet* figureSetPtr = getFigureSet(figureColor);

    figureSetPtr->deleteFigure(eatenFigurePtr);
}

MoveResultValue Table::isValidMove(Move& move)
{
    auto currentFigurePtr = move.getCurrentFigure();
    auto endPositionPtr = move.getEndPosition();
    FigureColor figureColor = currentFigurePtr->getColor();
    FigureName figureType = currentFigurePtr->getType();
    Figure* figureOnEndPositionPtr = getFigureOnField(*endPositionPtr);
    Field* startPositionPtr = currentFigurePtr->getCurrentPosition();

    if (currentFigurePtr->isValidFigureMove(*startPositionPtr, *endPositionPtr))
    {
        if (figureType == FigureName::bishop ||
                figureType == FigureName::rook ||
                figureType == FigureName::queen ||
                figureType == FigureName::pawn)
        {
            if (figureType == FigureName::pawn)
            {
                if(!PawnFigure::checkPawnMove(startPositionPtr, endPositionPtr,
                                              figureOnEndPositionPtr, figureColor))
                    return MoveResultValue::notValidMove;
            }
            if(isOtherFigureBetweenCurrentAndNextPosition(
                        currentFigurePtr->
                        allPositionsBetweenCurrentAndNextPosition(*endPositionPtr)))
                return MoveResultValue::notValidMove;
        }
        return MoveResultValue::validMove;
    }
    return Move::invalidMove();
}

void Table::undoMove(Field& startPosition, Move& move)
{
    auto currentFigurePtr = move.getCurrentFigure();
    auto eatenFigurePtr = move.getEndFigure();

    if (eatenFigurePtr != nullptr)
    {
        if(currentFigurePtr->getColor() == eatenFigurePtr->getColor())
        {
            undoCastling(move);
            return;
        }
        auto currentPosition = currentFigurePtr->getCurrentPosition();
        eatenFigurePtr->setCurrentPosition(currentPosition);
        eatenFigurePtr->setActiveState();
    }
    currentFigurePtr->setCurrentPosition(&startPosition);
}

void Table::undoCastling(Move& move)
{
    auto kingFigurePtr = move.getKingFigureInMove();
    auto rookFigurePtr = move.getRookFigureInMove();

    auto startPositionPtr = getField(move.getStartPosition()->getPosition());
    auto endPositionPtr = getField(move.getEndPosition()->getPosition());

    auto kingPositionPtr = move.getCurrentFigure() == kingFigurePtr ?
                startPositionPtr : endPositionPtr;
    auto rookPositionPtr = move.getCurrentFigure() == rookFigurePtr ?
                startPositionPtr : endPositionPtr;

    kingFigurePtr->setCurrentPosition(kingPositionPtr);
    rookFigurePtr->setCurrentPosition(rookPositionPtr);
}

void Table::moveFigure(Move& move)
{
    auto currentFigurePtr = move.getCurrentFigure();
    auto figureOnEndPositionPtr = move.getEndFigure();
    auto endPositionName = move.getEndPosition()->getPosition();
    auto endPositionPtr = getField(endPositionName);

    if (figureOnEndPositionPtr != nullptr)
    {
        figureOnEndPositionPtr->setCurrentPosition(nullptr);
        figureOnEndPositionPtr->setEatenState();
    }
    currentFigurePtr->setCurrentPosition(endPositionPtr);
}

MoveResultValue Table::checkChess(FigureColor kingColor,
                                  FigureColor currentFigureColor)
{
    auto allFiguresOnTable = getAllFiguresOnTable();
    Figure* kingPtr = getFigure(kingColor, FigureName::king);
    auto kingPositionRow = kingPtr->getCurrentPosition()->getRow();
    auto kingPositionCol = kingPtr->getCurrentPosition()->getCol();
    std::pair<int, int> kingPosition(kingPositionRow, kingPositionCol);
    int howMuchFiguresAttackKing = 0;
    Figure* figureWhoAttackKingPtr = nullptr;

    if (checkIsPositionAttack(kingPosition, allFiguresOnTable,
                              currentFigureColor,
                              howMuchFiguresAttackKing, &figureWhoAttackKingPtr))
    {
        if(kingPtr->getColor() == currentFigureColor)
            return MoveResultValue::chess;
        return checkChessMat(kingPtr, howMuchFiguresAttackKing, figureWhoAttackKingPtr);
    }
    return MoveResultValue::validMove;
}

bool Table::checkIsPositionAttack(std::pair<int, int> position,
                                  std::vector<Figure*> allFigures,
                                  FigureColor attackersColor,
                                  int& howMuchFiguresAttackKing, Figure** figureWhoAttackKing)
{
    for (auto figuresPtr : Table::getFiguresInColor(allFigures,attackersColor))
    {
        auto allowedMovesPerFigure = figuresPtr->allAllowedMoves(allFigures);
        if (std::find(allowedMovesPerFigure.begin(), allowedMovesPerFigure.end(),
                      position) != allowedMovesPerFigure.end())
        {
            howMuchFiguresAttackKing++;
            *figureWhoAttackKing = figuresPtr;
        }
    }

    if (howMuchFiguresAttackKing == 0)
    {
        return false;
    }
    return true;
}

MoveResultValue Table::checkChessMat(Figure* kingPtr, int howMuchFiguresAttackKing,
                                     Figure* figureWhoAttackKingPtr)
{
    int howMuchFiguresAttackPositionArroundKing = 0;
    Figure* figureWhoAttackPositionArroundKingPtr = nullptr;
    FigureColor kingColor = kingPtr->getColor();
    FigureColor differentColorOfKing = kingPtr -> getOtherColor();
    auto allFiguresOnTable = getAllFiguresOnTable();
    auto allFiguresOnTableWithoutKing = getAllFiguresOnTableWithoutKing(kingPtr);
    auto allFiguresInKingsColor = Table::getFiguresInColor(allFiguresOnTable, kingColor);
    std::vector<std::pair<int, int>> allAllowedKingMoves =
            kingPtr->allAllowedMoves(allFiguresInKingsColor);
    std::pair<int, int> figureCurrentPosition = figureWhoAttackKingPtr->getCurrentPositionPair();

    for (auto position : allAllowedKingMoves)
    {
        howMuchFiguresAttackPositionArroundKing = 0;
        if (!checkIsPositionAttack(position, allFiguresOnTableWithoutKing,
                                   differentColorOfKing,
                                   howMuchFiguresAttackPositionArroundKing,
                                   &figureWhoAttackPositionArroundKingPtr))
        {
            return MoveResultValue::chess;
        }
    }
    if (howMuchFiguresAttackKing == 1 && figureWhoAttackKingPtr->getType() != FigureName::knight)
    {
        if (std::find(allAllowedKingMoves.begin(), allAllowedKingMoves.end(),
                      figureCurrentPosition) != allAllowedKingMoves.end())
        {
            return MoveResultValue::chess;
        }
        if (canSomeFigureProtectKing(kingPtr, figureWhoAttackKingPtr))
            return MoveResultValue::chess;
        return MoveResultValue::chessMat;
    }
    return MoveResultValue::chessMat;
}

bool Table::canSomeFigureProtectKing(Figure* kingPtr, Figure* figureWhoAttackKingPtr)
{
    FigureColor kingColor = kingPtr->getColor();
    auto allFiguresOnTable = getAllFiguresOnTable();
    Field kingPosition = *(kingPtr->getCurrentPosition());
    auto figureWhoAttackKingPairPos = figureWhoAttackKingPtr->getCurrentPositionPair();
    auto kingColorFigureSetPtr = getFigureSet(kingColor);
    std::vector<std::pair<int, int>> pathBetweenFigureAndKing =
            figureWhoAttackKingPtr->allPositionsBetweenCurrentAndNextPosition(kingPosition);
    pathBetweenFigureAndKing.emplace_back(figureWhoAttackKingPairPos);
    int howMuchFiguresAttackKing = 0;
    auto allFiguresWithoutKing = kingColorFigureSetPtr->getFiguresWithoutKing();
    for (auto position : pathBetweenFigureAndKing)
    {
        if (checkIsPositionAttack(position, allFiguresOnTable, kingColor,
                                  howMuchFiguresAttackKing, &figureWhoAttackKingPtr) &&
                figureWhoAttackKingPtr->getType() != FigureName::king)
            return true;
    }
    return false;
}

void Table::castling(Move& move)
{
    auto kingPtr = move.getKingFigureInMove();
    auto rookPtr = move.getRookFigureInMove();
    int kingPositionCol = kingPtr->getCurrentPosition()->getCol();
    int kingPositionRow = kingPtr->getCurrentPosition()->getRow();
    int rookPositionCol = rookPtr->getCurrentPosition()->getCol();

    Field* newKingPositionPtr;
    Field* newRookPositionPtr;
    int kingDifference;
    int rookDifference;


    if (rookPositionCol > kingPositionCol)
    {
        kingDifference = 2;
        rookDifference = -2;
    }
    else
    {
        kingDifference = -2;
        rookDifference = 3;
    }
    newKingPositionPtr = getField(kingPositionRow, kingPositionCol + kingDifference);
    kingPtr->setCurrentPosition(newKingPositionPtr);
    newRookPositionPtr = getField(kingPositionRow, rookPositionCol + rookDifference);
    rookPtr->setCurrentPosition(newRookPositionPtr);
}

bool Table::isValidCastling(Move& move, bool castlingLongStatus, bool castlingShortStatus)
{
    auto kingPtr = move.getKingFigureInMove();
    auto rookPtr = move.getRookFigureInMove();
    auto rookPositionPtr = rookPtr->getCurrentPosition();
    auto distanceBetweenKingAndRook = kingPtr->
            countPositionBetweenCurrentAndNextPosition(*rookPositionPtr);
    bool isCastlingAllowed = distanceBetweenKingAndRook > 2 ?
                castlingLongStatus : castlingShortStatus;
    if(isCastlingAllowed == true)
    {
        if(!isFigureBetweenKingAndRook(kingPtr, rookPtr))
            return false;
    }
    return isCastlingAllowed;
}

MoveResultValue Table::isChessOrChessMat(Figure* currentFigurePtr)
{
    FigureColor currentFigureColor = currentFigurePtr->getColor();
    FigureColor otherFigureColor = currentFigurePtr->getOtherColor();

    auto moveResult = checkChess(otherFigureColor, currentFigureColor);

    if(moveResult == MoveResultValue::chess)
    {
        TextLogger::logWarning("Chess! You must protect king!");
        return MoveResultValue::chess;
    }
    else if(moveResult == MoveResultValue::chessMat)
    {
        TextLogger::logWarning("ChessMat! Game is over!");
        return MoveResultValue::chessMat;
    }
    return MoveResultValue::notValidMove;
}

void Table::pawnOnEndTable(Move& move)
{
    auto currentFigurePtr = move.getCurrentFigure();
    auto endPositionPtr = move.getEndPosition();
    auto figureColor = currentFigurePtr->getColor();
    FigureSet* figureSetInCurrentColor = getFigureSet(figureColor);

    if (currentFigurePtr->getType() == FigureName::pawn &&
            currentFigurePtr->isFigureOnEndTable(*endPositionPtr))
    {
        figureSetInCurrentColor->changePawnWithOtherFigure(move);
    }
}

void Table::deleteAllFigures()
{
    for(auto &figureSet : _figuresOnTable)
    {
        figureSet.deleteFigures();
    }
}

Table::~Table()
{
    deleteAllFigures();
    deleteAllFields();
}

void Table::deleteAllFields()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        delete [] _fields[i];
        _fields[i] = nullptr;
    }
    delete [] _fields;

}
