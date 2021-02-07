#include <iostream>
#include "QuadraticEquation.h"

using namespace std;

int main()
{
    //QuadraticEquation q1(2, -10, 8);
    QuadraticEquation q1(1, 1, 1);

    auto [x1, x2, dIsNegative] = q1.solve();
    if (dIsNegative) {
        auto [Reel, Imag, dIsNegative] = q1.solve();
        std::cout << "Resulat: " << Reel << "+i" << Imag << " og " << Reel << "-i" << Imag << std::endl;
    } else {
        std::cout << "Resulat: " << x1 << " og " << x2 << std::endl;
    }

    return 0;
}
