#include "figureset.h"

FigureSet::FigureSet(FigureColor color)
{

    //    for(int j = 0 ; j < 2 ; j++)
    //    {
    //        BishopFigure bishop;
    //        KnightFigure knight;
    //        RookFigure rook;

    //        _setfigures.push_back(&rook);
    //        _setfigures.push_back(&knight);
    //        _setfigures.push_back(&bishop);

    //        if(j == 0)
    //        {
    //            KingFigure king;
    //            QueenFigure queen;
    //            _setfigures.push_back(&king);
    //            _setfigures.push_back(&queen);
    //        }
    //    }
    //    for(int j = 0 ; j < 8 ; j++)
    //    {
    //        PawnFigure pawn;
    //        _setfigures.push_back(&pawn);
    //    }


}
FigureSet::FigureSet(std::vector<Figure*> figures)
   // :_setfigures{figures}
{

}
Figure* FigureSet::figureOnPosition(Field position)
{
    for(auto item : _setfigures)
    {
        if(item->getCurrentPosition() == position)
        {
            return item;
        }
    }
    return nullptr;
}
void FigureSet::setColor(FigureColor color)
{
    _setColor = color;
}
void FigureSet::removeEatenFigure(Figure* eatenFigure)
{
    for(auto it = _setfigures.begin(); it < _setfigures.end(); it++)
    {
        if(eatenFigure == *it)
        {
            _setfigures.erase(it);
        }
    }
}
void FigureSet::editFigure(Figure* figure)
{

}
void FigureSet::addFigure(Figure* newFigure)
{
    _setfigures.push_back(newFigure);
}
std::vector<Figure*> FigureSet::getFigures()
{
    return _setfigures;
}
Figure* FigureSet::getFigureOnPosition(Field position)
{
    for(auto item : _setfigures)
    {
        if(item->getCurrentPosition() == position)
            return item;
    }
    return nullptr;
}
void FigureSet::initializeFiguresOnStart(FigureColor color)
{
    _setColor = color;

    RookFigure* rook = new RookFigure(color);
    _setfigures.push_back(rook);
    KnightFigure* knight = new KnightFigure(color);
    _setfigures.push_back(knight);
    BishopFigure* bishop = new BishopFigure(color);
    _setfigures.push_back(bishop);
    KingFigure* king = new KingFigure(color);
    _setfigures.push_back(king);
    QueenFigure* queen = new QueenFigure(color);
    _setfigures.push_back(queen);
    bishop = new BishopFigure(color);
    _setfigures.push_back(bishop);
    knight = new KnightFigure(color);
    _setfigures.push_back(knight);
    rook = new RookFigure(color);
    _setfigures.push_back(rook);
    PawnFigure* pawn = nullptr;
    for(int i = 0; i < 8 ; i++)
    {
        pawn = new PawnFigure(color);
        _setfigures.push_back(pawn);
    }
}
