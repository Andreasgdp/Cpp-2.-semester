#include <iostream>
#include <cstdio>

#include "ClothingCalc.h"

int main()
{
    ClothingCalc Calc(183, 70, 21);
    std::cout<<"Hat str:" << Calc.calcHat() << std::endl;
    std::cout<<"Jacket str:" << Calc.calcJacket() << std::endl;
    std::cout<<"Waist str:" << Calc.calcWaist() << std::endl;

    bool newPerson = true;
    do{
        ClothingCalc cloth;
        double height;
        double weight;
        unsigned int age;

        std::cin >> height;
        cloth.setHeight(height);

        std::cin >> weight;
        cloth.setWeight(weight);

        std::cin >> age;
        cloth.setAge(age);

        std::cout <<"Choose your size: \n1 - Hat\n2 - Jacket\n3 - Waist" << std::endl;
        unsigned int choose;
        std::cin >> choose;
        switch(choose)
        {
        case 1:
            std::cout << "\nHat size: " << cloth.calcHat() << std::endl;
        case 2:
            std::cout << "Jacket size: " << cloth.calcJacket() << std::endl;
        case 3:
            std::cout << "Waist size: " << cloth.calcWaist() << std::endl;
        default:
            std::cout << "Wrong input " << std::endl;
        }

    }while (newPerson);

    return 0;
}



