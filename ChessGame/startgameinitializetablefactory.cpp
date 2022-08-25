#include "startgameinitializetablefactory.h"

StartGameInitializeTableFactory::StartGameInitializeTableFactory()
{

}

std::vector<Figure*> StartGameInitializeTableFactory::createFigures(FigureColor color)
{
    std::vector<Figure*> allFigures{};
    //std::unique_ptr<Figure> rook1 = std::make_unique<RookFigure>(color);
    RookFigure* rookPtr = new RookFigure(color);
    allFigures.push_back(rookPtr);

    KnightFigure* knightPtr = new KnightFigure(color);
    //std::unique_ptr<Figure> knight1 = std::make_unique<KnightFigure>(color);
    allFigures.push_back(knightPtr);

    BishopFigure* bishopPtr = new BishopFigure(color);
    //std::unique_ptr<Figure> bishop1 = std::make_unique<BishopFigure>(color);
    allFigures.push_back(bishopPtr);

    QueenFigure* queenPtr = new QueenFigure(color);
    //std::unique_ptr<Figure> queen = std::make_unique<QueenFigure>(color);
    allFigures.push_back(queenPtr);

    KingFigure* kingPtr = new KingFigure(color);
    //std::unique_ptr<Figure> king = std::make_unique<KingFigure>(color);
    allFigures.push_back(kingPtr);

   //std::unique_ptr<Figure> bishop2 = std::make_unique<BishopFigure>(color);
    bishopPtr = new BishopFigure(color);
    allFigures.push_back(bishopPtr);

    //std::unique_ptr<Figure> knight2 = std::make_unique<KnightFigure>(color);
    knightPtr = new KnightFigure(color);
    allFigures.push_back(knightPtr);

    //std::unique_ptr<Figure> rook2 = std::make_unique<RookFigure>(color);
    rookPtr = new RookFigure(color);
    allFigures.push_back(rookPtr);

    PawnFigure* pawnPtr;
    for(int i = 0; i < 8 ; i++)
    {
        pawnPtr = new PawnFigure(color);
        //std::unique_ptr<Figure> pawn = std::make_unique<PawnFigure>(color);
        allFigures.push_back(pawnPtr);
    }
    return allFigures;
}

Table* StartGameInitializeTableFactory::createTable()
{
        Table* tablePtr = new Table();
        FigureSet blackFigureSet;
        FigureSet whiteFigureSet;

        blackFigureSet.setColor(FigureColor::Black);
        whiteFigureSet.setColor(FigureColor::White);

        auto blackFigures = createFigures(FigureColor::Black);
        blackFigureSet.initializeFiguresOnStart(blackFigures);

        auto whiteFigures = createFigures(FigureColor::White);
        whiteFigureSet.initializeFiguresOnStart(whiteFigures);

        auto blackFiguresIt = blackFigures.begin();
        auto whiteFiguresIt = whiteFigures.begin();

        Field* whiteFieldPtr;
        Field* blackFieldPtr;

        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0; j < 8 ; j++)
            {
                whiteFieldPtr = tablePtr->getField(i,j);
                (*whiteFiguresIt)->setCurrentPosition(whiteFieldPtr);
                blackFieldPtr = tablePtr->getField(7-i, j);
                (*blackFiguresIt)->setCurrentPosition(blackFieldPtr);
                whiteFiguresIt++;
                blackFiguresIt++;
            }
        }
        tablePtr->setFigureSet(blackFigureSet,0);
        tablePtr->setFigureSet(whiteFigureSet,1);

        return tablePtr;
}
