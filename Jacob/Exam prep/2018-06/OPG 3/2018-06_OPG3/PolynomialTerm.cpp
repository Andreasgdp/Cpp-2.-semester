#include "PolynomialTerm.h"
#include <cmath>

PolynomialTerm::PolynomialTerm() {
    _coeff = 0;
    _power = 0;
}


// Get-funktioner for member variable
int PolynomialTerm::getPower() const {
    return _power;
}

double PolynomialTerm::getCoefficient() const {
    return _coeff;
}

// Set-funktioner for member variable
void PolynomialTerm::setPower(int power) {
    _power = power;
}

void PolynomialTerm::setCoefficient(double coeff) {
    _coeff = coeff;
}

// Beregn ledets værdi når værdien for x kendes (parameteren)
double PolynomialTerm::evaluate(double x) {
    return _coeff * pow(x, _power);
}
