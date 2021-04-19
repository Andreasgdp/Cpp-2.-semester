#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
    Shape();
    virtual double area() {return _area;};
private:
    double _area;
};

#endif // SHAPE_H
