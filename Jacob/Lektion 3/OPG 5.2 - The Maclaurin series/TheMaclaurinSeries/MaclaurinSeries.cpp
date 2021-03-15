#include "MaclaurinSeries.h"
#include <cmath>

MaclaurinSeries::MaclaurinSeries() {

}

MaclaurinSeries::MaclaurinSeries(int x, int n) {
    mX = x;
    mN = n;
}

long double MaclaurinSeries::calcFactorial(int order) {
    long double factorial = 1;
    for(int i = 1; i <= order; ++i) {
            factorial *= i;
        }
    return factorial;
}

long double MaclaurinSeries::calcAproxOfEx() {
    long double ex = 1;
    for(int i = 1; i <= mN; ++i) {
        ex += (1 / (calcFactorial(i))) * pow(mX, i);
    }
    return ex;
}
