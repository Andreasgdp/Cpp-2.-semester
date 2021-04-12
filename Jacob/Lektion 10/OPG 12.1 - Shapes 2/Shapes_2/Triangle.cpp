#include "Triangle.h"

Triangle::Triangle() {

}

Triangle::Triangle(double height, double width) {
    _height = height;
    _width = width;
}

double Triangle::area() {
    return 0.5 * _height * _width;
}
