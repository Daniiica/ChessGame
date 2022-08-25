#include "game.h"

Game::Game(ChessTableFactory* tableFactoryPtr)
{
    _players[0] = Player(FigureColor::White);
    _players[1] = Player(FigureColor::Black);
    _tablePtr = tableFactoryPtr->createTable();
}

MoveResultValue Game::getMoveResult(Player& player, Move& move)
{
    if(!move.isCastling())
    {
        auto currentFigurePtr = move.getCurrentFigure();
        auto secondFigurePtr = move.getEndFigure();

        if (Figure::invalidEndFigure(currentFigurePtr, secondFigurePtr) == MoveResultValue::notValidMove)
            return MoveResultValue::notValidMove;

        return _tablePtr->isValidMove(move);
    }
    return castlingResult(player, move);
}

void Game::playMove(Move& move)
{
    auto eatenFigurePtr = move.getEndFigure();
    auto currentFigurePtr = move.getCurrentFigure();

    if(eatenFigurePtr != nullptr && currentFigurePtr->getColor() == eatenFigurePtr->getColor())
    {
        _tablePtr->castling(move);
    }
    else
    {
        _tablePtr->moveFigure(move);
    }
}

bool Game::isSelfChess(Figure* currentFigurePtr)
{
    auto figureColor = currentFigurePtr->getColor();
    auto opponentsFigureColor = currentFigurePtr->getOtherColor();

    return _tablePtr->checkChess(figureColor, opponentsFigureColor) == MoveResultValue::chess ?
           true : false;
}

void Game::cancelMove(Field* startPositionPtr, Move& move)
{
    _tablePtr->undoMove(*startPositionPtr, move);
    TextLogger::logWarning("Your king will be attack!");
}

Game::~Game()
{
    delete _tablePtr;
    _tablePtr = nullptr;
}

bool Game::isChessMat(Figure* currentFigurePtr)
{
    return _tablePtr->isChessOrChessMat(currentFigurePtr) == MoveResultValue::chessMat ?
                true : false;
}

MoveResultValue Game::castlingResult(Player& player, Move& move)
{
    auto castlingLongStatus = player.getCastlingLongStatus();
    auto castlingShortStatus = player.getCastlingShortStatus();

    if(_tablePtr->isValidCastling(move, castlingLongStatus, castlingShortStatus))
    {
        return MoveResultValue::validMove;
    }
    else
    {
        TextLogger::logWarning("Can't play castling!");
        return MoveResultValue::notValidMove;
    }
}

bool Game::startFigureValidation(Player& player, Field* startPositionPtr)
{
    FigureColor playerColor = player.getColor();
    Figure* figureOnStartPositionPtr = _tablePtr->getFigureOnField(*startPositionPtr);
    auto validationStartFigure = Figure::invalidStartFigure(startPositionPtr, figureOnStartPositionPtr, playerColor);

    return validationStartFigure == MoveResultValue::notValidMove ? false : true;
}

void Game::outputTitle(Player& player)
{
    auto color = player.getColor();
    std::string text = "The " + player.getName() + " player is on the move \n" + "Please enter move ";
    TextLogger::logFigureName(text,color);
}

InputResultValue Game::getInputResult(std::string& userFirstInput, std::string& userSecondInput,
                                      Field** startPosition, Field** endPosition)
{
    if(isEndGame(userFirstInput))
        return InputResultValue::exit;

    *startPosition = _tablePtr->getField(userFirstInput);
    *endPosition = _tablePtr->getField(userSecondInput);

    if(Field::invalidField(*startPosition) == InputResultValue::notValidInput ||
            Field::invalidField(*endPosition) == InputResultValue::notValidInput)
        return InputResultValue::notValidInput;
    return InputResultValue::validInput;
}

void Game::setInputPositions(std::string& userFirstInput, std::string& userSecondInput) // getInputPositions
{
    std::cin >> userFirstInput;
    if(!isEndGame(userFirstInput)) // da imam test za 1. input  = quit i za 2. input = quit
        std::cin >> userSecondInput;
}

bool Game::isEndGame(std::string userFirstInput)
{
    return userFirstInput == "quit" ? true : false;
}

void Game::start()
{
    TextLogger::logTitle("Welcome to Chess!");
    BoardVisualizer::printTable(*_tablePtr);

    run();
}

Table* Game::getTable()
{
    return _tablePtr;
}
void Game::run()
{
    std::string userFirstInput {};
    std::string userSecondInput {};
    int playerIndex = 0;

    Field* startPositionPtr = nullptr;
    Field* endPositionPtr = nullptr;
    Figure* currentFigurePtr = nullptr;
    Figure* eatenFigurePtr = nullptr;

    bool isChess = false;
    InputResultValue inputResultValue = InputResultValue::validInput;

    while(inputResultValue != InputResultValue::exit &&
          isChess != true)
    {
        outputTitle(_players[playerIndex]);
        setInputPositions(userFirstInput, userSecondInput);
        inputResultValue = getInputResult(userFirstInput, userSecondInput,
                                          &startPositionPtr, &endPositionPtr);
        if(inputResultValue == InputResultValue::validInput &&
                startFigureValidation(_players[playerIndex], startPositionPtr))
        {
            currentFigurePtr = _tablePtr->getFigureOnField(*startPositionPtr);
            eatenFigurePtr = _tablePtr->getFigureOnField(*endPositionPtr);
            Move move(*startPositionPtr, *endPositionPtr, currentFigurePtr, eatenFigurePtr);

            if(getMoveResult(_players[playerIndex], move) == MoveResultValue::validMove)
            {
                playMove(move);

                if(isSelfChess(currentFigurePtr))
                {
                    cancelMove(startPositionPtr, move);
                }
                else
                {
                    _tablePtr->pawnOnEndTable(move);
                    if(eatenFigurePtr != nullptr)
                    {
                        if(currentFigurePtr->getColor() == eatenFigurePtr->getColor())
                        {
                            _players[playerIndex].disableCastlingStatus();
                        }
                        else
                        {
                            _tablePtr->deleteEatenFigure(eatenFigurePtr);
                        }
                    }
                    _players[playerIndex].changeCastlingStatus(currentFigurePtr, startPositionPtr);
                    changePlayer(playerIndex);
                    BoardVisualizer::printTable(*_tablePtr);
                    isChess = isChessMat(currentFigurePtr);
                }
            }
        }
    }
}

void Game::changePlayer(int& playersIndex)
{
    playersIndex == 0 ? playersIndex++ : playersIndex--;
}

