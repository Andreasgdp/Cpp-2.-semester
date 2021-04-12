#include "Triangle.h"

Triangle::Triangle()
{

}

double Triangle::calcArea(double height, double width) {
    return mArea = 0.5 * height * width;
}
