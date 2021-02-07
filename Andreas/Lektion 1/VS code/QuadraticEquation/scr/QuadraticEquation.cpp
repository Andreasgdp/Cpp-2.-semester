#include "../Headers/QuadraticEquation.h"
#include <math.h>
#include <tuple>
#include <complex>
#include <iostream>

QuadraticEquation::QuadraticEquation()
{
}

QuadraticEquation::QuadraticEquation(double a, double b, double c)
{
	mA = a;
	mB = b;
	mC = c;
}

std::tuple<double, double, bool> QuadraticEquation::solve() const
{
	// Negative determinant, imaginary
	if (double d = pow(mB, 2) - 4 * mA * mC < 0)
	{
		// Real number
		std::complex<double> imag(-mB / (2 * mA), sqrt(abs(pow(mB, 2) - 4 * mA * mC)) / (2 * mA));

		return {std::real(imag), std::imag(imag), true};
	}
	else
	{ // Positive determinant
		double x1 = (-mB + sqrt(pow(mB, 2) - 4 * mA * mC)) / (2 * mA);
		double x2 = (-mB - sqrt(pow(mB, 2) - 4 * mA * mC)) / (2 * mA);
		return {x1, x2, false};
	}
}
