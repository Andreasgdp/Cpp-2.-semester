#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square: public Shape
{
public:
    Square();
    Square(double height, double width);

    double height() const;
    void setHeight(double height);

    double witdh() const;
    void setWitdh(double witdh);

    double area() override;

private:
    double _height, _width;
};

#endif // SQUARE_H
