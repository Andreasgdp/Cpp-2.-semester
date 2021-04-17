#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double length = 0, double height = 0) {_length = length; _height = height;};
    double area() override {return _height * _length;};
private:
    double _length, _height;
};

#endif // RECTANGLE_H
