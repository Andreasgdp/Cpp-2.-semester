#include "ArrayInt100.h"
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

ArrayInt100::ArrayInt100() {

}

void ArrayInt100::fillArray(int minValue, int maxValue) {
    std::default_random_engine engine{static_cast<unsigned int>(time(0))};
        std::uniform_int_distribution<int> random{minValue, maxValue};
        for (size_t i = 0; i <= mArray.size(); i++) {
            mArray[i] = random(engine);
        }
}

int ArrayInt100::findMax() {
    int max = mArray[0];
    for (size_t i = 0; i <= mArray.size(); i++)
        if (mArray[i] > max)
            max = mArray[i];
    return max;
}

void ArrayInt100::printArray() {
    for (size_t i = 0; i <= mArray.size(); i++) {
        cout << i << ": " << mArray[i] << endl;
    }
}

int ArrayInt100::countOccurrances(int x) {
    int count = 0;
    for (size_t i = 0; i <= mArray.size(); i++) {
        if (mArray[i] == x) {
            count += 1;
        }
    }
    return count;
}

void ArrayInt100::swapElements() {
    for (size_t i = 0, j = mArray.size(); i <= mArray.size() / 2; i++, j--) {
        int temp = mArray[i];
        mArray[i] = mArray[j];
        mArray[j] = temp;
    }
}
