#include "Polynomial.h"

Polynomial::Polynomial() {}

// Tilføj led til polynomie (e.g. 2x^3)
void Polynomial::addTerm(const PolynomialTerm &term) {
    _vecPoly.push_back(term);
}

// Beregn polynomiets værdi ved given x-værdi
double Polynomial::evaluate(double x) {
    double res = 0;
    for (size_t i = 0; i < _vecPoly.size(); i++) {
        res += _vecPoly[i].evaluate(x);
    }
    return res;
}

std::ostream &operator<<(std::ostream &out, const Polynomial &p) {
    for (size_t i = 0; i < p._vecPoly.size(); i++) {
        out << p._vecPoly[i].getCoefficient() << "x^" << p._vecPoly[i].getPower();
    }
    return out;
}
