#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Shape.h>

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(double height, double width);

    double area() override;

private:
    double _height, _width;
};

#endif // RECTANGLE_H
