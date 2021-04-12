#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle();

    double calcArea(double height, double width);
};

#endif // TRIANGLE_H
