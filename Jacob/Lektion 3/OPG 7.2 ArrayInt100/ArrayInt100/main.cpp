#include <iostream>
#include "ArrayInt100.h"

using namespace std;

int main()
{
    ArrayInt100 array;

    array.fillArray(0, 100);

    array.printArray();

    cout << "Max: " << array.findMax() << endl;

    int Occurrances = 2;
    cout << "Count " << Occurrances << ": " << array.countOccurrances(Occurrances) << endl;

    array.swapElements();
    array.printArray();

    return 0;
}
