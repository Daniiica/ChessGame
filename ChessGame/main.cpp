#include <iostream>
#include "game.h"
#include <string>
//#include <pdcurses.h>
#include "chesstablefactory.h"
#include "startgameinitializetablefactory.h"
#include "setchessexamplefactory.h"
#include "setchessmatexamplefactory.h"
#include <cstdlib>
#include "setcastlingexamplefactory.h"
#include "setpromotionexamplefactory.h"


int main()
{
    SetPromotionExampleFactory* tableFactoryPtr = new SetPromotionExampleFactory();
    Game game(tableFactoryPtr);
    game.start();

    return 0;
}
