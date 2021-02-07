#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H
#include <tuple>


class QuadraticEquation
{
public:
    QuadraticEquation();
    QuadraticEquation(double a, double b, double c);

    std::tuple<double, double, bool> solve() const;

private:
    double mA, mB, mC;
};

#endif // QUADRATICEQUATION_H
