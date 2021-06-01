#include <iostream>
#include "Polynominal.h"

int main()
{
    Polynominal p;
    std::string pstr = "22x^3+2x^2-1x^0";
    std::vector<std::pair<double, int> > poly = p.readPolynomial(pstr);
    for (unsigned int i = 0; i < poly.size(); ++i) {
        if (i > 0) {
            if (poly[i].first > 0)
                std::cout << "+";
        }
        std::cout << poly[i].first << "x^" << poly[i].second;
    }
    std::cout << std::endl;
}
