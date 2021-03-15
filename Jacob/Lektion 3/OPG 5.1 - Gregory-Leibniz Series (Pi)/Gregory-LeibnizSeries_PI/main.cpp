#include <iostream>
#include "Pi.h"

using namespace std;

int main()
{
    Pi p(100000);
    cout << p.calcPi() << endl;

    return 0;
}
