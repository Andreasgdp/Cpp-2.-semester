#ifndef ARRAY100_H
#define ARRAY100_H
#include <array>


class Array100
{
public:
    Array100();
    void Fill(int min, int max);
    int FindMax();
    void Print();
    int Count(int x);
    void Swap();
private:
    std::array<int, 100> mArray{};
};

#endif // ARRAY100_H
