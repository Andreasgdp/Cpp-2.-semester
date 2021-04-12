#include "Rectangle.h"

Rectangle::Rectangle() {

}

Rectangle::Rectangle(double height, double width) {
    _height = height;
    _width = width;
}

double Rectangle::area() {
    return _height * _width;
}
