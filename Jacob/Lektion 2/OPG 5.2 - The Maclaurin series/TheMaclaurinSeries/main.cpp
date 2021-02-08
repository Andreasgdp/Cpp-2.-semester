#include <iostream>
#include "MaclaurinSeries.h"

using namespace std;

int main()
{

    MaclaurinSeries m(2, 10);

    cout << m.calcAproxOfEx() << endl;

    return 0;
}
