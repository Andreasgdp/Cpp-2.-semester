#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
    PolynomialTerm t0(3.0, 0);
    PolynomialTerm t1(1.0, 1);
    PolynomialTerm t2(1.0, 2);
    PolynomialTerm t3;
    t3.setCoefficient(2.1);
    t3.setPower(3);
    Polynomial p1;
    p1.addTerm(t1);
    std::cout << "p1(0) = " << p1.evaluate(0) << std::endl;
    std::cout << "p1(1) = " << p1.evaluate(1) << std::endl;
    std::cout << "p1(2) = " << p1.evaluate(2) << std::endl;
    Polynomial p2;
    p2.addTerm(t0);
    p2.addTerm(t2);
    std::cout << "p2(0) = " << p2.evaluate(0) << std::endl;
    std::cout << "p2(1) = " << p2.evaluate(1) << std::endl;
    std::cout << "p2(2) = " << p2.evaluate(2) << std::endl;
    Polynomial p3;
    p3.addTerm(t0);
    p3.addTerm(t1);
    p3.addTerm(t2);
    p3.addTerm(t3);
    std::cout << "p3(0) = " << p3.evaluate(0) << std::endl;
    std::cout << "p3(1) = " << p3.evaluate(1) << std::endl;
    std::cout << "p3(2) = " << p3.evaluate(2) << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
}
