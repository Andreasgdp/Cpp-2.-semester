#include "QuadraticEquation.h"
#include <math.h>
#include <tuple>
#include <complex>
#include <iostream>

typedef complex<double> dcomp;

QuadraticEquation::QuadraticEquation() {

}

QuadraticEquation::QuadraticEquation(double a, double b, double c) {
    mA = a;
    mB = b;
    mC = c;
}

std::tuple<double, double, bool> QuadraticEquation::solve() const {
    // Negative determinant, imaginary
    if (double d = pow(mB, 2) - 4 * mA * mC < 0) {
        std::complex<double> imag1(-mB / (2 * mA), sqrt(-pow(mB, 2) - 4 * mA * mC) / (2 * mA));
        std::complex<double> imag2 = -mB / (2 * mA) - sqrt(-pow(mB, 2) - 4 * mA * mC) / (2 * mA);

        return {std::real(imag1), std::imag(imag1), true};

    } else {    // Positive determinant
        double x1 = (-mB + sqrt(pow(mB, 2) - 4 * mA * mC)) / (2 * mA);
        double x2 = (-mB - sqrt(pow(mB, 2) - 4 * mA * mC)) / (2 * mA);
        return {x1, x2, false};
    }
}
