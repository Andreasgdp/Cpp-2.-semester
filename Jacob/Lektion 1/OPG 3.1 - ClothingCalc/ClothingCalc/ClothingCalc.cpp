#include "ClothingCalc.h"
#include <math.h>

ClothingCalc::ClothingCalc() {

}

ClothingCalc::ClothingCalc(double height, double weight, unsigned int age) {
    mHeight = height;
    mWeight = weight;
    mAge = age;
}

double ClothingCalc::calcHat() {
    return (mWeight / mHeight) * 41.25 * M_PI;
}

double ClothingCalc::calcJacket() {
    unsigned int AgeAdjustment = 0;
    if (mAge > 30) {
        AgeAdjustment = (mAge - 30) % 10 / 8;
    }
    return (mHeight * mWeight) / 335 + AgeAdjustment;
}

double ClothingCalc::calcWaist() {
    unsigned int AgeAdjustment = 0;
    if (mAge > 28) {
        AgeAdjustment = (mAge - 28) % 2 / 10;
    }
    return mWeight / 2.6 + AgeAdjustment;
}
