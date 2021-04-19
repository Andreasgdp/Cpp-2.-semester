#include "Triangle.h"

Triangle::Triangle()
{

}

Triangle::Triangle(double height, double width)
{
    _height = height;
    _width = width;
}

double Triangle::area()
{
    return (1/2 * _height * _width);
}
