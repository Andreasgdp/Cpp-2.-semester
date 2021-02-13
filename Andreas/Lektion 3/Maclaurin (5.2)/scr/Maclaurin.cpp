#include "../Headers/Maclaurin.h"
#include <math.h>
#include <iostream>

Maclaurin::Maclaurin(/* args */)
{
}

Maclaurin::Maclaurin(int x, int order)
{
	mX = x;
	mOrder = order;
}

long double Maclaurin::calcAproxOfEx()
{
	long double ex = 1;
	for (int i = 1; i < mOrder; ++i)
	{
		ex += (1 / (calcFactorial(i))) * pow(mX, i);
	}

	return ex;
}

long double Maclaurin::calcFactorial(int order)
{
	long double factorial = 1;

	for (int i = 1; i <= order; ++i)
	{
		factorial *= i;
	}
	return factorial;
}

long double Maclaurin::calcAproxOfEx(int x, int order)
{
	long double ex = 1;
	for (int i = 1; i < order; ++i)
	{
		ex += (1 / (calcFactorial(i))) * pow(x, i);
	}

	return ex;
}
