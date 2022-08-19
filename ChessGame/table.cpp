#include "table.h"


Table::Table()
{
    _fields = new Field *[8];
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
        for(auto figure : figureSet.getAllFigures())
        {
            if(figure->getState() == true && figure->getCurrentPosition() != nullptr)
            allFiguresOnTable.emplace_back(figure);
        }
    }
    return allFiguresOnTable;
}

std::vector<Figure*> Table::getAllFiguresOnTableWithoutKing(Figure* king)
{
    std::vector<Figure*> allFiguresOnTable;
    for(auto figureSet : getFiguresOnTable())
    {
        for(auto figure : figureSet.getAllFigures())
        {
            if(figure->getState() == true && figure->getCurrentPosition() != nullptr
                    && figure != king)
            allFiguresOnTable.emplace_back(figure);
        }
    }
    return allFiguresOnTable;
}

std::vector<Figure*> Table::getFiguresInColor(std::vector<Figure*> allFigures, FigureColor color)
{
    std::vector<Figure*> figuresInSameColor;
    for(auto figures : allFigures)
    {
        if(figures->getColor() == color && figures->getType() != FigureName::king)
        {
            figuresInSameColor.emplace_back(figures);
        }
    }
    return figuresInSameColor;
}

std::vector<std::pair<int,int>> Table::convertFiguresPositionsToIndexes(
        std::vector<Figure*> allFigures, FigureColor color)
{
    std::vector<std::pair<int,int>> allPositionIndexesForFigures;
    std::pair<int,int> figurePositionPair;
    for(auto figure : allFigures)
    {
        figurePositionPair = figure->getCurrentPositionPair();
        allPositionIndexesForFigures.emplace_back(figurePositionPair);
    }
    return allPositionIndexesForFigures;
}

void Table::setFigureSet(FigureSet figures, int index)
{
    _figuresOnTable[index] = figures;
}

Figure* Table::getFigure(FigureColor color, FigureName name)
{
    FigureSet* figureSet = getFigureSet(color);
    for(auto figure : figureSet->getAllFigures())
    {
        if(figure->getType() == name)
        {
            return figure;
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
            for(auto figure : allFigures)
            {
                if(figure->getState() == true &&
                        figure->getCurrentPosition() != nullptr &&
                        *(figure->getCurrentPosition()) == _fields[field.first][field.second])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

std::vector<Field*> Table::convertIndexesInFields(
        std::vector<std::pair<int,int>> indexOfPositions)
{
    std::vector<Field*> allowedFields;

    for(auto field : indexOfPositions)
    {
        for(auto figureSet : _figuresOnTable)
        {
            for(auto figure : figureSet.getAllFigures())
            {
                if(*(figure->getCurrentPosition()) == _fields[field.first][field.second])
                {
                    allowedFields.emplace_back(&_fields[field.first][field.second]);
                }
            }
        }
    }
    return allowedFields;
}

std::vector<std::pair<int,int>> Table::convertFieldsToIndexesWithoutKing(Figure* king)
{
    std::vector<std::pair<int,int>> indexes;
    for(auto figureSet : _figuresOnTable)
    {
        for(auto figures : figureSet.getAllFigures())
        {
            if(figures != king && figures->getState() == true)
            {
                indexes.emplace_back(std::pair(figures->getCurrentPosition()->getRow(),
                                               figures->getCurrentPosition()->getCol()));
            }
        }
    }
    return indexes;
}

Figure* Table::getFigureOnField(Field position)
{
    for(auto figureSet : _figuresOnTable)
    {
        for(auto figure : figureSet.getAllFigures())
        {
            if(figure != nullptr && figure->getState() == true &&
                    *(figure->getCurrentPosition()) == position)
            {
                return figure;
            }
        }
    }
    return nullptr;
}

bool Table::isFigureBetweenKingAndRook(Figure* king, Figure* rook)
{
    auto kingPosition = king->getCurrentPosition();
    auto path = rook->allPositionsBetweenCurrentAndNextPosition(*kingPosition);
    Field* positionInPath;
    for (auto field : path)
    {
        positionInPath = getField(field.first, field.second);
        if (getFigureOnField(*positionInPath) != nullptr)
        {
            TextLogger::logWarning("There are figures between king and rook!");
            return false;
        }
    }
    return true;
}

//void Table::playMove(Move& move, Field* endPosition)
//{
//    auto startPosition = move.getStartPosition();
//    auto eatenFigure = move.getEndFigure();
//    auto currentFigure = move.getCurrentFigure();
//    auto figureColor = currentFigure->getColor();
//    auto otherFigureColor = currentFigure->getOtherColor();
//    if(isValidMove(move) != MoveResultValue::notValidMove)
//    {
//        moveFigure(move, endPosition);

//        MoveResultValue isChess = checkChess( figureColor, otherFigureColor);
//        if (isChess == MoveResultValue::chess)
//        {
//            undoMove(*startPosition, currentFigure, eatenFigure);
//            TextLogger::logWarning("Your king will be attack!");
//        }
//    }
//}

MoveResultValue Table::isValidMove(Move& move)
{
    auto currentFigure = move.getCurrentFigure();
    auto endPosition = move.getEndPosition();
    FigureColor figureColor = currentFigure->getColor();
    FigureSet* figureSetInFigureColor = getFigureSet(figureColor);
    FigureName figureType = currentFigure->getType();
    Figure* figureOnEndPosition = getFigureOnField(*endPosition);
    Field* startPosition = currentFigure->getCurrentPosition();

    if (currentFigure->isValidFigureMove(*startPosition, *endPosition))
    {
        if (figureType == FigureName::bishop ||
                figureType == FigureName::rook ||
                figureType == FigureName::queen ||
                figureType == FigureName::pawn)
        {
            if (figureType == FigureName::pawn)
            {
                if(!PawnFigure::checkPawnMove(startPosition, endPosition,
                                              figureOnEndPosition, figureColor))
                    return MoveResultValue::notValidMove;
                if (currentFigure->isFigureOnEndTable(*endPosition)) {
                    figureSetInFigureColor->changePawnWithOtherFigure(&currentFigure);
                }
            }
            if(isOtherFigureBetweenCurrentAndNextPosition(
                        currentFigure->allPositionsBetweenCurrentAndNextPosition(*endPosition)))
                return MoveResultValue::notValidMove;
        }
        return MoveResultValue::validMove;
    }
    return MoveResultValue::notValidMove;
}

void Table::undoMove(Field& startPosition, Figure* currentFigure, Figure* eatenFigure)
{
    if (eatenFigure != nullptr)
    {
        auto currentPosition = currentFigure->getCurrentPosition();
        eatenFigure->setCurrentPosition(currentPosition);
        eatenFigure->setActiveState();
    }
    currentFigure->setCurrentPosition(&startPosition);
}

void Table::moveFigure(Move& move, Field* endPosition)
{
    auto currentFigure = move.getCurrentFigure();
    auto currentFigureColor = currentFigure->getColor();
    auto figureOnEndPosition = move.getEndFigure();

    if (figureOnEndPosition != nullptr)
    {
        getFigureSet(currentFigureColor)->deleteFigure(figureOnEndPosition);
    }
    currentFigure->setCurrentPosition(endPosition);
    //move.getCurrentFigure()->setCurrentPosition(&endPosition);
}

MoveResultValue Table::getResult(Move& move)
{
    Figure* currentFigure = move.getCurrentFigure();
    Figure* eatenFigure = move.getEndFigure();
    FigureColor figureColor = currentFigure->getColor();
    FigureColor otherFigureColor = currentFigure->getOtherColor();
    Field* startPosition = currentFigure->getCurrentPosition();

    auto moveValidation = isValidMove(move);
    if(moveValidation == MoveResultValue::validMove)
    {
        MoveResultValue isChess = checkChess( figureColor, otherFigureColor);
        if (isChess == MoveResultValue::chess || isChess == MoveResultValue::chessMat)
        {
            undoMove(*startPosition, currentFigure, eatenFigure);
            TextLogger::logWarning("Your king will be attack!");
            return MoveResultValue::notValidMove;
        }
        return MoveResultValue::validMove;
    }
    return MoveResultValue::notValidMove;
}

MoveResultValue Table::checkChess(FigureColor kingColor,
                                 FigureColor currentFigureColor)
{
    auto allFiguresOnTable = getAllFiguresOnTable();
    Figure* king = getFigure(kingColor, FigureName::king);
    auto kingPositionRow = king->getCurrentPosition()->getRow();
    auto kingPositionCol = king->getCurrentPosition()->getCol();
    std::pair<int, int> kingPosition(kingPositionRow, kingPositionCol);
    int howMuchFiguresAttackKing = 0;
    Figure* figureWhoAttackKing = nullptr;

    if (checkIsPositionAttack(kingPosition, allFiguresOnTable,
                              currentFigureColor,
                              howMuchFiguresAttackKing, &figureWhoAttackKing))
    {
        if(king->getColor() == currentFigureColor)
            return MoveResultValue::chess;
        return checkChessMat(king, howMuchFiguresAttackKing, figureWhoAttackKing);
    }
    return MoveResultValue::validMove;
}

bool Table::checkIsPositionAttack(std::pair<int, int> position,
                                 std::vector<Figure*> allFigures,
                                 FigureColor attackersColor,
                                 int& howMuchFiguresAttackKing, Figure** figureWhoAttackKing)
{
    for (auto figures : Table::getFiguresInColor(allFigures,attackersColor))
    {
        auto allowedMovesPerFigure = figures->allAllowedMoves(allFigures);
        if (std::find(allowedMovesPerFigure.begin(), allowedMovesPerFigure.end(),
                      position) != allowedMovesPerFigure.end())
        {
            howMuchFiguresAttackKing++;
            *figureWhoAttackKing = figures;
        }
    }

    if (howMuchFiguresAttackKing == 0)
    {
        return false;
    }
    return true;
}

MoveResultValue Table::checkChessMat(Figure* king, int howMuchFiguresAttackKing,
                                    Figure* figureWhoAttackKing)
{
    int howMuchFiguresAttackPositionArroundKing = 0;
    Figure* figureWhoAttackPositionArroundKing = nullptr;
    FigureColor kingColor = king->getColor();
    FigureColor differentColorOfKing = king -> getOtherColor();
    auto allFiguresOnTable = getAllFiguresOnTable();
    auto allFiguresOnTableWithoutKing = getAllFiguresOnTableWithoutKing(king);
    auto allFiguresInKingsColor = Table::getFiguresInColor(allFiguresOnTable, kingColor);
    std::vector<std::pair<int, int>> allAllowedKingMoves =
            king->allAllowedMoves(allFiguresInKingsColor);
    std::pair<int, int> figureCurrentPosition = figureWhoAttackKing->getCurrentPositionPair();

    for (auto position : allAllowedKingMoves)
    {
        howMuchFiguresAttackPositionArroundKing = 0;
        if (!checkIsPositionAttack(position, allFiguresOnTableWithoutKing,
                                   differentColorOfKing,
                                   howMuchFiguresAttackPositionArroundKing,
                                   &figureWhoAttackPositionArroundKing))
        {
            return MoveResultValue::chess;
        }
    }
    if (howMuchFiguresAttackKing == 1 && figureWhoAttackKing->getType() != FigureName::knight)
    {
        if (std::find(allAllowedKingMoves.begin(), allAllowedKingMoves.end(),
                      figureCurrentPosition) != allAllowedKingMoves.end())
        {
            return MoveResultValue::chess;
        }
        if (canSomeFigureProtectKing(king, figureWhoAttackKing))
            return MoveResultValue::chess;
        return MoveResultValue::chessMat;
    }
    return MoveResultValue::chessMat;
}

bool Table::canSomeFigureProtectKing(Figure* king, Figure* figureWhoAttackKing)
{
    FigureColor kingColor = king->getColor();
    auto allFiguresOnTable = getAllFiguresOnTable();
    Field kingPosition = *(king->getCurrentPosition());
    auto figureWhoAttackKingPairPos = figureWhoAttackKing->getCurrentPositionPair();
    auto kingColorFigureSet = getFigureSet(kingColor);
    std::vector<std::pair<int, int>> pathBetweenFigureAndKing =
            figureWhoAttackKing->allPositionsBetweenCurrentAndNextPosition(kingPosition);
    pathBetweenFigureAndKing.emplace_back(figureWhoAttackKingPairPos);
    int howMuchFiguresAttackKing = 0;
    auto allFiguresWithoutKing = kingColorFigureSet -> getFiguresWithoutKing();
    for (auto position : pathBetweenFigureAndKing)
    {
        if (checkIsPositionAttack(position, allFiguresOnTable, kingColor,
                                  howMuchFiguresAttackKing, &figureWhoAttackKing) &&
                figureWhoAttackKing->getType() != FigureName::king)
            return true;
    }
    return false;
}

void Table::castling(Move& move)
{
    auto king = move.getKingFigureInMove();
    auto rook = move.getRookFigureInMove();
    int kingPositionCol = king->getCurrentPosition()->getCol();
    int kingPositionRow = king->getCurrentPosition()->getRow();
    int rookPositionCol = rook->getCurrentPosition()->getCol();

    Field* newKingPosition;
    Field* newRookPosition;
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
    newKingPosition = getField(kingPositionRow, kingPositionCol + kingDifference);
    king->setCurrentPosition(newKingPosition);
    newRookPosition = getField(kingPositionRow, rookPositionCol + rookDifference);
    rook->setCurrentPosition(newRookPosition);
}

bool Table::isValidCastling(Move& move, bool castlingLongStatus, bool castlingShortStatus)
{
    auto king = move.getKingFigureInMove();
    auto rook = move.getRookFigureInMove();
    auto rookPosition = rook->getCurrentPosition();
    auto distanceBetweenKingAndRook = king->
            countPositionBetweenCurrentAndNextPosition(*rookPosition);
    bool isCastlingAllowed = distanceBetweenKingAndRook > 2 ?
                castlingLongStatus : castlingShortStatus;
    if(isCastlingAllowed == true)
    {
        if(!isFigureBetweenKingAndRook(king,rook))
            return false;
    }
    return isCastlingAllowed;
}

MoveResultValue Table::isChessOrChessMat(Figure* currentFigure)
{
    FigureColor currentFigureColor = currentFigure->getColor();
    FigureColor otherFigureColor = currentFigure->getOtherColor();

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

