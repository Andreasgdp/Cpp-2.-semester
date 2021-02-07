#include <cstdio>
#include <iostream>
#include "../Headers/Fibonacci.h"

using namespace std;

int main()
{
	int initialSize = 0;
	int timePeriod;
	int updataDay;
	bool calcAgain;

	std::cout << "What's the initial size of Crud?: ";
	std::cin >> initialSize;
	std::cout << "What's the time between each reproduction?: ";
	std::cin >> updataDay;
	Fibonacci f(initialSize, timePeriod, updataDay);

	do
	{
		std::cout << "Over how many days wil you make this calcylation from now?: ";
		std::cin >> timePeriod;
		f.setTimePeroid(timePeriod);
		f.calcCrud();
		std::cout << f.getCurrSize() << " pounds"<< std::endl;
		std::cout << "Want to calc for one more timePeried? (1 for yes and 0 for no): ";
		std::cin >> calcAgain;
	} while (calcAgain);

	return 0;
}