#include "Maclaurin.h"
#include <iostream>

using namespace std;

int main()
{
    Maclaurin m(2, 1000);

    cout << m.calcAproxOfEx();
    return 0;
}
