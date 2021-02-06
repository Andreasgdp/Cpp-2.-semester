#ifndef CLOTHINGCALC_H
#define CLOTHINGCALC_H

#pragma once

class ClothingCalc
{
public:
	ClothingCalc();
	ClothingCalc(double height, double weight, unsigned int age);

	void setHeight(double height);
	void setWeight(double weight);
	void setAge(unsigned int age);

	double calcHat() const;
	double calcJacket() const;
	double calcWaist() const;

private:
	double mHeight, mWeight;
	unsigned int mAge;
	unsigned int yearsOverX(unsigned int x, unsigned int fullYears) const;
};

#endif // !CLOTHINGCALC_H
