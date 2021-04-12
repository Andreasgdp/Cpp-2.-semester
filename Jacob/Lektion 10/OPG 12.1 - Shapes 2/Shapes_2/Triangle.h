#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Shape.h>

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(double height, double width);

    double area();

private:
    double _height, _width;
};

#endif // TRIANGLE_H
