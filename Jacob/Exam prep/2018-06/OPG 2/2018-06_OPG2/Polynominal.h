#ifndef POLYNOMINAL_H
#define POLYNOMINAL_H

#include "sstream"
#include "vector"

class Polynominal
{
public:
    Polynominal();
    std::vector<std::pair<double, int> > readPolynomial(std::string& p);
};

#endif // POLYNOMINAL_H
