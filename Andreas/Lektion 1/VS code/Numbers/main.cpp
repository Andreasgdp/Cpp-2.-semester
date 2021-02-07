#include <iostream>
#include "ClothingCalc.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ClothingCalc clothCalculator(175, 80, 20);
    cout << "\nHat size: " << clothCalculator.calcHat() << endl;
    cout << "Jacket size: " << clothCalculator.calcJacket() << endl;
    cout << "Waist size: " << clothCalculator.calcWaist() << endl;

    bool newPerson = true;
    do
    {
        ClothingCalc cloth;
        double height;
        double weight;
        unsigned int age;

        cout << "Choose your height: ";
        cin >> height;
        cloth.setHeight(height);
        cout << "Choose your weight: ";
        cin >> weight;
        cloth.setWeight(weight);
        cout << "Choose your age: ";
        cin >> age;
        cloth.setAge(age);

        cout << "Choose your size:\n1 - Hat\n2 - Jacket\n3 - Waist" << endl;
        unsigned int choose;
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "\nHat size: " << cloth.calcHat() << endl;
            break;
        case 2:
            cout << "Jacket size: " << cloth.calcJacket() << endl;
            break;
        case 3:
            cout << "Waist size: " << cloth.calcWaist() << endl;
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }

        cout << "Wanna' calc another person? (Y/n):" << endl;
        string uInput;
        cin >> uInput;
        newPerson = (uInput.compare("y") == 0 || uInput.compare("Y") == 0) ? true : false;

    } while (newPerson);

    return 0;
}