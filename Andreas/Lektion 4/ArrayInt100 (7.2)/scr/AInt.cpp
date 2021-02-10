#include "../Headers/AInt.h"
#include <ctime>
#include <random>
#include <iostream>
#include <array>
#include <limits>

AInt::AInt(/* args */)
{
}

AInt::~AInt()
{
}

void AInt::fillArray(int aMinVal, int bMaxVal)
{
	std::default_random_engine engine{static_cast<unsigned int>(time(0))};
	std::uniform_int_distribution<unsigned int> random{aMinVal, bMaxVal};
	for (size_t i = 0; i < mArr.size(); i++)
	{
		mArr[i] = random(engine);
	}
}

int AInt::getMaxVal() const
{
	int maxVal = std::numeric_limits<int>::min();

	for (size_t i = 0; i < mArr.size(); i++)
	{
		maxVal = (mArr[i] > maxVal) ? maxVal = mArr[i] : maxVal;
	}

	return maxVal;
}

void AInt::printArray() const
{
	for (size_t i = 0; i < mArr.size(); i++)
	{
		std::cout << "value at '" << i << "' is: " << mArr[i] << std::endl;
	}
}

int AInt::countOccurs(int num) const
{
	int counter = 0;
	for (size_t i = 0; i < mArr.size(); i++)
	{
		counter = (mArr[i] == num) ? counter += 1 : counter;
	}
	return counter;
}

void AInt::swapElems()
{
}
