/*
 * Assume that unsigned integers are stored in four bytes and that the starting address
 * of the built-in array is at location 1002500 in memory.
*/

#include <iostream>

using namespace std;

int main()
{
    // a)
    unsigned int values[5] = {2,4,6,8,10};

    // b)
    unsigned int *vPtr;

    // c)
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
      cout << values[i] << " ";
    }
    cout << endl;

    // d)
    cout << "&values[0]: " << &values[0] << endl;
    cout << "vPtr: " << vPtr << endl;
    vPtr = values;
    vPtr = &values[0];
    cout << "vPtr: " << vPtr << endl;

    // e)
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        cout << *(vPtr + i) << " ";
    }
    cout << endl;

    // f)
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        cout << *(values + i) << " ";
    }
    cout << endl;

    // g)
    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        cout << vPtr[i] << " ";
    }
    cout << endl;

    // h)
    cout << *(vPtr + 4) << endl;
    cout << *(values + 4) << endl;
    cout << vPtr[4] << endl;

    // i)
    /*
     * If i assume that the starting address is 1002500 in memory, then vPtr + 3 is 1002500 + 3 * 4 = 1002512.
     * The value stored at vPtr + 3 is 8.
     */
    vPtr = &values[0];
    cout << "vPtr: " << vPtr << endl;
    cout << "vPtr + 3: " << vPtr + 3 << endl;
    cout << "Value at vPtr + 3: " << *(vPtr + 3) << endl;

    // j)
    /*
     * Assuming that vPtr points to values[4] the address of vPtr -= 4 is 1002500 + 3 * 4 - 4 = 1002512.
     * The value stored at vPtr -= 4 when values[4] is 8.
     */
    vPtr = &values[4];
    cout << "vPtr: " << vPtr << endl;
    cout << "vPtr -= 4: " << vPtr - 4 << endl;
    cout << "Value at vPtr -= 4: " << *(vPtr -= 4) << endl;

    int numbers[3][3] = { {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9} };
    cout << *(*(numbers + 1) + 2);


    return 0;
}
