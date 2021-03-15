#include "Fibonacci.h"
#include <iostream>

Fibonacci::Fibonacci() {

}

Fibonacci::Fibonacci(int initialSize, int days) {
    mInitialSize = initialSize;
    mDays = days;
}

int Fibonacci::solve() const {
    int day = 0;
    int F1 = 0;
    int F2 = mInitialSize;
    const int timePeriod = 5;
    while (day < mDays / timePeriod) {
        int temp = F1 + F2;
        F1 = F2;
        F2 = temp;
        day += 1;
    }
    return F2;
}
