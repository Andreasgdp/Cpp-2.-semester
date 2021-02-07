#include <iostream>
#include "../Headers/QuadraticEquation.h"

using namespace std;

int main()
{
    double a;
    double b;
    double c;
    bool runAgain = true;

    do
    {
        std::cout << "Vælg din a-værdi: ";
        std::cin >> a;
        std::cout << "Vælg din b-værdi: ";
        std::cin >> b;
        std::cout << "Vælg din c-værdi: ";
        std::cin >> c;

        QuadraticEquation q1(a, b, c);

        auto [x1, x2, dIsNegative] = q1.solve();
        if (dIsNegative)
        {
            auto [Reel, Imag, dIsNegative] = q1.solve();
            std::cout << "Resulat: " << Reel << " ± I" << Imag << std::endl;
        }
        else
        {
            std::cout << "Resulat: " << x1 << " og " << x2 << std::endl;
        }

        std::cout << "Vil du gerne køre igen? (1 for ja og 0 for nej): ";
        std::cin >> runAgain;

    } while (runAgain);

    return 0;
}
