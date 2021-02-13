#include "../Headers/Fibonacci.h"
#include <iostream>

Fibonacci::Fibonacci(/* args */)
{
}

Fibonacci::Fibonacci(int initialSize, int timePeriod, int updateDay)
{
	mInitialSize = initialSize;
	mTimePeroid = timePeriod;
	mUpdateDay = updateDay;
}

Fibonacci::~Fibonacci()
{
}

void Fibonacci::setUpdateDay(int updateDay)
{
	mUpdateDay = updateDay;
}

void Fibonacci::setInitialSize(int initialSize)
{
	mInitialSize = initialSize;
}

void Fibonacci::setTimePeroid(int timePeroid)
{
	mTimePeroid = timePeroid;
}

void Fibonacci::calcCrud()
{
	int temp;
	int counter = 0;
	int f1 = 0;
	int f2 = mInitialSize;
	while (counter < mTimePeroid / mUpdateDay)
	{
		temp = f1 + f2;
		f1 = f2;
		f2 = temp;
		counter += 1;
	}

	mInitialSize = temp;
}

int Fibonacci::getCurrSize() const
{
	return mInitialSize;
}
