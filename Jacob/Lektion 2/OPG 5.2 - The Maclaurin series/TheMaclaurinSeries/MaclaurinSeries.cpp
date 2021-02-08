#include "MaclaurinSeries.h"
#include <math.h>
#include <iostream>

MaclaurinSeries::MaclaurinSeries() {

}

MaclaurinSeries::MaclaurinSeries(int x, int n) {
    mX = x;
    mN = n;
}

long long MaclaurinSeries::calcFactorial(int order) {
    unsigned long long factorial = 1;
    for(int i = 1; i <= order; ++i) {
            factorial *= i;
        }
    std::cout << factorial << std::endl;
    return factorial;
}

long long MaclaurinSeries::calcAproxOfEx() {
    long long ex = 0;
    for(int i = 1; i <= mN; ++i) {
        ex += (1 / calcFactorial(i) * pow(mX, i));
    }
    return ex;
}
