#include <iostream>
#include "Fibonacci.h"

using namespace std;

int main()
{
    bool newCalc = true;
    while (newCalc) {
        int inInitialSize;
        std::cout << "Enter initial size: ";
        std::cin >> inInitialSize;

        int inDays;
        std::cout << "Enter number of days to grow: ";
        std::cin >> inDays;

        Fibonacci f(inInitialSize, inDays);

        std::cout << "After " << inDays << " days, your green crud population will have grown to be " << f.solve() << " pounds." << std::endl;

        std::string inNewCalc;
        std::cout << "\nEnter new person?(y/n): ";
        std::cin >> inNewCalc;
        if (inNewCalc.compare("y") == 0) {
            newCalc = true;
        } else {
            newCalc = false;
            }
    }
    return 0;
}
