#include "../Headers/Pi.h"
#include <math.h>

Pi::Pi(/* args */)
{
}

Pi::Pi(int order)
{
	mOrder = order;
}

Pi::~Pi()
{
}

double Pi::calcPi()
{
	mPi = 0;
	for (int i = 0; i < mOrder; i++)
	{
		mPi += ((pow(-1, i) * (1 / (2 * static_cast<double>(i) + 1))));
	}

	mPi *= 4;

	return mPi;
}
