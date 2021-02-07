#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    int contin = 0;

    int winCount = 0;

    srand(time(NULL));

    int userPickedDoor;
    std::string keepDoor;
    std::cout << "Keep door?(y/n): ";
    std::cin >> keepDoor;

    while (contin < 1000) {
        int carDoor = std::rand() % 3 + 1;

        int userPickedDoor = std::rand() % 3 + 1;

        int pickedDoor = std::rand() % 3 + 1;
        while (pickedDoor == userPickedDoor || pickedDoor == carDoor) {
            pickedDoor = std::rand() % 3 + 1;
        }

        std::cout << "Behind door " << pickedDoor << " was no car." << std::endl;

        if (keepDoor.compare("y") != 0) {
            for (int i = 1; i < 4; i++) {
                if (i != userPickedDoor && i != pickedDoor) {
                    userPickedDoor = i;
                    break;
                }
            }
        }

        std::cout << "U have chosen door number: " << userPickedDoor << std::endl;

        if (userPickedDoor == carDoor) {
            std::cout << "CONGRATULATIONS! U won the car." << std::endl;
            std::cout << "The car was behind door: " << carDoor << std::endl;
            winCount += 1;
        } else {
            std::cout << "There was no car behind door: " << userPickedDoor << std::endl;
            std::cout << "The car was behind door: " << carDoor << std::endl;
        }

        contin += 1;
    }

    double winProcentage = static_cast<double>(winCount) / 1000 * 100;

    std::cout << "WinCount: " << winCount << std::endl;
    std::cout << "Win procentage: " << winProcentage << std::endl;

    return 0;
}
