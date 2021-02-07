#include <iostream>
#include "QuadraticEquation.h"

using namespace std;

int main()
{
    bool newCalc = true;
    while (newCalc) {
        double inA;
        std::cout << "Enter a: ";
        std::cin >> inA;

        double inB;
        std::cout << "Enter b: ";
        std::cin >> inB;

        unsigned int inC;
        std::cout << "Enter c: ";
        std::cin >> inC;

        QuadraticEquation q1(inA, inB, inC);

        auto [x1, x2, dIsNegative] = q1.solve();
        if (dIsNegative) {
            auto [Reel, Imag, dIsNegative] = q1.solve();
            std::cout << "Resulat: " << Reel << "+i" << Imag << " og " << Reel << "-i" << Imag << std::endl;
        } else {
            std::cout << "Resulat: " << x1 << " og " << x2 << std::endl;
        }

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
