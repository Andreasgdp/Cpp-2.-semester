#include "Shape.h"

Shape::Shape() {
    _name = "Deafult name";
}

// Constructor with name
Shape::Shape(const std::string& name) {
    _name = name;
}

// Name
void Shape::setName(const std::string& name) {
    _name = name;
}

const std::string& Shape::getName() const {
    return _name;
}
