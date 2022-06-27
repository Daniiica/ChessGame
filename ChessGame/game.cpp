#include "game.h"

Game::Game()
{
    _players[0] = Player(FigureColor::White);
    _players[1] = Player(FigureColor::Black);
    _table = Table();
}
FigureColor Game::getColorName(std::string fc)
{
    if(fc == "White")
        return FigureColor::White;
    else
        return FigureColor::Black;
}
bool Game::newMove(std::string color, std::string firstPosition, std::string secondPosition)
{
    Field* firstField = _table.getField(firstPosition);
    Field* secondField = _table.getField(secondPosition);

    Figure* figureOnField = _table.getFigureOnField(*firstField);
    if(figureOnField == nullptr)
    {
        std::cout << "There is no figure on position " + firstField->getValue() + "." << std::endl;
        return false;
    }

    FigureColor figureColor = color == "White" ? FigureColor::White : FigureColor::Black;

    int index = 0;

    if(figureColor == FigureColor::Black)
    {
        index = 1;
    }

    if(figureOnField->getColor() != figureColor)
    {
        std::cout << "The opponent's figure is on position " + firstField->getValue() + "." << std::endl;
        return false;
    }
    else
    {
        return _players[index].addNewMove(firstField,secondField,_table);
    }
}
