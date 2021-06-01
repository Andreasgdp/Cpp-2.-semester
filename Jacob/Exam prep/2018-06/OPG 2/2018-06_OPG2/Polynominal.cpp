#include "Polynominal.h"
#include <iostream>

Polynominal::Polynominal()
{

}

std::vector<std::pair<double, int> > Polynominal::readPolynomial(std::string& p) {

    std::vector<std::pair<double, int> > vecPoly;
    std::pair<double, int> pair;
    for (int i = 0; i < 3; i++) {
        std::string delimX = "x";
        std::string koeff = p.substr(0, p.find(delimX));

        std::string delimPow = "^";
        std::string power = p.substr(p.find(delimPow) + 1, p.find("+") || p.find("-"));

        pair = std::make_pair(std::stod(koeff), std::stoi(power));
        vecPoly.push_back(pair);

        p.erase(0, koeff.size() + delimX.length() + power.size() + delimPow.length());
    }
    return vecPoly;
}

