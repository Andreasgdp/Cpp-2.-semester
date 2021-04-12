#include "Circle.h"
#include <math.h>

Circle::Circle()
{

}

double Circle::calcArea(double radius) {
    return mArea = M_PI * pow(radius, 2);
}
