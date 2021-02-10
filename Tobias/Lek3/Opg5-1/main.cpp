#include <iostream>
#include "Pi.h"

using namespace std;

int main()
{
    Pi pi(10000);
    cout << "Pi er " << pi.calcPi() << endl;
    return 0;
}
