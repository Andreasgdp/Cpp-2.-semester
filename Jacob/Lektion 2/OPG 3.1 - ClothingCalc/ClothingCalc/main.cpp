#include <iostream>
#include <string>
#include "ClothingCalc.h"

int main()
{
    bool newPerson = true;
    while (newPerson) {
        double inHeight = 0;
        std::cout << "Enter height: ";
        std::cin >> inHeight;

        double inWeight = 0;
        std::cout << "Enter weight: ";
        std::cin >> inWeight;

        unsigned int inAge = 0;
        std::cout << "Enter age: ";
        std::cin >> inAge;

        ClothingCalc c1(inHeight, inWeight, inAge);

        unsigned int sizeToCalc;
        std::cout << "\nEnter size to calculate (1. Hat, 2. Jacket, 3. Waist): ";
        std::cin >> sizeToCalc;
        switch (sizeToCalc) {
        case 1:
            std::cout << "\nHat size: " << c1.calcHat() << std::endl;
            break;
        case 2:
            std::cout << "\nJacket size: " << c1.calcJacket() << std::endl;
            break;
        case 3:
            std::cout << "\nWaist size: " << c1.calcWaist() << std::endl;
            break;
        }

        std::string inNewPerson;
        std::cout << "\nEnter new person?(y/n): ";
        std::cin >> inNewPerson;
        if (inNewPerson.compare("y") == 0) {
            newPerson = true;
        } else {
            newPerson = false;
            }
    }

    return 0;
}
