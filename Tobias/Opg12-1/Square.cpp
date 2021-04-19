#include "Square.h"

Square::Square()
{

}

Square::Square(double height, double width)
{
    _height = height;
    _width = width;
}

double Square::height() const
{
    return _height;
}

void Square::setHeight(double height)
{
    _height = height;
}

double Square::witdh() const
{
    return _width;
}

void Square::setWitdh(double width)
{
    _width = width;
}

double Square::area()
{
    return (_height * _width);
}
