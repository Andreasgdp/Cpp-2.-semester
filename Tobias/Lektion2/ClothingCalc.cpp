#include "ClothingCalc.h"
#include <math.h>

ClothingCalc::ClothingCalc()
{

}

ClothingCalc::ClothingCalc(double height, double weight, unsigned int age)
{
    mHeight = height;
    mWeight = weight;
    mAge    = age;

}

void ClothingCalc::setHeight(double height){
    mHeight = height;
}

void ClothingCalc::setWeight(double weight){
    mWeight = weight;
}

void ClothingCalc::setAge(unsigned int age){
    mAge = age;
}

double ClothingCalc::calcHat() {

        double hat = (mWeight/mHeight)*41.25*M_PI;
        return hat;
}

double ClothingCalc::calcJacket() {

    double jacket = (mHeight*mWeight)/355+1/8 * ClothingCalc::yearsOverX(30,10);
    return jacket;
}

double ClothingCalc::calcWaist() {
    double waist = mWeight/2.6 + 1/10 * ClothingCalc::yearsOverX(28, 2);
    return waist;
}

unsigned int ClothingCalc::yearsOverX(unsigned int x, unsigned int fullYears) const{
    if (mAge > x){

        return (mAge - x) % fullYears;
    } else
      return 0;
}
