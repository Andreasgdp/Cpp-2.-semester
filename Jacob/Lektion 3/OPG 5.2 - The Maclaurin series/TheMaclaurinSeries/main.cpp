#include <iostream>
#include "MaclaurinSeries.h"
#include <string>

using namespace std;

int main()
{
    bool newCalc = true;
    while (newCalc) {
        int inX = 0;
        std::cout << "Enter x: ";
        std::cin >> inX;

        int inN = 0;
        std::cout << "Enter n: ";
        std::cin >> inN;

        MaclaurinSeries m(inX, inN);

        cout << "Result: " << m.calcAproxOfEx() << endl;

        std::string inNewCalc;
        std::cout << "\nEnter new calculation?(y/n): ";
        std::cin >> inNewCalc;
        if (inNewCalc.compare("y") == 0) {
            newCalc = true;
        } else {
            newCalc = false;
        }
    }
    return 0;
}
