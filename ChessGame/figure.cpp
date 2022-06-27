#include "figure.h"

Figure::Figure(FigureColor color, FigureName type, Field currentPosition, bool state)
    :_color{color},_type{type},_currentPosition{currentPosition},_state{state}
{
}
Figure::Figure(FigureColor color)
    :_color{color}
{
}
Field Figure::getCurrentPosition()
{
    return _currentPosition;
}
FigureName Figure::getType()
{
    return _type;
}
FigureColor Figure::getColor()
{
    return _color;
}
void Figure::setCurrentPosition(Field position)
{
    _currentPosition = position;
}
void Figure::setActiveState()
{
    _state = true;
}
void Figure::setEatenState()
{
    _state = false;
}
bool Figure::operator==(const Figure &rhs) const
{
    if(this->_color == rhs._color && this->_currentPosition == rhs._currentPosition
            && this->_type == rhs._type && this->_state == rhs._state)
    {
        return true;
    }
    return false;
}
