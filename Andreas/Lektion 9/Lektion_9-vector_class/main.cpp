#include <iostream>
#include "Vector.h"


using namespace std;

int main()
{
    Vector a(3);
    {
        Vector b(2);
        b[0] = 1;
        b[1] = 2;

        cin >> b;
        cout << b;

        Vector a;
        a = b;
    }
    Vector c(3);
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    std::cout << a << std::endl;
    std::cout << " Finish " << std::endl;
}
