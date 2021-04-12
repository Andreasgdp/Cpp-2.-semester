#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    // Default constructor
    Shape();

    // Constructor with name
    Shape(const std::string& name);

    // Name
    void setName(const std::string& name);
    const std::string& getName() const;

    // Area
    virtual double area() = 0;

private:
    std::string _name;
};


#endif // SHAPE_H
