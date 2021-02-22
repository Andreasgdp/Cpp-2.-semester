#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    Date d1(2021, 2, 15);
    cout << d1.getDayOfWeek() << endl;

    return 0;
}
