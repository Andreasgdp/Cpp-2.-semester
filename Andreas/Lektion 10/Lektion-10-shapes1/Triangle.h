#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"


class Triangle : public Shape
{
public:
    Triangle(double length = 0, double height = 0) {_length = length; _height = height;};
    double area() override {return 0.5 * _height * _length;};
private:
    double _length, _height;
};

#endif // TRIANGLE_H
