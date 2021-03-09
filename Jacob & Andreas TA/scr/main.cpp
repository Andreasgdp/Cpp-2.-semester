#include "../Headers/Loan.h"
#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char const *argv[])
{
	double debt, years, paymentsPerYear, interestRate;
	std::cout << "Enter debt, years, peymentsPerYear, intrestRate: ";
	std::cin >> debt >> years >> paymentsPerYear >> interestRate;

	Loan l(debt, years, paymentsPerYear, interestRate);

	l.printLoanInformation(std::cout);
	std::cout << "Total Interest: " << l.totalInterest() << std::endl;
	std::cout << "Total Payment: " << l.totalPayment() << std::endl;
	std::cout << "Total Interest Tax Deducted: " << l.totalInterestTaxDeducted(30.6) << std::endl;

	l.outputPeriodicalPayments(std::cout);

	std::cout << std::endl
			  << "-----------------------------------------------------------------------" << std::endl;

	// Other lånetyper - Fastforrentet obligationslån, løbetid: 30 år, Obligations-renteprocent: 0.5% (https://netbank.totalkredit.dk/netbank/showStockExchangeInternal.do)
	Loan lObligationslan(100000, 30, 4, 0.5);
	std::cout << std::endl
			  << "Obligationslaan: " << std::endl;
	lObligationslan.printLoanInformation(std::cout);
	std::cout << "Total Interest: " << lObligationslan.totalInterest() << std::endl;
	std::cout << "Total Payment: " << lObligationslan.totalPayment() << std::endl;
	std::cout << "Total Interest Tax Deducted: " << lObligationslan.totalInterestTaxDeducted(30.6) << std::endl;

	return 0;
}
