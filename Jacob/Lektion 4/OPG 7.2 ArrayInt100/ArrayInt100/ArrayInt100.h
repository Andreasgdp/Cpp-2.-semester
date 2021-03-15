#ifndef ARRAYINT100_H
#define ARRAYINT100_H
#include <array>

class ArrayInt100
{
public:
    ArrayInt100();

    void fillArray(int minValue, int maxValue);
    int findMax();
    void printArray();
    int countOccurrances(int x);
    void swapElements();

private:
    std::array<int, 9> mArray{};
};

#endif // ARRAYINT100_H
