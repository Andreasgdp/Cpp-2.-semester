#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include "Shape.h"

class Circle : public Shape
{
public:
    Circle(double radius = 0) {_radius = radius;};
    double area() override {return 2 * 3.14159 * _radius;};
private:
    double _radius;
};

#endif // CIRCLE_H
