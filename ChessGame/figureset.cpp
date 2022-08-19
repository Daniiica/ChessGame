#include "figureset.h"

Figure* FigureSet::figureOnPosition(Field position)
{
    for(auto item : _setfigures)
    {
        if(*(item->getCurrentPosition()) == position)
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

std::vector<Figure*> FigureSet::getFiguresWithoutKing()
{
    std::vector<Figure*> figureSetWithoutKing;
    for(auto figure : _setfigures)
    {
        if(figure->getType() != FigureName::king && figure->getState() == true)
        {
            figureSetWithoutKing.emplace_back(figure);
        }
    }
    return figureSetWithoutKing;
}

std::vector<Figure*> FigureSet::getAllFigures()
{
    std::vector<Figure*> allActiveFigures;
    for(auto figure : _setfigures)
    {
        if(figure->getState() == true) // && figure->getCurrentPosition() != nullptr)
        {
            allActiveFigures.emplace_back(figure);
        }
    }
    return allActiveFigures;
}

void FigureSet::addFigure(Figure* newFigure)
{
    _setfigures.push_back(newFigure);
}

void FigureSet::initializeFiguresOnStart(std::vector<Figure*> allFigures)
{
    _setfigures = allFigures;
}

std::vector<std::pair<int,int>> FigureSet::allAllowedMovesForOneFigureSet(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allAllowedMovesPerFigureSet;

    for(auto figure : _setfigures)
    {
        auto allAllowedMovesPerFigure = figure->allAllowedMoves(figuresOnTable);
        allAllowedMovesPerFigureSet.insert(allAllowedMovesPerFigureSet.end(),
                                           allAllowedMovesPerFigure.begin(),
                                           allAllowedMovesPerFigure.end());
    }
    return allAllowedMovesPerFigureSet;
}

void FigureSet::changePawnWithOtherFigure(Figure** pawnFigure)
{
    std::string replaceFigureName;
    auto pawnFigureColor = (*pawnFigure)->getColor();
    auto pawnPosition = (*pawnFigure)->getCurrentPosition();
    TextLogger::logFigureName(
                "Please enter the name of figure you want to exchange the pawn with.\n "
                "Choose between: rook knight bishop queen pawn\n", pawnFigureColor);
    while (replaceFigureName != "rook" &&
           replaceFigureName != "knight" &&
           replaceFigureName != "bishop" &&
           replaceFigureName != "queen" &&
           replaceFigureName != "pawn")
    {
        std::cin >> replaceFigureName;
    }

    if(replaceFigureName == "rook")
    {
        Figure* rook = new RookFigure(pawnFigureColor, pawnPosition);
        replaceFigure(pawnFigure, rook);
    }
    if(replaceFigureName == "knight")
    {
        KnightFigure* knight = new KnightFigure(pawnFigureColor, pawnPosition);
        replaceFigure(pawnFigure, knight);
    }
    if(replaceFigureName == "bishop")
    {
        BishopFigure* bishop = new BishopFigure(pawnFigureColor, pawnPosition);
        replaceFigure(pawnFigure, bishop);
    }
    if(replaceFigureName == "queen")
    {
        QueenFigure* queen = new QueenFigure(pawnFigureColor, pawnPosition);
        replaceFigure(pawnFigure, queen);
    }
    else
    {
        return;
    }
}

void FigureSet::replaceFigure(Figure** pawnFigure, Figure* newFigure)
{
    addFigure(newFigure);
    (*pawnFigure)->setEatenState();
    (*pawnFigure)->setCurrentPosition(nullptr);
    *pawnFigure = newFigure;
}

void FigureSet::deleteFigure(Figure* figureOnEndPosition) // da se proveri da li radi
{
    auto figureSetIterator = _setfigures.begin();
    while(figureSetIterator != _setfigures.end())
    {
        if(*figureSetIterator == figureOnEndPosition)
            _setfigures.erase(figureSetIterator);
    }
}
