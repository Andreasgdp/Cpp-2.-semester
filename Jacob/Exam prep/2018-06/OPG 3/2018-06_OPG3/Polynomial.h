#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "PolynomialTerm.h"
#include <vector>
#include <iostream>

class Polynomial
{
public:
    Polynomial();

    void addTerm(const PolynomialTerm& term); // Tilføj led til polynomie (e.g. 2x^3)
    double evaluate(double x); // Beregn polynomiets værdi ved given x-værdi
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);

private:
    std::vector<PolynomialTerm> _vecPoly;
};

#endif // POLYNOMIAL_H
