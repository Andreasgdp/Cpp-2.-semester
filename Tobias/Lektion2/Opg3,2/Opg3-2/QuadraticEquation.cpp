#include "QuadraticEquation.h"
#include  <cmath>

QuadraticEquation::QuadraticEquation()
{

}

QuadraticEquation::QuadraticEquation(double a,double b,double c){
    mA = a;
    mB = b;
    mC = c;

}

// Setter
void QuadraticEquation::setA(double a){
    mA = a;
}
void QuadraticEquation::setB(double b){
    mB = b;
}
void QuadraticEquation::setC(double c){
    mC = c;
}

//funk

double QuadraticEquation::Solve() {
    double dis = mB*mB - 4*mA*mC;
    if (dis >= 0){
        double solve1 = (-mB + sqrt(mB*mB - 4*mA*mC))/ 2*mA;
        double solve2 = (-mB - sqrt(mB*mB - 4*mA*mC))/ 2*mA;
        return solve1 and solve2;
    }
    else {
        double real = -mB/ (2*mA);
        double img  = sqrt(-dis)/(2*mA);
        return real and img;

    }
    return 0;
}
