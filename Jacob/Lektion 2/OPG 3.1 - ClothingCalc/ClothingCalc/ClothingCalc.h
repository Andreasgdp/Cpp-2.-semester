#ifndef CLOTHINGCALC_H
#define CLOTHINGCALC_H


class ClothingCalc
{
public:
    ClothingCalc();
    ClothingCalc(double height, double weight, unsigned int age);

    double calcHat();
    double calcJacket();
    double calcWaist();

private:
    double mHeight, mWeight;
    unsigned int mAge;

};

#endif // CLOTHINGCALC_H
