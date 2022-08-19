#include "game.h"

Game::Game(ChessTableFactory* tableFactory)
{
    _players[0] = Player(FigureColor::White);
    _players[1] = Player(FigureColor::Black);
    _table = tableFactory->createTable();
}

MoveResultValue Game::getMoveResult(Player& player, Move& move)
{
    if(!move.isCastling()) // da promenim ime
    {
        auto currentFigure = move.getCurrentFigure();
        auto secondFigure = move.getEndFigure();

        if (Figure::invalidEndFigure(currentFigure, secondFigure) == MoveResultValue::notValidMove)
            return MoveResultValue::notValidMove;

        return _table->isValidMove(move);
    }
    return castlingResult(player, move);
}

void Game::playMove(Move& move, Field* endPosition)
{
    auto startPosition = move.getStartPosition();
    auto eatenFigure = move.getEndFigure();
    auto currentFigure = move.getCurrentFigure();
    auto figureColor = currentFigure->getColor();
    auto otherFigureColor = currentFigure->getOtherColor();

    _table->moveFigure(move, endPosition);

    MoveResultValue isChess = _table->checkChess( figureColor, otherFigureColor);
    if (isChess == MoveResultValue::chess)
    {
        _table->undoMove(*startPosition, currentFigure, eatenFigure);
        TextLogger::logWarning("Your king will be attack!");
    }

}

bool Game::isChessMat(Figure* currentFigure)
{
    if(_table->isChessOrChessMat(currentFigure) == MoveResultValue::chessMat)
        return true;
    return false;
}

void Game::doCastling(Player& player, Move& move)
{
    _table->castling(move);
    player.disableCastlingStatus();
}

MoveResultValue Game::castlingResult(Player& player, Move& move)
{
    auto castlingLongStatus = player.getCastlingLongStatus();
    auto castlingShortStatus = player.getCastlingShortStatus();

    if(_table->isValidCastling(move, castlingLongStatus, castlingShortStatus))
    {
        doCastling(player, move);
        return MoveResultValue::validMove;
    }
    else
    {
        TextLogger::logWarning("Can't play castling!");
        return MoveResultValue::notValidMove;
    }
}

bool Game::startFigureValidation(Player& player, Field* startPosition)
{
    FigureColor playerColor = player.getColor();
    Figure* figureOnStartPosition = _table->getFigureOnField(*startPosition);
    auto validationStartFigure = Figure::invalidStartFigure(startPosition, figureOnStartPosition, playerColor);

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

    *startPosition = _table->getField(userFirstInput);
    *endPosition = _table->getField(userSecondInput);

    if(Field::invalidField(*startPosition, *endPosition) == InputResultValue::notValidInput) // samo da vrati rezultat fje i da bude isInvalidField
        return InputResultValue::notValidInput; // bolje 2x da zovem fju
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
    BoardVisualizer::printTable(*_table);

    run();
}

Table* Game::getTable()
{
    return _table;
}
void Game::run()
{
    std::string userFirstInput {}; // = "";
    std::string userSecondInput {};
    int playerIndex = 0;

    Field* startPosition = nullptr;
    Field* endPosition = nullptr;
    Figure* currentFigure = nullptr;
    Figure* eatenFigure = nullptr;

    bool isChess = false;
    InputResultValue inputResultValue = InputResultValue::validInput;

    while(inputResultValue != InputResultValue::exit &&
          isChess != true)
    {
        outputTitle(_players[playerIndex]);
        setInputPositions(userFirstInput, userSecondInput);
        inputResultValue = getInputResult(userFirstInput, userSecondInput,
                                          &startPosition, &endPosition);
        if(inputResultValue == InputResultValue::validInput &&
                startFigureValidation(_players[playerIndex], startPosition))
        {
            currentFigure = _table->getFigureOnField(*startPosition);
            eatenFigure = _table->getFigureOnField(*endPosition);
            Move move(*startPosition, *endPosition, currentFigure, eatenFigure);
            if(getMoveResult(_players[playerIndex], move) == MoveResultValue::validMove)
            {
                playMove(move, endPosition);
                changePlayer(playerIndex);
                BoardVisualizer::printTable(*_table);
                isChess = isChessMat(currentFigure);
            }
        }
    }
}

void Game::changePlayer(int& playersIndex)
{
    playersIndex == 0 ? playersIndex++ : playersIndex--;
}
