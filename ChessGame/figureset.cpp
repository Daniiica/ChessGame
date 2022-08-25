#include "figureset.h"

Figure* FigureSet::figureOnPosition(Field position)
{
    for(auto itemPtr : _setfigures)
    {
        if(*(itemPtr->getCurrentPosition()) == position)
        {
            return itemPtr;
        }
    }
    return nullptr;
}

void FigureSet::setColor(FigureColor color)
{
    _setColor = color;
}

FigureColor FigureSet::getColor()
{
    return _setColor;
}

void FigureSet::setFigures(std::vector<Figure*> allFigures)
{
    _setfigures = allFigures;
}
std::vector<Figure*> FigureSet::getFiguresWithoutKing()
{
    std::vector<Figure*> figureSetWithoutKing;
    for(auto figurePtr : _setfigures)
    {
        if(figurePtr->getType() != FigureName::king && figurePtr->getState() == true)
        {
            figureSetWithoutKing.emplace_back(figurePtr);
        }
    }
    return figureSetWithoutKing;
}

std::vector<Figure*> FigureSet::getAllFigures()
{
    std::vector<Figure*> allActiveFigures;
    for(auto figurePtr : _setfigures)
    {
        if(figurePtr->getState() == true) // && figure->getCurrentPosition() != nullptr)
        {
            allActiveFigures.emplace_back(figurePtr);
        }
    }
    return allActiveFigures;
}

void FigureSet::addFigure(Figure* newFigurePtr)
{
    _setfigures.push_back(newFigurePtr);
}

void FigureSet::initializeFiguresOnStart(std::vector<Figure*> allFigures)
{
    _setfigures = allFigures;
}

std::vector<std::pair<int,int>> FigureSet::allAllowedMovesForOneFigureSet(
        std::vector<Figure*> figuresOnTable)
{
    std::vector<std::pair<int,int>> allAllowedMovesPerFigureSet;

    for(auto figurePtr : _setfigures)
    {
        auto allAllowedMovesPerFigure = figurePtr->allAllowedMoves(figuresOnTable);
        allAllowedMovesPerFigureSet.insert(allAllowedMovesPerFigureSet.end(),
                                           allAllowedMovesPerFigure.begin(),
                                           allAllowedMovesPerFigure.end());
    }
    return allAllowedMovesPerFigureSet;
}

Figure* FigureSet::createFigure(std::string replaceFigureName, FigureColor color, Field* positionPtr)
{
    Figure* newFigurePtr = nullptr;
    if(replaceFigureName == "rook")
    {
        RookFigure* rook = new RookFigure(color, positionPtr);
        return rook;
    }
    if(replaceFigureName == "knight")
    {
        KnightFigure* knight = new KnightFigure(color, positionPtr);
        return knight;
    }
    if(replaceFigureName == "bishop")
    {
        BishopFigure* bishop = new BishopFigure(color, positionPtr);
        return bishop;
    }
    if(replaceFigureName == "queen")
    {
        QueenFigure* queen = new QueenFigure(color, positionPtr);
        return queen;
    }
    return newFigurePtr;
}

void FigureSet::changePawnWithOtherFigure(Move& move)
{
    auto pawnFigurePtr = move.getCurrentFigure();
    auto pawnPositionPtr = pawnFigurePtr->getCurrentPosition();
    std::string replaceFigureName;
    auto pawnFigureColor = pawnFigurePtr->getColor();

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

   Figure* newFigurePtr = createFigure(replaceFigureName, pawnFigureColor, pawnPositionPtr);
   if(newFigurePtr != nullptr)
       replaceFigure(*pawnFigurePtr, newFigurePtr);
}

void FigureSet::replaceFigure(Figure& pawnFigure, Figure* newFigurePtr)
{
    addFigure(newFigurePtr);
    deleteFigure(&pawnFigure);
    pawnFigure = *newFigurePtr;
}

void FigureSet::deleteFigure(Figure* figureOnEndPositionPtr)
{
    auto figureIterator = _setfigures.begin();
    while(figureIterator != _setfigures.end() + 1)
    {
        if(*figureIterator == figureOnEndPositionPtr)
        {
            delete figureOnEndPositionPtr;
            _setfigures.erase(figureIterator);
        }
        ++figureIterator;
    }
}

void FigureSet::deleteFigures()
{
    for(auto &figure : _setfigures)
    {
       delete figure;
       figure = nullptr;
    }
}
