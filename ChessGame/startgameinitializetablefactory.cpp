#include "startgameinitializetablefactory.h"

StartGameInitializeTableFactory::StartGameInitializeTableFactory()
{

}

std::vector<Figure*> StartGameInitializeTableFactory::createFigures(FigureColor color)
{
    std::vector<Figure*> allFigures;
    //std::unique_ptr<Figure> rook1 = std::make_unique<RookFigure>(color);
    RookFigure* rook = new RookFigure(color);
    allFigures.push_back(rook);
    KnightFigure* knight = new KnightFigure(color);
    //std::unique_ptr<Figure> knight1 = std::make_unique<KnightFigure>(color);
    allFigures.push_back(knight);
    BishopFigure* bishop = new BishopFigure(color);
    //std::unique_ptr<Figure> bishop1 = std::make_unique<BishopFigure>(color);
    allFigures.push_back(bishop);
    QueenFigure* queen = new QueenFigure(color);
    //std::unique_ptr<Figure> queen = std::make_unique<QueenFigure>(color);
    allFigures.push_back(queen);
    KingFigure* king = new KingFigure(color);
    //std::unique_ptr<Figure> king = std::make_unique<KingFigure>(color);
    allFigures.push_back(king);
   //std::unique_ptr<Figure> bishop2 = std::make_unique<BishopFigure>(color);
    bishop = new BishopFigure(color);
    allFigures.push_back(bishop);
    //std::unique_ptr<Figure> knight2 = std::make_unique<KnightFigure>(color);
    knight = new KnightFigure(color);
    allFigures.push_back(knight);
    //std::unique_ptr<Figure> rook2 = std::make_unique<RookFigure>(color);
    rook = new RookFigure(color);
    allFigures.push_back(rook);
    PawnFigure* pawn;
    for(int i = 0; i < 8 ; i++)
    {
        pawn = new PawnFigure(color);
        //std::unique_ptr<Figure> pawn = std::make_unique<PawnFigure>(color);
        allFigures.push_back(pawn);
    }
    return allFigures;
}

Table* StartGameInitializeTableFactory::createTable()
{
        Table* table = new Table();
        FigureSet blackFigureSet;
        blackFigureSet.setColor(FigureColor::Black);
        blackFigureSet.initializeFiguresOnStart(createFigures(FigureColor::Black));
        FigureSet whiteFigureSet;
        whiteFigureSet.setColor(FigureColor::White);
        whiteFigureSet.initializeFiguresOnStart(createFigures(FigureColor::White));
        auto blackFigures = blackFigureSet.getAllFigures();
        auto whiteFigures = whiteFigureSet.getAllFigures();
        auto blackFiguresIt = blackFigures.begin();
        auto whiteFiguresIt = whiteFigures.begin();
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0; j < 8 ; j++)
            {
                (*whiteFiguresIt)->setCurrentPosition(table->getField(i,j)); //_fields[i][j]);
                (*blackFiguresIt)->setCurrentPosition(table->getField(7-i,j));//_fields[7-i][j]);
                whiteFiguresIt++;
                blackFiguresIt++;
            }
        }
        table->setFigureSet(blackFigureSet,0);
        table->setFigureSet(whiteFigureSet,1);

        return table;
}
