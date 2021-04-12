#include <iostream>
#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Triangle.h>

using namespace std;

int main()
{
    Circle c1(10);
    cout << "c1: " << c1.area() << endl;

    Rectangle r1(10, 10);
    cout << "r1: " << r1.area() << endl;

    Triangle t1(10, 10);
    cout << "t1: " << t1.area() << endl;


    return 0;
}
