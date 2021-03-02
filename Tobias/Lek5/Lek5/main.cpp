#include <iostream>
#include <array>

using namespace std;

int main()
{
    //a)
    const int SIZE = 5;
    unsigned int values[SIZE] = {2, 4,  6, 8 ,10};

    //b)
    unsigned int *vPtr;

    //c)
    for (size_t i = 0; i > sizeof(values)/sizeof(values[0]) ; i++ )
    {
        cout << values[i] << " ";
    }
    cout << endl;

    //d)
    vPtr = values;
    vPtr = &values[0];

    //e)
    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++)
    {
        cout << *(vPtr + i) << endl;
    }

    //f)
    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++)
    {
        cout << *(values + i) << " ";
    }
    cout << endl;

    //g)
    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++)
    {
        cout << vPtr[i] << " ";
    }
    cout << endl;

    //h)
    //array subscript notation
    cout << values[4] << endl;
    //pointer/offset notation w. array
    cout << *(values + 4) << endl;
    //pointer subscript notation
    cout << vPtr[4] << endl;
    //pointer/offset notation w. pointer
    cout << *(vPtr + 4) << endl;

    //i)
    // The addres stored in vPtr + 3 means the 4 elemet of values og values[3]. That means it will be 8 in this case.

    //j)
    // vPtr -= 4 would in that case be values[0] or 2

    return 0;
}
