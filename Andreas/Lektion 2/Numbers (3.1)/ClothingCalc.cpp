#include "ClothingCalc.h"
#include <math.h>

ClothingCalc::ClothingCalc()
{
}

ClothingCalc::ClothingCalc(double height, double weight, unsigned int age)
{
	mHeight = height;
	mWeight = weight;
	mAge = age;
}

void ClothingCalc::setHeight(double height)
{
	mHeight = height;
}

void ClothingCalc::setWeight(double weight)
{
	mWeight = weight;
}

void ClothingCalc::setAge(unsigned int age)
{
	mAge = age;
}

double ClothingCalc::calcHat() const
{
	return mWeight / mHeight * 41.25 * atan(1) * 4;
}

double ClothingCalc::calcJacket() const
{
	return mHeight * mWeight / 335 + 1 / 8 * ClothingCalc::yearsOverX(30, 10);
}

double ClothingCalc::calcWaist() const
{
	return mWeight / 2.6 + 1 / 10 * ClothingCalc::yearsOverX(28, 2);
}

unsigned int ClothingCalc::yearsOverX(unsigned int x, unsigned int fullYears) const
{
	return (mAge > x) ? (mAge - x) % fullYears : 0;
}

double ClothingCalc::calcLeg() const
{
	return 0.0;
}
