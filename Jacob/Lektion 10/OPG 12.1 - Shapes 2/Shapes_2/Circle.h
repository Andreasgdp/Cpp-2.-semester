#ifndef CIRCLE_H
#define CIRCLE_H

#include <Shape.h>

class Circle : public Shape
{
public:
    Circle();
    Circle(double radius);

    double area() override;

private:
    double _radius;
};

#endif // CIRCLE_H
