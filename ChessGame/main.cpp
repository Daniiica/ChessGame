#include <iostream>
#include "game.h"
#include <string>
#include <curses.h>

void inputParameters(std::string player, std::string& firstPosition,std::string& secondPosition)
{
    std::cout << "The " + player + " player is on the move \n" <<std::endl;
    std::cout << "Please enter current position" <<std::endl;
    std::cin >> firstPosition;
    std::cout << std::endl;
    std::cout << "Please enter next position" <<std::endl;
    std::cin >> secondPosition;
    std::cout << std::endl;
}

void inputMove(std::string player, std::string& firstPosition,std::string& secondPosition,Game& game)
{
    inputParameters(player,firstPosition,secondPosition);

    while(game.newMove(player,firstPosition,secondPosition) == false)
    {
        inputParameters(player,firstPosition,secondPosition);
    }
}

bool exitGame()
{
    char exit;
    std::cout << "Do you want to exit? ('y' or 'n') " << std::endl;
    std::cin >> exit;
    if(exit == 'y')
    {
        return false;
    }
    return true;
}
int main()
{
    std::string firstPlayer = "White";
    std::string secondPlayer = "Black";

    std::string firstPosition;
    std::string secondPosition;

    Game game;

    std::cout << "Welcome to Chess!\n" <<std::endl;

    while(firstPlayer != "")
    {
        inputMove(firstPlayer, firstPosition,secondPosition,game);
        inputMove(secondPlayer, firstPosition,secondPosition,game);
        if(!exitGame())
            break;
    }
    return 0;
}
