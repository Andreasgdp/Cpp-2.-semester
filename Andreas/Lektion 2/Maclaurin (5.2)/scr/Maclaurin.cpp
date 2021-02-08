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

unsigned long long Maclaurin::calcAproxOfEx()
{
	unsigned long long ex = 0;
	for (int i = 1; i < mOrder; ++i)
	{
		ex += (1 / (calcFactorial(i))) * pow(mX, i);
	}

	return ex;
}

unsigned long long Maclaurin::calcFactorial(int order)
{
	unsigned long long factorial = 1;

	for (int i = 1; i <= order; ++i)
	{
		factorial *= i;
	}
	std::cout << factorial << std::endl;
	return factorial;
}

unsigned long long Maclaurin::calcAproxOfEx(int x, int order)
{
	unsigned long long ex = 0;
	for (int i = 1; i < order; ++i)
	{
		ex += (1 / (calcFactorial(i))) * pow(x, i);
	}

	return ex;
}
