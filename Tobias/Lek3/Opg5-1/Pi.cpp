#include "Pi.h"
#include <math.h>

Pi::Pi()
{
    mOrder = 0;
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
    for (double i = 0; i < mOrder; i++)
    {
        mPi += ((pow(-1, i) * (1 / (2 * i + 1))));
    }

    mPi *= 4;

    return mPi;
}
