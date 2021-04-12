#include <iostream>
#include <Shape.h>
#include <Circle.h>
#include <Rectangle.h>
#include <Triangle.h>


using namespace std;

int main()
{
    Shape s1;
    cout << "s1: " << s1.getArea() << endl;

    Circle c1;
    c1.calcArea(10);
    cout << "c1: " << c1.getArea() << endl;

    Rectangle r1;
    r1.calcArea(10, 10);
    cout << "r1: " << r1.getArea() << endl;

    Triangle t1;
    t1.calcArea(10, 10);
    cout << "t1: " << t1.getArea() << endl;


    return 0;
}
