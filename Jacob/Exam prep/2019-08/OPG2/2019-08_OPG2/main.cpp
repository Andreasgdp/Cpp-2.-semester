#include <iostream>
#include "TowerHanoi.h"

using namespace std;

int main()
{
    std::cout << "Tower of Hanoi height 3" << std::endl;
    TowerHanoi th1(3);
    th1.move();
    std::cout << "Tower of Hanoi height 4" << std::endl;
    TowerHanoi th2(15);
    th2.move();
}
