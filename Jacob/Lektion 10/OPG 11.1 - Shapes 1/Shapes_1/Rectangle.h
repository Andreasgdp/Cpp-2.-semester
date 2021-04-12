#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();

    double calcArea(double height, double width);
};

#endif // RECTANGLE_H
