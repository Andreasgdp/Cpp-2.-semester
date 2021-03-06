#include "../Headers/Loan.h"
#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
	Loan l(100000, 10, 4, 0.03);

	std::cout << "Lånets løbetid: 10 år" << std::endl;
	std::cout << "Lånebeløb 100000 kr" << std::endl;
	std::cout << "Årlige renter: 3%" << std::endl;
	std::cout << "Betalinger per år: 4 betalinger" << std::endl;

	l.outputPeriodicalPayments(std::cout);

	return 0;
}
