#include "Circle.h"
#include <math.h>

Circle::Circle() {

}

Circle::Circle(double radius) {
    _radius = radius;
}

double Circle::area() {
    return M_PI * pow(_radius, 2);
}
