#include <iostream>

#include "Date.h"

using namespace std;

int main()
{
    Date d1(2007, 9, 5);
    cout << d1.getDayOfWeek() << endl;

    return 0;
}
