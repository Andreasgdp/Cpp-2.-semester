#include <iostream>
#include "DollarAmount.h"

using namespace std;

int main()
{
    DollarAmount d1(100);
    d1.addInterest(1, 1);

    cout << d1.toString() << endl;

    return 0;
}
