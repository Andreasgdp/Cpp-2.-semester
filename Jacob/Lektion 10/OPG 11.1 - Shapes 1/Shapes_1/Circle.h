#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle();

    double calcArea(double radius);
};

#endif // CIRCLE_H
