#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date d1(2020, 2, 7);
    cout << d1.getDayOfWeek() << endl;

    return 0;
}
